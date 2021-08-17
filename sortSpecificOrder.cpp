#include <bits/stdc++.h>
using namespace std;

void twoWaySort(int arr[], int n){
    for (int i = 0; i < n; i++)
//        if (arr[i] & 1) // Check for odd
        if(arr[i]%2!=0)
            arr[i] *= -1;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        if (arr[i] & 1)
            arr[i] *= -1;
}

int main(){
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	twoWaySort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}