#include <libc.h>
# define BUFFER_SIZE 1
// ############ //
// getnextline //
typedef struct s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}					t_list;
int					ft_strlc(char *s, int len0_or_chr1);
char				*ft_join(char *s1, char *s2);
char				*get_next_line(int fd);
t_list				*ft_lstnew(char *content, int fd);
char				*ft_get_content(t_list **list_o, int fd);
void				delete_node(t_list **list, int fd);
char	*ft_join(char *s1, char *s2)
{
	char	*rtn;
	char	*tmp;
	int		i;

	rtn = (char *)malloc(sizeof(char) * (ft_strlc(s1, 0) + ft_strlc(s2, 0)
				+ 1));
	if (!rtn)
		return (NULL);
	tmp = rtn;
	i = 0;
	while (s1[i])
		*tmp++ = s1[i++];
	i = 0;
	while (s2[i])
		*tmp++ = s2[i++];
	*tmp = '\0';
	free(s1);
	return (rtn);
}
int	ft_strlc(char *s, int len0_or_chr1)
{
	int	i;

	i = 0;
	while (s[i] && len0_or_chr1)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (!len0_or_chr1)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (-1);
}
t_list	*ft_lstnew(char *content, int fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->fd = fd;
	node->next = 0;
	return (node);
}
char	*ft_get_content(t_list **list_o, int fd)
{
	t_list	*new;
	t_list	*list;
	char	*rtn;

	list = *list_o;
	while (list)
	{
		if (list->fd == fd)
			return (list->content);
		list = list->next;
	}
	rtn = (char *)malloc(sizeof(char));
	if (!rtn)
		return (NULL);
	*rtn = '\0';
	new = ft_lstnew(rtn, fd);
	if (!new)
	{
		free(rtn);
		return (NULL);
	}
	new->next = *list_o;
	*list_o = new;
	return ((*list_o)->content);
}
void	delete_node(t_list **list, int fd)
{
	t_list	*tmp;
	t_list	*nex;
	t_list	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		nex = tmp->next;
		if (tmp->fd == fd)
		{
			free(tmp->content);
			free(tmp);
			if (prev)
				prev->next = nex;
			else
				*list = nex;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
char	*read_content(char *content, int fd, int *r)
{
	char	*c;

	c = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!c)
	{
		free(content);
		return (NULL);
	}
	*c = '\0';
	*r = read(fd, c, BUFFER_SIZE);
	if (*r == -1)
	{
		free(c);
		free(content);
		return (NULL);
	}
	c[*r] = '\0';
	if (*c)
		content = ft_join(content, c);
	free(c);
	return (content);
}
void	get_line_3(char *content, char *nw_content, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	j = 0;
	while (content[i])
		nw_content[j++] = content[i++];
	nw_content[j] = '\0';
}
char	*get_line_2(char **content, int index)
{
	char	*line;
	char	*nw_content;

	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	nw_content = (char *)malloc(sizeof(char) * (ft_strlc(*content, 0) - index));
	if (!nw_content)
	{
		free(line);
		return (NULL);
	}
	get_line_3(*content, nw_content, line);
	free(*content);
	*content = nw_content;
	if (content && *content == (void *)('\0'))
		return (free(content), *content = 0, line);
	return (line);
}
char	*get_line_1(char **content, int fd)
{
	char	*l;
	int		r;

	r = 1;
	l = (char *)malloc(sizeof(char));
	if (!l)
		return (NULL);
	*l = '\0';
	while (*content && ft_strlc(*content, 1) == -1 && r != 0)
		*content = read_content(*content, fd, &r);
	if (!*content)
	{
		free(l);
		return (NULL);
	}
	if (r == 0)
	{
		l = ft_join(l, *content);
		free(*content);
		*content = 0;
		if (*l == '\0')
			return (free(l), l = NULL);
		return (l);
	}
	return (free(l), l = get_line_2(content, ft_strlc(*content, 1)), l);
}
char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*tmp;
	char			*content;
	char			*line;

	if (fd < 0)
		return (NULL);
	content = ft_get_content(&list, fd);
	if (!content)
		return (NULL);
	line = get_line_1(&content, fd);
	tmp = list;
	while (tmp)
	{
		if (tmp->fd == fd)
			tmp->content = content;
		tmp = tmp->next;
	}
	if (!content)
		delete_node(&list, fd);
	return (line);
}
// ############ //


/* main function */
/* 
	- Example problem take two lines each line have a number
	output the sum result of the two numbers;

	input:
	10
	20

	output:
	10 + 20 = 30
*/

int main()
{
	char *A = get_next_line(STDIN_FILENO);
	char *B = get_next_line(STDIN_FILENO);

	int a = atoi(A), b = atoi(B);

	printf("%d + %d = %d\n", a, b, a + b);

	free(A), free(B);
	return (0);
}
