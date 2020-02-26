# Systems-Programming
programming assignments for Systems Programming at Portland State University

1. HW1-Prints a list of words for the user to type, loops an error message if the word is typed wrong, and calculates the time for the user to complete the list of words
2. HW2-Compares two hex digits and print the bits in common in hex, signed, and unsigned
3. HW3-Implements a IEEE foating point parser, where the first argument is the number of fraction 
bits (n), the second argument is the nubmer of exponent bits(k), and the third argument is the hex representation
of the number the user wants to parse
4. HW4-
	asciitobits() first reads in one character at a time until end of the file. If we are not at the end of the file yet, it stores
	the number of characters for until new line, which is the error check for the end of a row. Therefore, it is storing
	the number of characters in every row, which is the same as number of columns for each row. The number of 
	columns for each row must be equal to each other, otherwise there is an issue and we must free memory. There is an error check
	for if the information being read in exceeds the capacity, and if it does, it reallocates memory to be twice as
	large as before so that there is room for the bits being read. Asciitobits() writes a 1 where the position of the bit 
	we are at is by scaling the amount of bits being read in. It's doing this by right shifting 5, which is the same as
	dividing the current bit by 32. For example, if the current bit is 4, integer division 4/32 is 0, which means 
	we are at position 0, and a 1 will be written in that position, and returns this result. When it is called in convbits.c,
	it is reading in a '+' to be converted to either a 1 or a 0 in asciitobits().

	bitstoascii() is using the result returned in asciitobits() when it is called in convbits.c (the position of the bit we are at), 	 to write either a white char or a black char.This function writes characters to the stream FILE. It iterates through
	each index of the existing matrix and writes with black char where there is a 1 and writes with  white char where
	there is a 0. The way this function checks whether or not there is a 1 or 0 is line 18, where it right shifts the
	bits array by 5, which is the same thing as dividing by 32, which is the size of each index. This first accesses
	the correct index the bit should be in. Then, it uses & to check if that bit is turned on or not. If it's turned on, that
	means there exists a bit, and it should be written with black char. If it's not turned on (has a 0 value), then it should
	be written with white char. When it is called in convbits.c, it is writing the character 'o' where there is a 1 and 
	no character where there is a 0. 
	
	Rather than doubling the capacity when we run out of room for bits_read, simply adding the capacity by 32 bits each time
	will return a bitmap that has at most 32 extra bits.
	Each index in the bits array is 32 bits. That means if we fill up the second index of bits array (64 bits), we just need to
	move to the third index (96 bits), which is only an additional 32 bits. Doubling the capacity would give us 128 bits,
	which is the fourth index (not what we need). 

	The new function freebits.c I wrote divided the size of the struct by the bits, which is the size of our
	current struct and the number of indexes we need to free. It frees the indexes of the stuct that are filled,
	and the loop exits once everything has been deleted. Finally, the struct itself is deleted. The object file
	freebits.o must be put in the makefile, and called before return in convbits, after everything has been read and written.

	The getopt() function returns the next option character specified on the command line. In convbits.c, the option
	takes option arguments i and o. My program writes and reads to a file stream using fopen() until the command line args
	are done beingparsed, which is when optarg() returns -1, which is why my while loop conditional is != -1. 
	If the option arguments i and o exist, the program will read and write from an external file. 
	It sets a flag 'r' for reading in the character '+' from an external file, and sets a flag 'w' for writing out 
	the character 'o' where there is a '+' to an external file. If the option arguments i and o are NULL, read and write
	the same way but from standard input and output.  
