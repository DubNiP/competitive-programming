#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a,b,x,minmov=1e10,movat=0;
    cin>>a>>b>>x;

    if(a==b){
        cout<<"0\n";
        return;
    }


    if(a<b){
        ll tmp=a;
        a=b;
        b=tmp;
    }
    while(a!=b){
        minmov=min(minmov,movat+(a-b));
        a=a/x;
        if(a<b){
            ll tmp=a;
            a=b;
            b=tmp;
        }
        movat++;
    }
    minmov=min(minmov,movat);
    cout<<minmov<<"\n";
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                cin >> q;
                    while(q--) solve();
                        return 0;
}

