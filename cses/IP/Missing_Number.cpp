#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,i;
    cin>>n;
    vector<int>v(n-1);
    for(auto &w : v) cin>>w;
    sort(v.begin(),v.end());
    for(i=0;i<n-1;i++){
        if(v[i]!=i+1){
            cout<<i+1;
            return 0;
        }
    }
    cout<<n;

    return 0;
}
