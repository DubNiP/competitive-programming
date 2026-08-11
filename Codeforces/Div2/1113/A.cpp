#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


void solve() {
    string s; cin>>s;
    bool um=false,zr=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'&&!zr){
            s.erase(i,1);
            zr=true;
            i--;
        }
        else if(s[i]=='1'&&!um){
            s.erase(i,1);
            um=true;
            i--;
        }
    }
    cout<<s<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
