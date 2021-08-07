#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
      int maxNo=INT_MIN;
      for(int i=0;i<n;i++)
          maxNo=max(maxNo,a[i]);
      cout<<maxNo<<endl;
    return 0;
}