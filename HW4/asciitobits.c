/* Copyright © 2018 Bart Massey */
//Lily Tran

#include <stdlib.h>
#include "bits.h"

struct bits *
asciitobits(FILE *f, char black_char) {
    struct bits *result = malloc(sizeof *result);
    if (result == 0)
        return 0;
    result->nrows = 0;
    result->ncols = 0;
    result->bits = malloc(sizeof *result->bits);
    if (result->bits == 0)
        return 0;
    size_t capacity = 32;
    size_t bits_read = 0;
    int ncols = 0;
    int ch;

	/*reading in one character at a time until EOF*/ 
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n') {
            if (result->nrows == 0) //hit first new line
                result->ncols = ncols;//storing number of characters before the new line
            if (result->ncols != ncols) { //number of columns have to be equal to each other
                free(result->bits);
                free(result);
                return 0;
            }
            result->nrows++; //in a new row
            ncols = 0; //start at the first column again
            continue;
        }
	/*if run out of room, make more space*/
        if (bits_read >= capacity) {
            capacity += 32; //3. Repair
            result->bits = realloc(result->bits, capacity);
            if (result->bits == 0)
                return 0;
        }
	/*Scaling amount of bits read so that we correct index of bits. If read in less than 32 bits, still in first index that
	was allocated. Using bits_read to get within the correct 32 bits of space. Setting a 0 or 1 where the position of our current
	bit.*/
        if (ch == black_char) {
            result->bits[bits_read >> 5] |= 1 << (bits_read & 0x1f);
        } else {
            result->bits[bits_read >> 5] &= ~(1 << (bits_read & 0x1f));
        }
        bits_read++;
        ncols++;
    }

	/* if we have read until the end of file and ncols is 0, there were characters that is not a new line.*/
    if (ncols > 0) {
        if (result->nrows == 0) //making sure same width
            result->ncols = ncols;
        if (ncols != result->ncols) {
            free(result->bits);
            free(result);
            return 0;
        }
        result->nrows++;
    }
    return result;
}

