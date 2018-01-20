#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
	

    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n){
	for(int i=n/2;i>=0;i--)
		heapify(arr, n ,i);	
	// One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
	 // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int len){
	for(int i=0; i< len; i++){
		printf("%d ", arr[i]);
	}
}
int main(){
	int arr[]= {12,34,56,11,32,15};
	int len = sizeof(arr)/sizeof(arr[0]);
	HeapSort(arr, len);
	cout<<"sorted array is " << endl;
	printArray(arr,len);
}