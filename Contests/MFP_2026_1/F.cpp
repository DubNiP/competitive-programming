#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &w : v) cin>>w;
    double probat,probtot=1;
    for(int i=0;i<n;i++){
        if(k>v[i]) continue;
        probat=((double)(k-1)/(double)v[i]);
        probtot*=probat;
    }
    probtot = 1-probtot;
    cout<<fixed<<setprecision(10)<<probtot<<"\n";
}


signed main(){
    solve();
}

