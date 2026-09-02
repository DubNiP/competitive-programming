#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(){
    int n; cin>>n;
    vector<pair<int,int>>v(n);
    for(auto &w : v) cin>>w.first;
    for(auto &w : v) cin>>w.second;
    for(int i=0;i<n;i++){
        if(v[i].first<v[i].second){
            cout<<"-1";
            return;
        }
    }
    sort(v.begin(),v.end(), [](auto a, auto b){return a.first - a.second < b.first - b.second;});
    int resp=0;
    for(int i=n-1;i>0;i--){
        resp+=v[i].first;
    }
    resp+=v[0].second;
    cout<<resp;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

