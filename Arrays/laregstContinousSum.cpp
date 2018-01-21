#include<iostream>
#include<climits>
using namespace std;

int largestSumSubarray(int arr[], int n){
	int max_so_far = INT_MIN;
	int max_ending_here = 0;
	
	for(int i=0; i < n ; i++){
		max_ending_here += arr[i];
		
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
		
		if (max_ending_here < 0)
            max_ending_here = 0;
	}
	return max_so_far;		
}

int main(){
	int arr[]= {1,2,-1,-3,4,5,6,7,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int largestSum = largestSumSubarray(arr, n);
	cout << "largest continous sum subarray is " << largestSum << endl;
	return 0;
}
