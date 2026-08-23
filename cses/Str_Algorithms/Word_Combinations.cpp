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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int get_rand_base(int mod){
    int b = uniform_int_distribution<int>(300,mod-1)(rng);
    return b%2==0 ? b-1 : b;
}

const int MOD1 = 1e9+7;
const int BASE1 = get_rand_base(MOD1);

struct DoubleHash {
    vi h1,p1;

    DoubleHash(const string & s){
        int n=sz(s);
        h1.assign(n+1,0); p1.assign(n+1,1);

        for(int i=0;i<n;i++){
            h1[i+1]=(h1[i]*BASE1+s[i])%MOD1;
            p1[i+1]=(p1[i]*BASE1)%MOD1;
        }
    }

    ii get(int l,int r) {
        int len = r-l+1;
        int val = (h1[r+1] - (h1[l] * p1[len])%MOD1 + MOD1) %MOD1;
        return {val,-1};
    }
};



void solve(){
    
    string n;
    int i,k;
    cin>>n;
    cin>>k;
    DoubleHash h(n);
    vector<set<int>> words(5005);
    set<int>sizes;
    for(i=0;i<k;i++){
        string aux; cin>>aux;
        DoubleHash p(aux);
        words[sz(aux)].insert(p.get(0,sz(aux)-1).f);
        sizes.insert(sz(aux));
    }
    vi dp(sz(n)+1);
    dp[sz(n)]=1;
    for(i=sz(n)-1;i>=0;i--){
        for(auto w : sizes){
            if(w+i>sz(n)) continue;
            int v=h.get(i,i+w-1).f;
            if(words[w].find(v)!=words[w].end())
                dp[i]=(dp[i]+dp[i+w])%MOD;
        }
    }
    cout<<dp[0]<<endl;


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
