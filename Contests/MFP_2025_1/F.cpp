#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int i,n,r,t,b=0;
    cin>>n>>r>>t;
    vector<int>v(n);
    for(i=0;i<n;i++) v[i]=i+1;
    for(i=0;i<n;i++){
        if(v[i]==r){
            if(i==n-1) b=0;
            else b=i;
            v.erase(v.begin()+i);
            break;
        }
    }
    while(t--){
        b++;
        b=(b%(n-1));
    }

    cout<<v[b]<<"\n";
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
             
                    while(q--) solve();
                        return 0;
}

