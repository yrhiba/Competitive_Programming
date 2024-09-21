#include "header.hpp"

/* Binominial
Usage:
	1- precumpute:
		InverseofNumber(mod);
		InverseofFactorial(mod);
		factorial(mod);
*/
// array to store inverse of 1 to N
ll factorialNumInverse[MAX_N + 1];
// array to precompute inverse of 1! to N!
ll naturalNumInverse[MAX_N + 1];
// array to store factorial of first N numbers
ll fact[MAX_N + 1];
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (int i = 2; i <= MAX_N; i++)
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
	factorialNumInverse[0] = factorialNumInverse[1] = 1;
	// precompute inverse of natural numbers
	for (int i = 2; i <= MAX_N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
// Function to calculate factorial of 1 to N
void factorial(ll p)
{
	fact[0] = 1;
	// precompute factorials
	for (int i = 1; i <= MAX_N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
	// n C r = n!*inverse(r!)*inverse((n-r)!)
	ll ans = ((fact[N] * factorialNumInverse[R])
				% p * factorialNumInverse[N - R])
				% p;
	return ans;
}
