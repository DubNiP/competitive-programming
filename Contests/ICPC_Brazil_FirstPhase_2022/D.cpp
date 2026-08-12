#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    
    int n,i,x,y; cin>>n>>x>>y;
    int cx=1,cy=1;
    for(i=0;i<n-1;i++) cx*=2;
    cy=cx;
    
    int dist=cx/2;
    int aux=0,resp=0;
    while(cx!=x){
        if(cx>x) cx-=dist;
        else cx+=dist;
        dist/=2;
        resp++;
    }
    dist=cy/2;
    while(cy!=y){
        if(cy>y) cy-=dist;
        else cy+=dist;
        dist/=2;
        aux++;
    }
    cout<<max(aux,resp);

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
