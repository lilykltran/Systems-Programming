/* Copyright © 2018 Bart Massey */
//Lily Tran

#include <stdio.h>
#include "bits.h"
#include <unistd.h>
#include <stdlib.h>

int
main(int argc, char **argv) {

	FILE *ifile = stdin;
	FILE *ofile = stdout;
	int c;
	
	while ((c = getopt(argc, argv, "i:o:")) != -1) //set option arguments i and o
	{
		switch(c)
		{
			case 'i':
				ifile = fopen(optarg, "r"); //open file with flag i as command arg, flag r for read
				if (ifile == NULL) //make sure file reading in something
				{
					fprintf(stderr, "-i needs to be a valid arg\n");
					return 1;
				}
				break;

			case 'o':
				ofile = fopen(optarg, "w"); //open file with flag o as command arg, flag w for write
				if (ofile == NULL) //make sure file reading in something
				{
					fprintf(stderr, "-o needs to be a valid arg\n");
					return 1;
				}
				break;

			default:
				abort();
		}
	}

	struct bits *bitmap = asciitobits(ifile, '+'); //read in every character of +, to be converted to a 1 or 0.
	
	if (bitmap == 0) {
		perror("asciitobits");
		return 1;
	}

	bitstoascii(ofile, 'o', ' ', bitmap); //write out to a new file with a o, where there is a 1. 
	freebits(bitmap, bitmap->bits); //call destructor

    	return 0;
}


