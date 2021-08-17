#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int a,b;
    cout<<"Enter the number range: ";
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(isPrime(i)){
            cout<<"The prime num between "<<a<<" and "<<b<<" is "<<i<<endl;
        }
    }
    return 0;
}