#include "bigint.h"

void bint_init(BINT* n, int sgn, char* digs) {
    size_t slen = strlen(digs);
    n->_s = sgn;
    n->_l = slen;
    n->_d = (DIGITTYPE*)malloc(BINT_CONTAINER_MAX * sizeof(DIGITTYPE));
    if (n->_d != NULL) {
        memset(n->_d, 0, BINT_CONTAINER_MAX * sizeof(DIGITTYPE));
        for (int i = 0; i < slen; i++) {
            n->_d[slen - i - 1] = (int)(digs[i] - '0');
        }
    }
}

void bint_cpy(BINT* dst, BINT* src) {
    memcpy(dst->_d, src->_d, MAX(dst->_l, src->_l) * sizeof(DIGITTYPE));
    dst->_s = src->_s;
    dst->_l = src->_l;
}

// OLD
//int bint_len(BINT* n) {
//    int i = BINT_CONTAINER_MAX;
//    while (!n->_d[--i]);
//    return i + 1;
//}

void bint_add(BINT* a, BINT* b, BINT* dst) {
    // Non-negative
    dst->_s = 1;
    DIGITTYPE carr = 0;
    size_t mlen = MAX(a->_l, b->_l);
    for (int i = 0; i < mlen; i++) { // Iterate up to length of longest number
        DIGITTYPE s = a->_d[i] + b->_d[i] + carr;
        if (s >= 10) {
            carr = 1;
            s %= 10;
        } else {
            carr = 0;
        }
        dst->_d[i] = s;
    }
    // Last carry
    if (carr != 0) { dst->_l++; }
    dst->_d[mlen] = carr;
}

void bint_put(BINT* n, int nl) {
    if (n->_s == -1) { printf("-"); }
    for (int i = n->_l - 1; i >= 0; i--) {
        // Format according to DIGITTYPE
        printf("%d", n->_d[i]);
    }
    if (nl) { printf("\n"); }
}

void bint_putraw(BINT* n, int nl) {
    for (int i = 0; i < BINT_CONTAINER_MAX; i++) {
        printf("%d ", n->_d[i]);
    }
    if (nl) { printf("\n"); }
}


void bint_writefile(FILE* fptr, int t, BINT* n, int nl) {
    if (fptr != 0) {
        fprintf(fptr, "Term #%-d: ", t);
        int flg = 0;
        if (n->_s == -1) { fprintf(fptr, "-"); }
        for (int i = BINT_CONTAINER_MAX - 1; i >= 0; i--) {
            int d = n->_d[i];
            if (!flg && d != 0) { flg = 1; }
            if (flg) { fprintf(fptr, "%d", d); }
        }
        if (!flg) { fprintf(fptr, "0"); } // The entire digit array is 0
        if (nl) { fprintf(fptr, "\n"); }
    }
}