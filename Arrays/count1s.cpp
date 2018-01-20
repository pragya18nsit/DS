#include<iostream>
using namespace std;

int countOnes(int arr[], int low, int high){
	if(high >= low){
		int mid= (low+ high)/2;
		if(arr[mid] ==1 && (arr[mid+1] ==0 || mid == high))
			return mid+1;
		
		if (arr[mid] == 1)
      		return countOnes(arr, (mid + 1), high);
      	else
      		return countOnes(arr,low, mid -1);

	}
}
int main()
{
	int arr[] = {1,1,1,1,1,1,0,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout << "Count of 1s in given array is " << countOnes(arr,0,len);
}
