#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>


void solve(){
    ll n,m,cont,resp=0;
    bool ok,active;
    cin>>n>>m;
    vll v(n);
    for(auto &w : v) cin>>w;
    

    ll l=0,r=2e9;
    while(l<=r){
        ll mid=(l+r)/2;
        cont=m;
        ok=false,active=false;
        for(int i=n-1;i>=0;i--){
            if(v[i]<mid) active=true;
            if(max(v[i],v[i]+cont)<mid){
                ok=true;
                break;
            }
            if(active) cont--;
        }
        if(!ok){ 
            resp=max(resp,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q=1;
    //cin>>q;
    while(q--) solve();
}

