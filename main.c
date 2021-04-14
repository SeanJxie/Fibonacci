#include "bigint.h"
#include <time.h>

/*
Implementing the BINT struct by computing the Fibonacci sequence.
*/


#define NTERMS 10000

int main() {
    int nTerms;

    printf("How many terms would you like to compute? (starting from term #1): ");
    scanf_s("%d", &nTerms);

    printf("\Computing Fibonacci sequence up to term %d.\n", nTerms);

    FILE* fptr;
    fopen_s(&fptr, "Fibonacci_sequence.txt", "w");

    BINT prev;
    BINT curr;
    BINT sum;
    double runtime = 0.0;

    clock_t begin = clock();

    bint_init(&sum, 0, "0");
    bint_init(&prev, 0, "0");
    bint_init(&curr, 1, "1");

    bint_writefile(fptr, 1, &curr, 1);

    for (int t = 0; t < nTerms - 1; t++) {
        bint_add(&prev, &curr, &sum);
        bint_cpy(&prev, &curr);
        bint_cpy(&curr, &sum);
        printf("\r%.2f%% complete.", (t + 1.0f) / (nTerms - 1.0f) * 100.0f);
        bint_writefile(fptr, t + 2, &curr, 1);
    }

    clock_t end = clock();
    runtime += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\nComputation took %f seconds.", runtime);

    if (fptr != NULL) { fclose(fptr); }

    return 0;
}