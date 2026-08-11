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
    int n; cin>>n;
    string s; cin>>s;
    int i,resp=1;
    char ant=s[0];
    for(i=1;i<n;i++){
        if(s[i]!=ant) resp++;
        ant=s[i];
    }

    for(i=1;i<n-1;i++){
        if(s[i-1]==s[i+1]&&s[i-1]!=s[i]){
            cout<<resp-2<<"\n";
            return;
        }
    }
    for(i=1;i<n-1;i++){
        if(s[i-1]!=s[i+1]&&s[i]!=s[i-1]&&s[i]!=s[i+1]){
            cout<<resp-1<<"\n";
            return;
        }
    }
    cout<<resp<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
