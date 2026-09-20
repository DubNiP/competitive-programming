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

vvi tab;

void calc(int a,int b){

    int i,j,k;
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            if(j==i){
                tab[i][i]=0;
                continue;
            }
            for(k=1;k<i;k++)
                tab[i][j]=min(tab[i][j],tab[k][j]+tab[i-k][j]+1);
            for(k=1;k<j;k++)
                tab[i][j]=min(tab[i][j],tab[i][k]+tab[i][j-k]+1);
        }
    }
}

void solve(){

    int i,a,b,resp=0; cin>>a>>b;
    if(b>a) swap(a,b);
    tab=vvi(a+1,vi(b+1,INF));
    calc(a,b);
    cout<<tab[a][b]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
