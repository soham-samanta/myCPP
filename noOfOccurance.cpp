#include<bits/stdc++.h>
using namespace std;

int countOccurrences(int arr[], int n, int x) 
{ 
	int res = 0; 
	for (int i=0; i<n; i++) 
		if (x == arr[i]) 
		res++; 
	return res; 
} 

int main() 
{   int t;
    cin>>t;
    while(t--){
    int n,x;
    cin>>n>>x;
	int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	cout << countOccurrences(arr, n, x)<<endl; 
    }
	return 0; 
} 


/* DIVIDE & CONQUER */
// int count(int arr[], int x, int n) {	 
// int *low = lower_bound(arr, arr+n, x); 

// if (low == (arr + n) || *low != x)
// //	cout<<"Key not found! "<<endl; 
// return 0;

// int *high = upper_bound(low, arr+n, x);	 
//     return high - low; 
// } 

// int main(){ 
//     int t;
//     cin>>t;
//     while(t--){
//         int n,x;
//         cin>>n>>x;
//         int arr[n];
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }
//         sort(arr,arr+n);
//     // int l = sizeof(arr)/sizeof(arr[0]); 
//     cout<<count(arr, x, n); 
//     }
// return 0; 
// } 
