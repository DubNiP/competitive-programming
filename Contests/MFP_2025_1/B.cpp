#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>>grafo;
vector<bool>visitou;
int add=0,rmv=0;

void dfs(int i,int pai){
    visitou[i]=true;
    for(auto w : grafo[i]){
        if(visitou[w]&&w!=pai) rmv++;
        else if (!visitou[w]) dfs(w,i);
    }
}


void solve() {
    int i,n,ar;
    cin>>n>>ar;
    grafo=vector<vector<int>>(n);
    visitou=vector<bool>(n);
    for(i=0;i<ar;i++){
        int a,b;
        cin>>a>>b; a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    dfs(0,0);
    for(i=1;i<n;i++){
        if(!visitou[i]){
            add++;
            dfs(i,i);
        }
    }
    if(add==0&&rmv==0) cout<<"BOM\n";
    else cout<<"RUIM "<<rmv/2<<" "<<add<<"\n";

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}

