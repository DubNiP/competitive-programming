#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b) cout<<c<<"\n";
    else if(b==c) cout<<a<<"\n";
    else if(a==c) cout<<b<<"\n";
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}

