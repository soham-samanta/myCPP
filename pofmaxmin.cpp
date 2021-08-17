#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxNo= INT_MIN;
    
    for(int i=0;i<n;i++){
        maxNo=max(maxNo,a[i]);
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int minNo= INT_MAX;
    for(int i=0;i<m;i++){
        minNo=min(minNo,b[i]);
    }
    int ans=maxNo*minNo;
    cout<<ans<<endl;
    
    return 0;
}