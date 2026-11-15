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
vi primes,v(1e6+10);
vi lp(1e6+11,0);
void crivo(int n){
    for(int i=2;i<=n;i++){
        if(lp[i]==0){
            lp[i]=i;
            primes.pb(i);
        }
        for(int p : primes){
            if(p>lp[i] || i*p>n)break;
            lp[i*p]=p;
        }
    }
}

void solve() {

    int i,n,qp=0,resp=0; cin>>n;
    map<int,int>freq;
    vi num(n),cl(n); 
    for(i=0;i<n;i++){
        cin>>num[i];
        int ax=sqrt(num[i]);
        if(ax*ax==num[i])qp++;
        int aux=num[i];
        freq.clear();
        while(aux>1){
            if(freq.count(lp[aux])>0) freq.erase(lp[aux]);
            else freq[lp[aux]]=1;
            aux/=lp[aux];
        }
        int op=1;
        for(auto [a,b] : freq) op*=a;
        v[op]++;
        cl.pb(op);
    }
    freq.clear();
    for(i=0;i<n;i++){
        int aux=num[i];
        while(aux>1){
            if(freq.count(lp[aux])>0) freq.erase(lp[aux]);
            else freq[lp[aux]]=1;
            aux/=lp[aux];
        }
        if(sz(freq)<9){
            int oposto=1;
            for(auto [a,b] : freq) {
                oposto*=a;
                if(oposto>1e6+10) break;
            }
            if(oposto==1) resp+=qp; 
            else if(oposto<1e6+10)resp+=v[oposto];
        }

    }
    cout<<resp<<endl;
    for(auto w : cl) v[w]=0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    crivo(1e6+10);
    while(q--) solve();
    return 0;
}
