#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


bool isPrimeFast(int num)
{
     if (num <= 1) return false;
     if (num == 2) return true; // Add this line to handle the case for num = 2
     if (num % 2 == 0 || num % 3 == 0 && num > 3) return false;
     int third = 1;
     for(int i = 5; i*i <= num; i+= 2)
     {
        if (num % i == 0)
            return false;

        // Skip each number that has a 3 factor (e.g. 9, 15, 21, 27 etc)
        // Since we already checked if the numer is divisble by 3 
        if(third == 2){
            i += 2;
            third = 0; 
        } else {
            third++;
        }
     }
     return true;
}

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

int main(){

    int x = nondet_int(); // Non-deterministic input
    __CPROVER_assume(x >= 0); // Assuming x is non-negative

    bool result1 = isPrime(x);
    bool result2 = isPrimeFast(x);

    assert(result1 == result2); // Assertion to check if both functions give the same result
    
}