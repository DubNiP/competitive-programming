#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


const int INF = 2e18;
const int MOD = 1e9+7;

void solve(){
    string s; cin>>s;
    int mini=INF,maxi=0;
    int u=0,z=0;
    for(int i=0;i<sz(s);i++) s[i]=='1' ? u++ : z++;

    for(int i=0;i<sz(s);i++){
        if(i%2+s[i]-'0'==1){
            u--;
            swap(u,z);
            u++;
        }
        else{
            z--;
            swap(u,z);
            z++;
        }
        mini=min(mini,u);
        maxi=max(maxi,u);
       
    }
    cout<<mini<<" "<<maxi;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
