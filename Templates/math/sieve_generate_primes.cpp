#include "header.hpp"

const int MAX_NP = 5e5;
vector<int> primes;
bool isprime[MAX_NP];
void sieve()
{
	isprime[0] = isprime[1] = true;
	for (int i = 2; i*i < MAX_NP; i++)
	{
		if (isprime[i]) continue;
		for (int j = i*i; j < MAX_NP; j+=i) isprime[j] = true;
	}
	for (int i = 2; i < MAX_NP; i++)
		if (!isprime[i]) primes.push_back(i);
}
