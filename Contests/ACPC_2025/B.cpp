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
    int i;
    bool b=true;
    string s; getline(cin,s);
    string aux;
    for(i=0;i<sz(s);i++){
        if(s[i]=='*'){
            if(b){
                aux+="\\bf{";
            }
            else{
                aux+="}";
            }
            i++;
            b=!b;
        }
        else aux+=s[i];
    }
    cout<<aux;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
