#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>desi(n),ap(m);
    for(auto &w : desi) cin>>w;
    for(auto &w : ap) cin>>w;

    sort(desi.begin(),desi.end());
    sort(ap.begin(),ap.end());

    ll pdesi=0,pap=0,resp=0;
    while(pdesi!=(ll)desi.size()&&pap!=(ll)ap.size()){
        if(abs(desi[pdesi]-ap[pap])<=k){
            resp++;
            pdesi++;
            pap++;
        }
        else{
            if(desi[pdesi]>=ap[pap]) pap++;
            else pdesi++;
        }
    }
    cout<<resp;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
