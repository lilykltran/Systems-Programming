/*Lily Tran CS201 A2 Bart Massey
Program to turn on bits that are requested
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



/*prototype for function that prints bits that are turned on*/
void
set(short result);



int
main(int argc, char *argv[])
{
	short result = 0;
	for (int i = 1; i < argc; i++)
	{
		int value = atoi(argv[i]);
		if (!isdigit(argv[i][0]) || value > 15 || value < 0) //make sure input is a num, between 1 and 15
		{
			fprintf(stderr, "Arguments must be numbers between 0..15");
			return 1;
		}
		result |= 1 << value; //turn on value bit
	}

	set(result); //function call
}



/*Function to print the bits that were turned on*/
void
set(short result)
{
	for (int i = 15; i >= 0; i--) 
	{
		if ((result >> i) & 1) //if bit turned on, print it as 1
		{
			printf("1");
		}
		else
		{
			printf("0"); //if that bit not turned on, print as 0
		}
	}
	printf("\n");
}

