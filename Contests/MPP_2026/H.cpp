#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using vi = vector<int>;

using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int n,r=0; cin>>n;
    for(int i=0;i<n;i++){
        int aux; cin>>aux; r+=aux;
    }
    if(r>120) r+=180;
    if(r>720) r+=180;
    cout<<r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
