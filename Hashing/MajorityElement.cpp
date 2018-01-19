#include <bits/stdc++.h>
using namespace std;

int majorityElement(int arr[], int n){
	unordered_map<int, int> map;
	
	for(int i=0; i <n ;i ++)
		map[arr[i]]++;
		
	for(auto pair: map)
		if(pair.second > n/2)
			return pair.first;
	
	return -1;
}

int main(){
	int arr[] = {1,2,3,4,5,31,1,1,1,1,1,1,1};
	
	int res = majorityElement(arr,n);
	if(res == -1)
		cout << "Majority element is " << res;
	else 
		count << "Not found ";
	return 0;
}
