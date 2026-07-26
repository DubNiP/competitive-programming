#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    
    int n,x; cin>>n>>x;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    int pe=0,pd=n-1;
    while(pe<pd){
        if(v[pe].first+v[pd].first==x){
            cout<<min(v[pe].second,v[pd].second)<<" "<<max(v[pe].second,v[pd].second);
            return;
        }
        else if(v[pe].first+v[pd].first>x) pd--;
        else pe++;
    }
    cout<<"IMPOSSIBLE";
    

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
