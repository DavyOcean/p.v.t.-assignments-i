#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool isPrime(int num)
{
     if (num <= 1) return false;
     if (num <= 2) return true;
     for(int i = 2; i < num; i++)
     {
         if (num % i == 0)
             return false;
     }
     return true;
}

void getPrimes(int limit, bool *primes) {
    int i,j;

    for (i=2;i<=limit;i++)
        assert(i >= 0 && i <= 100); // Before accessing primes[i], add an assertion to check that i is within the bounds of the allocated array.
        primes[i]=true;

    for (i=2; i*i<=limit;i++)
        assert(i >= 0 && i <= 100);
        if (primes[i])
            for (j = i; i * j <= limit; j++)  // Change < to <=
                assert(i*j >= 0 && i*j <= 100);
                primes[i*j]=false;

    // Remove free(primes); from getPrimes function.
}

int main(){
  bool *primes = malloc(sizeof(bool) * 101);  // Allocating 101 elements
  getPrimes(100, primes);

  int z = 1;
  int i;
  for (i = 2; i <= 100; i++)  // Start loop from 2
    assert(i >= 0 && i <= 100);
    if (primes[i])
        printf("%dth prime = %d\n",z++,i);

  free(primes); // Add free(primes); at the end of the main function.
}