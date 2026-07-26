#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,k,mid,resp=0;
vector<vector<ll>>mat;
map<ll,ll> mapa[20][20];

void searchBGN(int x, int y, ll xo){
    xo^=mat[x][y];
    if(x+y==mid){
        mapa[x][y][xo]++;
        return;
    }
    if(x+1<n) searchBGN(x+1,y,xo);
    if(y+1<m) searchBGN(x,y+1,xo);
}

void searchEND(int x, int y, ll xo,ll cont){
    if(cont==n+m-2-mid){
        if(mapa[x][y].count(k^xo)) resp+=mapa[x][y][xo^k];
        return;
    }
    xo^=mat[x][y];
    if(x>0) searchEND(x-1,y,xo,cont+1);
    if(y>0) searchEND(x,y-1,xo,cont+1);
}

void solve(){
    cin>>n>>m>>k;
    mat=vector<vector<ll>>(n,vector<ll>(m));
    mid=(n+m-2)/2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>mat[i][j];
    }
    searchBGN(0,0,0);
    searchEND(n-1,m-1,0,0);
    cout<<resp<<"\n";
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();

}
