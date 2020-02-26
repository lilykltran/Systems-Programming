/*Lily Tran. 989558404. CS201 Prog 1. 01/20/2018
This program prints a list of words for the user to type, loops an error message if the word is typed wrong, and calculates the time for the user to complete the list of words.*/

#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*This function prints each word to the user*/
void
print_words()
{
	char* word_list[] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}; //array of strings to choose from
	char user_str[10]; //store user's input
	int num_words = 9; //counter. should stop after 9 words.
	int c = 0;

	printf("Type the following words: \n");

	while (num_words > 0)
	{
		int word = rand() % num_words; //stores a random index of the word_list array
		do
		{
			printf("Word #%d is %s: ", 10 - num_words, word_list[word]); //selects word chosen by random index

			scanf("%9s", user_str); //stores user's input
			while((c = getchar()) != '\n' && c != EOF); //throw away if new line or EOF

		} while (strncmp(word_list[word], user_str, (strlen(word_list[word]) + 1)) != 0 && printf("Incorrect. Try again.\n"));

		word_list[word] = word_list[num_words - 1]; //move on to a different index
		--num_words; //number of words to choose from decreases
	}
}

//Where program begins executing. Contains function calls and declaration of objects. 
int
main()
{
	struct timeval seed, start, finish, taken; //create objects of elapsed time
	gettimeofday(&seed, NULL);

	srand(seed.tv_usec); //gets random permutation of words. gets member of struct timeval that gets time in microseconds

	gettimeofday(&start, NULL); //gets time of struct timeval
	
	print_words(); //function call to print the word list.

	gettimeofday(&finish, NULL); //get the time that it took the user to finish, place it in finish
	timersub(&finish, &start, &taken); //subtracts start time from finish time, places it in taken that is of timeval

	printf("Correct! Your time is: %d sec, %d usec\n", (int) taken.tv_sec, (int) taken.tv_usec); //prints time that was stored in taken
	return 1;
}
