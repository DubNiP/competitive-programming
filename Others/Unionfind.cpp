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

vi id,sz;

int find(int x){
    if(x==id[x]) return x;
    return id[x]=find(id[x]); 
}

void unite(int x, int y){
    int p=find(x), q=find(y);
    if(p==q) return;
    if(sz[p]<sz[q]) swap(p,q);
    id[q]=id[p];
    sz[p]+=sz[q];
}


void solve(){
    int n,q; cin>>n>>q;
    id = vi(n);
    iota(id.begin(),id.end(),0);
    sz = vi(n,1);
    while(q--){
        int w,a,b; cin>>w>>a>>b;
        if(w==0) unite(a,b);
        else find(a)==find(b) ? cout<<"1\n" : cout<<"0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
