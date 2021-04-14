#ifndef BIGINT_H
#define BIGINT_H

#include <stdio.h>
#include <memory.h>
#include <string.h>

#define BINT_CONTAINER_MAX 300000
#define MAX(A, B) (A > B) ? A : B

typedef int DIGITTYPE;
typedef struct {
    int        _s; // Sign
    DIGITTYPE* _d; // Digits
    size_t     _l; // Length
} BINT;

void bint_init(BINT* n, int sgn, char* digs);
void bint_cpy(BINT* dst, BINT* src);
//int  bint_len(BINT* n); OLD
void bint_add(BINT* a, BINT* b, BINT* dst);
//void bint_mul(BINT* a, BINT* b, BINT* dst);
void bint_put(BINT* n, int nl);
void bint_putraw(BINT* n, int nl);
void bint_writefile(FILE* fptr, int t, BINT* n, int nl);

#endif