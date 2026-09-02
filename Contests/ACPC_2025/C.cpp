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

    int n,m,i;cin>>n>>m;
    vi cartas(13),naip(4);
    for(i=0;i<n;i++){
        int aux;cin>>aux;
        cartas[aux-1]++;
    }
    for(i=0;i<m;i++){
        char c;cin>>c;
        if(c=='H')naip[0]++;
        else if(c=='S')naip[1]++;
        else if(c=='D')naip[2]++;
        else naip[3]++;
    }
    vi pego;
    for(i=0;i<13;i++){
        if(cartas[i]>4){
            cout<<"NO\n";
            return;
        }
        pego.pb(cartas[i]);
    }
    for(i=0;i<4;i++){
        if(naip[i]>13){
            cout<<"NO\n";
            return;
        }
    }
    sort(all(pego));
    sort(all(naip));
    for(i=3;i>=0;i--){
        int aux=naip[i];
        sort(all(pego));
        for(int j=0;aux>0;j++){
            if(pego[j]==4){
                cout<<"NO\n";
                return;
            }
            pego[j]++;
            aux--;
        }
    }
    cout<<"YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--)solve();


    return 0;
}
