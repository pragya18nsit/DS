#include<iostream>
using namespace std;

void numberOfNegatives(int mat[3][4], int &count){
	for(int i=0; i<3 ;i++){
		for(int j=0; j<4 ;j++){
			if(mat[i][j] < 0)
				count++;
			else
                break;
		}
	}	
}

int main(){
	int mat[3][4] = {{-3, -2, -1,  1},
             		{-2,  2,  3,  4},
             		{4,   5,  7,  8}};
    int negativesCount = 0;
	numberOfNegatives(mat, negativesCount);
	cout << "the number of negatives is "  << negativesCount;
}
