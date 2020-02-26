/*Lily Tran. CS201. HW3. Barton Massey
This program implements an IEEE foating point parser, where the first argument is the number of fraction 
bits (n), the second argument is the nubmer of exponent bits(k), and the third argument is the hex representation
of the number the user wants to parse.*/ 

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



/*This function makes sure the first and second arguments are valid.*/
void
error(char *argv[])
{
	int first_arg = atoi(argv[1]); //convert string to integer
	int second_arg = atoi(argv[2]);

	if (first_arg < 2 || first_arg > 10)
	{
		fprintf(stderr, "Illegal number of fraction bits (%s). %s", argv[1], "Should be between 2 and 10.\n");
		exit(1); //exit program with failure
	}

	if (second_arg < 3 || second_arg > 5)
	{
		fprintf(stderr, "Illegal number of exponent bits (%s). %s", argv[2], "Should be between 3 and 5.\n");
		exit(1); //exit program with failure
	}
}



int
main(int argc, char *argv[])
{
	error(argv); //function call to error
	int value, frac, exp, hex = 0;

	//reading in command line args as the approrpiate data types
	sscanf(argv[1], "%d", &frac);
	sscanf(argv[2], "%d", &exp);
	sscanf(argv[3], "%x", &hex);

	//create a mask with the same amount of bits turne don as the frac value
	int mask = 0;
	for (int i = 0; i < frac; ++i)
	{
		mask = mask ^ (1 << i); 
		
	}

	//create a mask with the same amount of bits turned on as the exp value
	int mask2 = 0;
	for (int i = 0; i < exp; ++i)
	{
		mask2 = mask2 ^ (1 << i);
		
	}

	mask2 = mask2 << frac;  //to move those bits over to where the exponent bits should be.
	value = frac + exp; //total bits

	if ((mask2 & hex) == mask2) //isolating exp bits, then checking if exp bits are set. If set it would equal mask2. Special case.
	{
		if ((mask & hex) == 0) //if fraction bits of the hex num is all 0's
		{
			if (((hex >> value) & 1) == 0) //if the signed bit is 0, means it's positive infinity.
			{
				fprintf(stderr, "+inf\n");
				exit(1);
			}

			else if (((hex >> value) & 1) == 1) //if the signed bit is 1, means it's negative infinity.
			{
				fprintf(stderr, "-inf\n");
				exit(1);
			}
		}
		
		else if ((mask % hex) != 0) //if exp is all 1s and frac is not all 1s, it's not a number
		{
			fprintf(stderr, "NaN\n");
			exit(1);
		}
	}

	float M = 0;
	int bias = (pow(2,exp-1)) - 1; //bias is 2 to the exponent minus 1, minus 1 
	int E = 0;
	int Ebin = 0;

	//To find the value of the fraction bits
	for (int i = 0; i < frac; ++i)
	{
		int ret = hex & 1; //ret will be 1 if the first frac bit is turned on
		M += ret * (1/(pow(2, (frac - i))));
		hex >> 1;
	}

	//To find the value of the exponent bits
	hex >>= frac; //move the hex over to the appropriate spot
	unsigned int mask3 = pow(2, frac) -1;
	Ebin += hex & mask3; //The value of the exponent 

	hex <<= frac; //move back hex so it's in exponent section

	if ((mask2 & hex) == 0)  //denormalized case
	{
		E = 1 - bias;
		float print = M * pow(2, E);
		if (((hex >> value) & 1) == 0) //if the signed bit is 0, print as positive
			printf("%f\n", print);
		else
			printf("%f\n", -print); //if signed bit is 1, print as negative
	}
	
	else //normalized case
	{
		M += 1;
		E = Ebin - bias;
		float print2 = M * pow(2, E);

		if (((hex >> value) & 1) == 0) //if the signed bit is 0, print as positive
			printf("%f\n", print2);
		else
			printf("%f\n", -print2); //if the signed bit is 0, print as negative
	}

	return 0;
}
