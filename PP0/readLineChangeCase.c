#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
John Abreu
1/29/2018
*/

//there are two ways to syntactically pass an array of char

//int getLine(char line[]);
//void printLine(char line[], int size);
//void changeCap(char line[], int size);

int getLine(char *line);
void printLine(char *line, int size);
void changeCap(char *line, int size);
void reverseString(char *line, int size);


int main(){
	char m[80];
	char *a;
	char *output;
	int i,size=0;

	printf("Enter a string that you'd like to reverse:\nInput: ");
	if (scanf("Input: %s", m) <= 80){
		size = getLine(m);
		a = m;
		reverseString(a, size);
	}
	else {
		exit(EXIT_FAILURE);
	}

	return 0;

}

//int getLine(char line[])
int getLine(char *line){
	char *a,b;
	int i,size=0;
	a = line;
	b = getchar();
	while( b != '\n' && size < 80)
    {
		*(a+size) = b;  //remember at this point size = 0
		//printf("a = %c\n",*(a+size));
		size++;
		b = getchar();
    }
	return size;
}

//void printLine(char line[], int size)
void printLine(char *line, int size){
	char *a;
	int i;
	a = line;
	for (i=0;i<size;i++)
		//printf("a = %c\n",*(a+i));
		printf("%c",*(a+i)); //no end of line
	printf("\n");
}

//void changeCap(char line[], int size)
void changeCap(char *line, int size){
	int i;
	char *a;
	a = line;
	//*a = *a - 97 + 65; //change the first letter of first word to be Upper Case
	*a = toupper(*a);
	i = 1;
	while (i < size){
		if (*(a+i) == ' '){ //skip this and capitalze next letter which is first letter of next word
			i++;
			//*(a+i) = *(a+i) - 97 + 65;
			*(a+i) = toupper(*(a+i));
		}
		i++;
	}
}

void reverseString(char *line, int size){
	char output[size-1];
	char test;

	for (int i=0; i < size; i++){
		test = line[size-i-1];
		output[size-i-1] = line[i];
		output[i] = test;
	}

	printf("Reversed: %s\n", output);
}

/*
csci2271@csci2271-VirtualBox:~/demos/tuesday1_23_18$ ./readLineChangeCase
Input : 	this is a test
Output: 	This Is A Test
All done
csci2271@csci2271-VirtualBox:~/demos/tuesday1_23_18$
*/
