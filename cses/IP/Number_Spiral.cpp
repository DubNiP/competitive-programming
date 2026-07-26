#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void solve() {
    ll y,x; cin>>x>>y;
    if(y>=x){
        if(y%2==1) cout<<(y*y)-x+1<<"\n";
        else cout<<((y-1)*(y-1))+x<<"\n";
    }
    else{
        if(x%2==0) cout<<(x*x)-y+1<<"\n";
        else cout<<((x-1)*(x-1))+y<<"\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
