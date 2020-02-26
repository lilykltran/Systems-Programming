/* Copyright © 2018 Bart Massey */
//Lily Tran

#include <stdio.h>
#include <stdint.h>

struct bits {
    int nrows, ncols;
    uint32_t *bits;
};

extern struct bits *
asciitobits(FILE *f, char black_char);

extern void
bitstoascii(FILE *f, char black_char, char white_char, struct bits *bitmap);

void freebits(struct bits *struct_free, uint32_t *bits); //function prototype to my function 
