#include <bits/stdc++.h>
#define ll long long
#define md 1000000007
using namespace std;
ll lm=10000001;
int main(){
ll a[lm];
ll T,k,i,j;

for(i=0;i<lm;i++) a[i]=1;

a[1]=0;
for(i=2;i*i<lm;i++){
	if(a[i]==1){
		for(j=i*2;j<lm;j+=i)
			a[j]=0;
	}
}
for(i=3;i<lm;i++) if(a[i]==1 && 2*i<lm) a[2*i]=-1;
for(i=3;i<lm;i++)
	a[i]+=a[i-1];

cin>>T;
for(k=0;k<T;k++){
	ll n;
	cin>>n;
	cout<<a[n]<<"\n";
}
 return 0;
}