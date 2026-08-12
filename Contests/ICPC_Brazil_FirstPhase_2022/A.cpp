#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int n; cin>>n;
    string s;
    cin>>s;
    int i,cont=0;
    int resp=0;
    for(i=0;i<n;i++){
        if(s[i]=='a') cont++;
        else{
            if(cont>1)resp+=cont;
            cont=0;
        }
    }
    if(cont>1) resp+=cont;
    cout<<resp;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
