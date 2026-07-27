#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int i,n,sum=0,sum2=0;
    cin>>n;
    vector<int>din(n),bill(n);
    for(i=0;i<n;i++){
        cin>>din[i]>>bill[i];
        sum+=din[i];
        sum2+=bill[i];
    }
    for(i=0;i<n;i++)
        if(sum2-(sum-din[i])<=bill[i]){
            cout<<i+1<<"\n";
            return;
        }
    cout<<"impossible\n";
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
       
                    while(q--) solve();
                        return 0;
}

