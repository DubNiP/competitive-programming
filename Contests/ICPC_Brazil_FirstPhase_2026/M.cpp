#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k,cont,resp=0;
    bool active,ok;
    cin>>n>>k;
    vector<ll>v(n);
    for(auto &w : v) cin>>w;

    ll l=0,r=2e9,mid;
    while(l<=r){
        mid=(l+r)/2;
        cont=k;
        active = false;
        ok=false;
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
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}


