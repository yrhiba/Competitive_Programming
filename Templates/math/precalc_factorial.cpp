#include "header.hpp"

#define FACT_MAXN 100001

ll fact[FACT_MAXN];

void precalc_factorial(void)
{
	/*factorial precalculation*/
	fact[0] = 1;
	fact[1] = 1;
	for (ll i = 2; i <= FACT_MAXN; i++)
	{
		fact[i] = (i * fact[i-1]);
		fact[i] %= mod;
	}
}
