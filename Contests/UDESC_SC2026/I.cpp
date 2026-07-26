#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll max=100000;

void solve() {
    int h;
    cin>>h;
    if(h%9!=0)cout<<h%9;
    for(int i=0;i<h/9;i++){
        cout<<"9";
    }
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int q = 1;
                    while(q--) solve();
                        return 0;
} 

