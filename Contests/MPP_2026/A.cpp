#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


void solve() {
    int n,q,i; cin>>n>>q;
    vector<ii>bar(n);
    vi ind(n);
    for(auto &[a,b] : bar) cin>>a>>b;
    ind[n-1]=-1;
    for(i=n-2;i>=0;i--){
        if(bar[i].s==bar[i+1].s) ind[i]=ind[i+1];
        else ind[i]=i+1;
    }
    while(q--){
        int mon,no; cin>>mon>>no;
        int resp=-1,l=0,r=n-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(bar[mid].f<=mon){
                r=mid-1;
                resp=mid;
            }
            else l=mid+1;
        }
        if(resp==-1) cout<<"-1\n";
        else if(no==bar[resp].s)
            ind[resp]!=-1 ? cout<<ind[resp]+1<<"\n" : cout<<"-1\n"; 
        else cout<<resp+1<<"\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
