#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);

    for(int i=n-1;i>=n-k;i--){
        cout<<a[i]<<" "<<endl;
    }

    return 0;
}

    
                                                                    /* descending order sort

                                                                    sort(a,a+n,greater<int>());
                                                                    for(int i=0;i<n;i++)

                                                                    */