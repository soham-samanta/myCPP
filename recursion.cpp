#include<bits/stdc++.h>
using namespace std;
//  int sum(int n){
//      if(n==0){
//          return 0;
//      }

//     //  int psum=sum(n-1);
//     //  return n+psum;
//     return n+sum(n-1);
//  }

//  int main(){
//      int n;
//      cin>>n;
//      cout<<sum(n)<<endl;
//      return 0;
//  }


    void dec(int n){
        if(n==1){
            cout<<"1"<<endl;
            return;
        }
        cout<<n<<endl;
        dec(n-1);
    }
    void inc(int n){
        if(n==0){
         //   cout<<"1"<<endl;
            return;
        }
        inc(n-1);
        cout<<n<<endl;
    }

    int main(){
    int n;
    cin>>n;
//    dec(n);
    inc(n);
    return 0;
}