#include<iostream>
#include<stdlib.h>
using namespace std;

void countWords(char *str, int &count){
	count = 1;
	while(*str){
		if(*str == '\n' || *str == '\t' || *str == ' '){
			count++;
		}
		str++;
	}
}
int main(){
	char str[] = "i am the\nbest";
	int countOfWords = 0;
	countWords(str,countOfWords);
	cout << "the number of words in the given string is " << countOfWords;
}
