#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_TERMS 94

typedef unsigned long long LLU; // From limits.h, ULLONG_MAX: 18446744073709551615.
// 12200160415121876738 is the largest fibonacci number before ULLONG_MAX at term #93.

int isprime(LLU n) {
     if (n <= 1) { // 1 or less
         return 0; 
     }

     if (n % 2 == 0 && n > 2) { // Multiple of 2
         return 0;
     }

     for(int i = 3; i < sqrt(n); i += 2) { // The rest
         if (n % i == 0) {
             return 0;
         }
     }

     return 1;
}

int main() {
    int i = 0;
    LLU curr = 0, computed[MAX_TERMS];
    computed[0] = 0;
    computed[1] = 1;

    for (int i = 0; i < MAX_TERMS; i++) {
        if (isprime(curr)) {
            printf("p: %llu n: %llu\n", i + 1, curr);
        }
        
        curr = computed[i] + computed[i + 1];
        computed[i + 2] = curr;
    }

   return 0;
}
