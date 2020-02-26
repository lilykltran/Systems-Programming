/*Lily tran CS201 A2 Bart Massey
Program to compare two hex digits and print the bits in common in hex, signed, and unsigned
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



/*Function prototype to convert hex strings to longs*/
int
convert(char *arg[]);



int
main(int argc, char *argv[])
{
	//Error message if the argument is not 2
	if (argc < 3)
	{
		fprintf(stderr, "Error: please provide two hexadecimal numbers as arguments to the program.\n");
		return 1;
	}

	int compared = convert(argv); //catch the return value in compared

	printf("Bits ");

	for (int i = 0; i < 32; i++)
	{
		if ((compared >> i) & 1) //if it's in common, print
		{
			printf("%d,", i);
		}
	}

	printf(" in common. ");

	printf("Hexadecimal: %x, Signed: %d, Unsigned: %u\n", compared, compared, compared); //prints as hex, signed, unsigned

	return 0;
}



/*Function to convert the hex arguments into strings*/
int
convert(char *arg[])
{
	int num1 = strtol(arg[1], NULL, 16); //change string to a long
	int num2 = strtol(arg[2], NULL, 16);

	return num1 & num2;
}
