#include<bits/stdc++.h>
using namespace std;

int odd(int a[],int n){
    // for(int i=0;i<n;i++){
    //     int c=0;
    //     for(int j=0;j<n;j++){
    //         if(a[i]==a[j])
    //         c++;
    //     }
    //     if(c%2!=0)
    //     return a[i];
    // }
    // return -1;

    int r=0;
    for (int i = 0; i < n; i++)
    r=r^a[i];
    return r;

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<odd(a,n);

    return 0;
}