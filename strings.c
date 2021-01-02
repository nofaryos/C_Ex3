#include "strings.h"
#include <stdio.h>
#include <string.h>

int substring( char * str1, char * str2);
int similar (char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);

/*
Main function
*/

int main(){
	//The first line in the file.
	char inputLine[WORD + OPTION + 1];
	//The word we should look for in the file.
	char inputWord[WORD];
	//a or b option
	char option;
	//Reading the first line of the text.
	fgets(inputLine,LINE,stdin);
	int j = 0;
	
	//
	while(inputLine[j] != ' '){
		//Reading the word we are looking for in the text.
		inputWord[j] = inputLine [j];
		j++;
	}
	j++;
	//The option to be sent to the appropriate function.
	option = inputLine[j];
	if(option == 'a'){
		print_lines(inputWord);
	}
	if(option == 'b'){
		print_similar_words(inputWord);
	}
	return 0;
}

/*
This function checks whether two strings are equal.
*/

int isEqualStringN(char s1[], char s2[], int n) {
	for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}

/*
This function takes two pointers to strings and checks if str2 is contained in str1.
*/

int substring( char* str1, char* str2) {
  int len1 = strlen(str1), len2 = strlen(str2);
  //If the length of str2 is greater than the length of str1, str2 not contained in str1.
  if(len1 < len2){
	  return 0;
  }
  for (int i = 0; i <= len1-len2; i++) {
    if (isEqualStringN(str2, str1+i, len2)==1) {
      return 1;
    }
  }
  return 0;
}

/*
This function check if it is possible to get from string s to string t
by omitting n characters. 
*/

int similar(char* s, char* t, int n){
	  int len1 = strlen(s), len2 = strlen(t);	  
	  int index = 0;
	 
	 if(len2 == len1-n){
		  if(n == 0){
			return isEqualStringN(s ,t, len2);
		}
		 while(index < len2 && 0 <= n){
				if(*s == *t){
					index++;
					s++;
					t++;	
				}
				else
				{
					s++;
					n--;
				}
		 }
		 if(index == len2){
			 return 1;
		 }
	  }
	  return 0;
}

/*
This function prints all the lines of text in which the user-selected string appears
option a for the user
*/

void print_lines(char* str){
	//An array that will contain every line in the text
	char c[LINE];
	int counter = 0;
   //Reading the text, line by line
   while(fgets(c,LINE,stdin)){
	   	//Skip the first line - the line in which is written what the user's choices are
		if(counter == 0){
			counter++;
			continue;
		}
		//Checking if the word str contained in a line
        if (substring(c,str)){
            printf("%s",c);
        }	
	}
}

/*
This function prints all the words in the text 
that are similar to the string that the user selects to the point of omitting one char from the word
option b for the user.
*/

void print_similar_words(char * str){
	//An array that will contain every line in the text
	char line[LINE];
	//An array that will contain every word in the text
	char word[WORD];
	int inputLen = strlen(str);	
	int j = 0 , counter = 0 ;
	
	//Skip the first line - the line in which is written what the user's choices are
	while(fgets(line,LINE,stdin)){

		if(counter == 0){
			counter++;
			continue;
		}
	int len = strlen(line);
	//A loop that goes through all the lines in the text.
	for(int i = 0 ; i < len ; i++){
		 j = 0 ;	
		 //A loop that goes through all the words in the text
		while(line[i] != ' ' && line[i] != '\n' && line[i] != '\t' && line[i] != '\r'){
			word[j] = line[i];
			j++;
			i++;
		}
		word[j] = '\0';
		//If the length of the word in the text is equal to the length of
		//the word entered by the user we will check if the words are equals.
		if(j == inputLen){
			if(isEqualStringN(word,str,inputLen) == 1){
				printf("result: %s \n",word);
			}
		}
		else
		{	
			//Check if the word in the text is equal to the word selected by the user to the
			//point of omitting one char from the word in the text
			if(similar(word,str,1) == 1){
			printf("%s \n",word);
			}
		}
	}		
  }
}



	  

	


