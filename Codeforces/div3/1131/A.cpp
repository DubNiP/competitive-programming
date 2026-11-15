#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back

#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

const int inf=2e18;
const int MOD=1e9+7;

void solve() {
    int i,n,m; cin>>n>>m;
    vector<int>freq(26);
    for(i=0;i<n;i++){
        char aux; cin>>aux;
        freq[aux-'a']++;
    }
    for(i=0;i<m;i++){
        char aux; cin>>aux;
        freq[aux-'a']--;
    }
    for(i=0;i<26;i++){
       
        if(i==8||i==18||i==23) continue;
        if(freq[i]!=0){
            cout<<"NO\n";
            return;
        }
    }
    if(freq[8]==1&&freq[18]==1&&freq[23]==1) cout<<"YES\n";
    else cout<<"NO\n";
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
