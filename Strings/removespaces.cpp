//Remove spaces from a given string
#include<iostream>
using namespace std;

void removeSpaces(char str[]){
	int count = 0;
	for(int i=0; str[i]; i++){
		if(str[i] != ' '){
			str[count++] = str[i];
		}
	}
	str[count] = '\0';
}

int main(){
	char str[] = "g  eeks   for ge  eeks  ";
    removeSpaces(str);
    cout << str;
    return 0;
}
