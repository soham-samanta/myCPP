#include<bits/stdc++.h>
using namespace std;

void rotateArray(int a[],int n,int k){
    int newArray[n];
    for(int i=0;i<n;i++){
        int newIndex=(i+n-k)%n;
        newArray[newIndex]=a[i];
    }
        for(int i =0;i<n;i++){
            cout<<newArray[i]<<" ";
        }
    
}

int main() {
    int t,n,k;
    cin>>t;
    while(t--){
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	rotateArray(a,n,k);
	cout<<endl;
  }
	return 0;
}