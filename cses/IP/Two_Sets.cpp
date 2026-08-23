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
    int n,i; cin>>n;
    if(n%4==1||n%4==2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vi on,off;
    if(n%2==0){
        for(i=1;i<=n/2;i++){
            if(i%2==0){
                on.pb(i);
                on.pb(n-i+1);
            }
            else{
                off.pb(i);
                off.pb(n-i+1);
            }
        }
    }
    else{
        on.pb(1);on.pb(2);off.pb(3);
        for(i=1;i<=n/2-1;i++){
            if(i%2==0){
                on.pb(i+3);
                on.pb(n-i+1);
            }
            else{
                off.pb(i+3);
                off.pb(n-i+1);
            }
        }
    }

    sort(all(on));
    sort(all(off));
    cout<<sz(on)<<endl;
    for(auto w : on) cout<<w<<" ";
    cout<<endl<<sz(off)<<endl;
    for(auto w : off) cout<<w<<" ";

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
