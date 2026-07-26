#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

vvi transp;
vb vis;
vi stamp;
vi ord;
vi resp;
bool ok=true;
int stop=-1;


void dfstransp(int i){
    vis[i]=true;
    stamp[i]=0;
    for(auto w : transp[i]){
        if(!vis[w]&&ok) dfstransp(w);
        else if(ok&&stamp[w]==0){
            ok=false;
            stop=w+1;
            resp.push_back(w+1);
        }
    }
    if(!ok)resp.push_back(i+1);
    stamp[i]=1;
    ord.push_back(i);
}


void solve() {

    int i,m,n; cin>>n>>m;
    transp=vvi(n);
    vis=vb(n);
    stamp=vi(n,-1);

    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        transp[b].push_back(a);
    }
    for(i=0;i<n;i++) if(!vis[i]&&ok) dfstransp(i);
    if(ok) cout<<"IMPOSSIBLE";
    else{
        bool av=false;
        int aux=-1;
        for(i=resp.size()-1;i>=0;i--)
            if(resp[i]==stop){
                aux=i;
                break;
            }
        cout<<aux+1<<"\n";
        for(i=0;i<resp.size();i++){
            if(resp[i]==stop){
                if(!av)av=true;
                else{
                    cout<<resp[i];
                    return;
                }
            }
            cout<<resp[i]<<" ";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}

