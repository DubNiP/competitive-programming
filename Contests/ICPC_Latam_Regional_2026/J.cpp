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
    int a,b; cin>>a>>b;

    if(a*b<10||a==2||b==2||(a==4&&b==4)) cout<<"*"<<endl;
    else{
        if(a==4){
            if(b!=8) cout<<"1 2"<<endl;
            else cout<<"1 1"<<endl;
        }
        else if(b==4){
            if(a!=8) cout<<"2 1"<<endl;
            else cout<<"1 1"<<endl;
        }
        else if(a==b) cout<<"2 1"<<endl;
        else cout<<"1 1"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
