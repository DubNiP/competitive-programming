#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){

    int i,j,k,n,sz; cin>>n>>sz;
    map<string,int>mapa;

    for(i=0;i<n;i++){
        string s; cin>>s;
        for(j=0;j<sz;j++){
            if(s[j]=='*'){
                for(k=0;k<26;k++){
                    s[j]=((int)'a')+k;
                    mapa[s]++;
                }
            }
        }
    }
    
    int maxi=0;
    for(auto [a,b] : mapa) maxi=max(maxi,b);

    for(auto [a,b] : mapa){
        if(b==maxi){
            cout<<a<<" "<<b;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
