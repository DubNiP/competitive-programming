#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,k,cont=0;
    string s;
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<k;i++){
        cont=0;
        for(int j=i;j<n;j+=k){
            if(s[j]=='1'){
                cont++;
            }
        }
        if(cont%2==1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                cin >> q;
                    while(q--) solve();
                        return 0;
}

