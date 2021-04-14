#include "bigint.h"
#include <time.h>

/*
Implementing the BINT struct
*/


#define NTERMS 10000

int main() {
    /*BINT n1, n2;
    bint_init(&n1, 1, "123125125");
    bint_init(&n2, 1, "321124");

    bint_cpy(&n1, &n2);

    bint_putraw(&n1, 1);*/


    // --- Fibonacci sequence ---
    // About 14.2017 minutes to process the one millionth term.

    printf("Generating Fibonacci sequence up to term %d.\n", NTERMS);

    clock_t begin = clock();

    FILE* fptr;
    fopen_s(&fptr, "Fibonacci_sequence.txt", "w");

    BINT prev;
    BINT curr;
    BINT sum;
    double runtime = 0.0;

    bint_init(&sum, 0, "0");

    // Initial t0 = 0 t1 = 1
    bint_init(&prev, 0, "0");
    bint_init(&curr, 1, "1");

    bint_writefile(fptr, 1, &curr, 1);

    for (int t = 0; t < NTERMS - 1; t++) {
        bint_add(&prev, &curr, &sum);
        bint_cpy(&prev, &curr);
        bint_cpy(&curr, &sum);
        printf("\r%.2f%% complete.", (t + 1.0f) / (NTERMS - 1.0f) * 100.0f);
        bint_writefile(fptr, t + 2, &curr, 1);
    }

    clock_t end = clock();

    runtime += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nCalculation took %f seconds.", runtime);
    if (fptr != NULL) { fclose(fptr); }

    // --- With standard types ---
    // unsigned long long int prev = 0;
    // unsigned long long int curr = 1;
    // unsigned long long int sum = 0;

    // for (int _ = 0; _ < NTERMS; _++) {
    //     printf("%d\n", curr);
    //     sum = prev + curr;
    //     prev = curr;
    //     curr = sum;
    // }

    // printf("%d\n", curr);

    return 0;
}