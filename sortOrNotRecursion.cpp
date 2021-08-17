#include<bits/stdc++.h>
using namespace std;

int dec(int n){
    if(n==0){
        cout<<"1"<<endl;
        return 1;
    }
     cout<<n<<endl;
    int prev=dec(n-1);
   
    return prev;
}

int main(){
    int n;
    cin>>n;
    dec(n);
    return 0;
}