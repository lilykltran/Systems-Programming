/* Copyright © 2018 Bart Massey */
//Lily Tran

#include <stdlib.h>
#include "bits.h"

/*This function writes characters to the stream FILE. It iterates through each index of the existing matrix
and writes with black char where there is a 1 and writes with  white char where there is a 0. The way this function checks
whether or not there is a 1 or 0 is line 18, where it right shifts the bits array by 5, which is the same thing as
dividing by 32, which is the size of each index. This first accesses the correct index the bit should be in. Then, it
uses & to check if that bit is turned on or not. If it's turned on, that means there exists a bit, and it should be written with
black char. If it's not turned on (has a 0 value), then it should be written with white char.*/

void
bitstoascii(FILE *f, char black_char, char white_char, struct bits *bitmap) {
    size_t posn = 0;
	//iterating through every  row
    for (int r = 0; r < bitmap->nrows; r++) {
	//iterating through every index of the row (columns)
        for (int c = 0; c < bitmap->ncols; c++) { 
            int bit = (bitmap->bits[posn >> 5] >> (posn & 0x1f)) & 1; //access the position of the argument bits. 
            if (bit == 0) //if there is no bit that exists, it should be 0, so do not draw
                fputc(white_char, f); //write white_char to FILE
            else
                fputc(black_char, f); //if there is a bit that exists, it should be 1, so draw with black_char to FILE.
            posn++; //check the next position in the matrix.
        }
        fputc('\n', f);
    }
}

