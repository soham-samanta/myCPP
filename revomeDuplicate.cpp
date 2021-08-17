#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int flg=0;
        while(n%2==0){
            n/=2;
            flg=1;
        }
        int q=sqrt(n);
        if(q*q==n && flg)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}