#include "header.hpp"

ll powermod(ll x, ll p, ll m = mod)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2, m) % m;
	if (p%2)
		return ((((res * res) % m) * (x % m)) % m);
	return ((res * res) % m);
}
 
ll inverse(ll x, ll m = mod)
{
	return (powermod(x, m-2, m));
}
