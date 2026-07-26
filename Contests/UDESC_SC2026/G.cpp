#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    int m=1;
    while(true){
        if(100%m!=0){
            m++;
            continue;
        }
        int aux=100/m;
        if(n%aux==0&&n>=aux){
            cout<<m;
            return;
        }
        m++;
    }
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}

