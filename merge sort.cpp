#include<iostream>
#include<vector>
using namespace std;
void merge(int* arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(int* arr, int l ,int h){
	if(l>=h){
	return	;
	}
	int mid=(h+l)/2;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,h);
	merge(arr,l,mid,h);
}
int main(){
	int n,i;
	cin>>n;
    int* arr = new int[n];
	for( i=0;i<n;i++){
		cin>>arr[i];
	}
	mergesort(arr,0,n-1);
		for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

