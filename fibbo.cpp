#include<iostream>
using namespace std;

void fib(int n){
    int t1=0,t2=1,r;
    for(int i=1;i<=n;i++){
        cout<<t1<<endl;
        r=t1+t2;
        t1=t2;
        t2=r;
    }
    return ;
}

int main(){
    int n;
    cout<<"Enter no of terms ";
    cin>>n;
    fib(n);
    return 0;
}