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

vi siz;
vi id;

int find(int i){
    if(id[i]==i) return i;
    return i=find(id[i]);
}

void unir(int a,int b){
    int p=find(a),q=find(b);
    if(p==q) return;
    if(siz[p]>siz[q]) swap(p,q);
    id[p]=id[q];
    siz[q]+=siz[p];
}


void solve(){
    int n,m; cin>>n>>m;
    siz=vi(n,1); id=vi(n);
    iota(id.begin(),id.end(),0);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        unir(a,b);
    }
    set<int>conj;
    for(int i=0;i<n;i++) conj.insert(find(i));
    cout<<conj.size();
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}

