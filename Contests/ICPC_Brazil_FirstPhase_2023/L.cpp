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

vector<string> part;

void solve(){
    string s; cin>>s;
    int n=s.size(),k; cin>>k;
    part=vector<string>(k);
    for(int i=0;i<n;i++){
        part[i%k].pb(s[i]);
    }
    for(int i=0;i<k;i++) sort(part[i].begin(),part[i].end());
    for(int i=0;i<n;i++){
        cout<<part[i%k][i/k];
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
