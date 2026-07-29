#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
using ll = long long;
using vi = vector<int>;

using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int n,i,s=-1,m=-1,soma=0; cin>>n;
    vi v(n+2);
    for(i=0;i<n+2;i++){
        cin>>v[i];
        s=max(s,v[i]);
        soma+=v[i];
    }
    soma-=s;
    m=soma-((n-1)*s);
    cout<<s<<" "<<m<<"\n";
    bool mf=false,sf=false;
    vi ord;
    for(i=0;i<n+2;i++){
        if(!mf&&v[i]==m) mf=true;
        else if(!sf&&v[i]==s) sf=true;
        else ord.push_back(s-v[i]);
    }
    sort(ord.begin(),ord.end());
    for(auto w : ord) cout<<w<<" ";

    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
