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

    int n;
    cin>>n;
    int l=0,r=n;
    int resp=inf;
    while(l<=r){
        int mid=(l+r)/2;
        int lim=0,mult=1;
        for(int i=mid;i>0;i--){
            while(i*(mult+1)<=mid)mult++;
            lim+=i*mult;
        }
        if(lim>=n){
            resp=min(resp,mid);
            r=mid-1;
        }
        else l=mid+1;
    }

    cout << resp << endl;
    int bag = 1;
    int rem = n; 

  
    for (int i = resp; i >= 1 && rem > 0; i--) {
        int qnt = resp / i;
        for (int j = 0; j < qnt && rem > 0; j++) {
            int pegar = min(i, rem);
            for (int k = 0; k < pegar; k++) {
                cout << bag << " ";
            }
            rem -= pegar;
            bag++;
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
