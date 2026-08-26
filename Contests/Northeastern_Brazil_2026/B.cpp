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

vector<string> r = {"000", "001", "011", "010", "110", "111", "101", "100"};

void solve(){
    int ind=-1;
    string s; cin>>s;
    for(int i=0;i<8;i++){
        if(s==r[i])ind=i;
    }

    for(int i=0;i<9;i++){
        cout<<r[ind]<<endl;
        ind++;
        ind%=8;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
