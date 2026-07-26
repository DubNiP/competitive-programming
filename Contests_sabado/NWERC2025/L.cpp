#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,i,j;
    string s;
    map<string,vector<int>>m;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<10;j++){
            cin>>s;
            if(m[s].empty()) m[s].assign(11,0);
            (m[s])[0]++;
            (m[s])[j+1]++;
        }
    }
    pair<string,vector<int>>par={"a",vector<int>(11,0)};
    bool tie=false;
    for(auto w : m){
        if(w.second > par.second){
            par.second=w.second;
            par.first = w.first;
            tie=false;
        }
        else if(w.second == par.second) tie=true;
    }
    if(tie) cout<<"tie\n";
    else cout<<par.first<<"\n";
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
             
                    while(q--) solve();
                        return 0;
}

