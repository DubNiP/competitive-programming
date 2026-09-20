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
    int i,n,resp=-1; cin>>n;
    string s; cin>>s;
    if(s[0]=='0'){
        cout<<-1<<endl;
        return;
    }

    int l=1,r=n,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        int sup=0,supm=0;
        int inf=0,infm=0;
        for(i=0;i<n;i++){
            infm=inf-mid;supm=sup+mid;
            if(s[i]=='0'){
                infm=max(infm,0LL);
                supm=min(supm,0LL);
            }
            else if(s[i]=='+') infm=max(infm,1LL);
            else supm=min(supm,-1LL);
            if(infm>supm){
                l=mid+1;
                break;
            }
            inf=infm; sup=supm;
            if(i==n-1){
                resp=mid;
                r=mid-1;
                break;
            }
        }
    }
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
