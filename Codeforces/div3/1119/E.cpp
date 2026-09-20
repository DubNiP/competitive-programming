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
    int i,n; cin>>n;
    vi v(n);
    for(auto&w:v)cin>>w;
    vi diff(n+2,0);
    
    for(i=0;i<n;i++){
        if(v[i]!=-1){
            int l=max(0LL,i-v[i]+1),r=min(n-1,i+v[i]-1);
            if(l<=r){
                diff[l]++;
                diff[r+1]--;
            }
        }
    }
    
    for(i=1;i<n;i++)diff[i]+=diff[i-1];
    
    bool p =true;
    for(i=0;i<n;i++){
        if(v[i]!=-1){
            int z1=i-v[i];
            int z2=i+v[i];
            bool ok=false;
            if(z1>=0&&diff[z1]==0)ok=true;
            if(z2<n&&diff[z2]==0)ok=true;
            if(!ok) {
                p=false;
                break;
            }
        }
    }

    if(!p){
        cout<<"-1"<<endl;
        return;
    }
    string s="";
    for(i=0;i<n;i++){
        if(diff[i]==0) s+='1';
        else s+='0';
    }
    cout<<s<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
