#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vi vector<int>

void solve() {
    int n=0,i,r=0;
    string s;
    cin>>n>>s;
    n=0;
    for(i=0;i<s.size();i++){
        if(s[i]=='#') n++;
        else{
            r=max(r,n);
            n=0;
        }
    }
    r=max(r,n);
    cout<<((r+1)/2)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
