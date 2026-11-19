#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


const int INF = 2e18;
const int MOD = 1e9+7;

vvi adj;
deque<int> fila1;
deque<int> fila2;
bool mark=true;
vi helper;


bool dfs(int i,int p){
    if(i==0||sz(adj[i])!=1)fila1.pb(i);
    for(auto w : adj[i]){
        if(w!=p){
            if(!dfs(w,i)) return false;
            if(sz(fila1)>0&&fila1[sz(fila1)-1]==w) fila1.pop_back();
            if(sz(fila2)>0&&fila2[sz(fila2)-1]==w) fila2.pop_back();
        }
    }
    if(sz(adj[i])==1&&i!=0){
        if(!mark&&sz(fila2)==0){
            cout<<"*"<<endl;
            return false;
        }
        if(mark){
            mark=false;
            helper[i]=fila1[0]+1;
            fila1.pop_front();
            fila2=fila1;
            while(sz(fila1)>0) fila1.pop_back();
           
            
        }
        else{
            helper[i]=fila2[sz(fila2)-1]+1;
            fila2.pop_back();
            for(auto w : fila1) fila2.pb(w);
            while(sz(fila1)>0) fila1.pop_back();
        }
    }
    return true;
}

void solve(){

    int i,n; cin>>n;
    adj=vvi(n);
    helper=vi(n);
    for(i=1;i<n;i++){
        int aux; cin>>aux; aux--;
        adj[aux].pb(i);
        adj[i].pb(aux);
    }

    if(dfs(0,-1)){
        for(auto w : helper) cout<<w<<" ";
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
