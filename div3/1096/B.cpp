#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int tam,a=0,b=0;
    cin>>tam;
    for(int i=0;i<tam;i++){
        char aux;
        cin>>aux;
        if(aux=='(') a++;
        else b++;
    }
    if(a==b) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                cin >> q;
                    while(q--) solve();
                        return 0;
} 
