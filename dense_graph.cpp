#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> pp1;
vector<ll> pp2;
bool isinrange(ll a,ll b){
    for(ll i=0;i<pp1.size();i++){
        if(pp1[i]<=b && pp2[i]>=a){
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,x,y;
		cin>>n>>m>>x>>y;
		ll a[m];
		ll b[m];
		ll c[m];
		ll d[m];
		for(ll i=0;i<m;i++){
		    cin>>a[i]>>b[i]>>c[i]>>d[i];
		}
		if(x==y){
		    cout<<"0"<<endl;
		    continue;
		}
		ll di[m];
		ll ans=-1;
		ll z=0;
		vector<ll> q1;
		vector<ll> q2;
		for(ll i=0;i<m;i++){
		    di[i]=0;
		}
		q1.push_back(x);
		q2.push_back(x);
		while((ans==-1) && (q1.size()!=0)){
		    pp1.clear();
		    pp2.clear();
		    pp1=q1;
		    pp2=q2;
		    vector<ll> w1;
		    vector<ll> w2;
		    for(ll i=0;i<(m);i++){
		        if((di[i]==0) && isinrange(a[i],b[i])){
		            w1.push_back(c[i]);
		            w2.push_back(d[i]);
		            if(c[i]<=y && d[i]>=y){
		                ans=z+1;
		            }
		            di[i]=1;
		        }
		    }
		    q1=w1;
		    q2=w2;
		    z++;
		}
		cout<<ans<<endl;
	}
	return 0;
}