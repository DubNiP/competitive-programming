#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int at=0,maxi=0,seq=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=at){
            seq=1;
            at=s[i];
        }
        else seq++;
        maxi=max(maxi,seq);
    }
    cout<<maxi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
