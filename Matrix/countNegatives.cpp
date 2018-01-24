#include<iostream>
using namespace std;

int numberOfNegatives(int mat[3][4], int count){
	for(i=0; i<3 ;i++){
		for(j=0; j<4 ;i++){
			if(mat[i][j] < 0)
				count++;
		}
	}	
}

int main(){
	int mat[3][4]] = {{-3, -2, -1,  1},
             		{-2,  2,  3,  4},
             		{4,   5,  7,  8}};
    int negativesCount = 0;
	int count = numberOfNegatives(mat, negativesCount);
	cout << "the number of negatives is "  << count;
}
