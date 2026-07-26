#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,c,i; cin>>n>>c;
    vector<int>v(n);
    for(auto &w : v) cin>>w;
    int val=0;
    vector<int>freq(1e6);
    vector<int>aux(1e6);

    for(i=0;i<n;i++){
        if(v[i]==c) val++;
    }

    int neg=0;
    int resp=0;

    for(i=0;i<n;i++){
        if(v[i]==c) neg++;
        else {
            if(i==0) freq[v[i]]=1;
            else {
                freq[v[i]]++;
                freq[v[i]]=max(1,(freq[v[i]]-neg+aux[v[i]]));
            }
            aux[v[i]]=neg;
        }
        resp=max(resp,freq[v[i]]);
    }
   
    cout<<max(val,val+resp);
    

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
