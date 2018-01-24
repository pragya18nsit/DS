//Search in a row wise and column wise sorted matrix
#include<iostream>
using namespace std;

bool searchElementInMatrix(int num, int x, int mat[4][4]){
	int i = 0, j = x-1;
	while(i<x && j>= 0){
		
		if ( mat[i][j] == num )
	    {
	        printf("n Found at %d, %d", i, j);
	        return true;
	    }
	 	if(mat[i][j] > num){
		 	j--;
		}
		else{
			i++;
		}
	}
	
	printf("n Element not found");
   	return false;  // if ( i==n || j== -1 )
}

int main(){
	int mat[4][4]= { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
	int num = 29;
    bool isPresent = searchElementInMatrix(num, 4, mat);
    cout << "\nthe given element is " << (isPresent? "" : "not") << "present";
}
