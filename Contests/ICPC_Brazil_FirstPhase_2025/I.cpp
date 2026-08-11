#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int n,i,x,y; cin>>n;
    vector<ii> v(n);
    for(i=0;i<n;i++){
        cin>>x>>y;
        v[i]={x,y};
    }
    vi dist(n);
    dist[0]=0;
    for(i=1;i<n;i++){
        if(v[i].f==v[i-1].f) dist[i]=abs(v[i].s-v[i-1].s);
        else dist[i]=abs(v[i].f-v[i-1].f);
    }
    int l=1,r=dist[1]-1;
    if(l>r){
        cout<<-1<<"\n";
        return;
    }
    for(i=1;i<n-1;i++){
        int aux=l;
        l=dist[i]-r;
        r=dist[i]-aux;

        if(r>dist[i+1]-1) r=dist[i+1]-1;
        if(l<1) l=1;
        if(r<l){
            cout<<-1<<"\n";
            return;
        }
    }
    for(i=n-2;i>0;i--) r=dist[i]-r;
    for(i=n-2;i>0;i--) l=dist[i]-l;
    cout<<max(l,r);






}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
