/*
1148. Article Views I

Link: https://leetcode.com/problems/article-views-i/
*/

-- PostgreSQL query statement
SELECT DISTINCT author_id AS id FROM Views WHERE author_id=viewer_id ORDER BY id;
