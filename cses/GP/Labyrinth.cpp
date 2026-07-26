#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m,i,j;
bool ok=false;
vector<vector<int>>siz;
vector<vector<char>>mat;
vector<vector<bool>>vis;
vector<vector<char>>letter;
int bx,by;

bool verifica(int a, int b){
    if(a>=0&&a<n&&b>=0&&b<m) return true;
    return false;
}


void bfs(int c, int d){
    queue<pair<int,int>>fila;
    fila.push({c,d});
    while(fila.size()!=0){
        pair<int,int>aux = fila.front();
        int x=aux.first;
        int y=aux.second;
        fila.pop();
        if(verifica(x+1,y)&&mat[x+1][y]!='#'&&!vis[x+1][y]){
            siz[x+1][y]=siz[x][y]+1;
            vis[x+1][y]=true;
            letter[x+1][y]='D';
            fila.push({x+1,y});
            if(mat[x+1][y]=='B'){
                ok=true;
                bx=x+1;
                by=y;
                return;
            }
        }
        if(verifica(x-1,y)&&mat[x-1][y]!='#'&&!vis[x-1][y]){
            siz[x-1][y]=siz[x][y]+1;
            vis[x-1][y]=true;
            letter[x-1][y]='U';
            fila.push({x-1,y});
            if(mat[x-1][y]=='B'){
                ok=true;
                bx=x-1;
                by=y;
                return;
            }
        }
        if(verifica(x,y+1)&&mat[x][y+1]!='#'&&!vis[x][y+1]){
            siz[x][y+1]=siz[x][y]+1;
            vis[x][y+1]=true;
            letter[x][y+1]='R';
            fila.push({x,y+1});
            if(mat[x][y+1]=='B'){
                ok=true;
                bx=x;
                by=y+1;
                return;
            }
        }
        if(verifica(x,y-1)&&mat[x][y-1]!='#'&&!vis[x][y-1]){
            siz[x][y-1]=siz[x][y]+1;
            vis[x][y-1]=true;
            letter[x][y-1]='L';
            fila.push({x,y-1});
            if(mat[x][y-1]=='B'){
                ok=true;
                bx=x;
                by=y-1;
                return;
            }
        }
    }
}

string resp;

void bfsprint(int x,int y){
    if(verifica(x-1,y)&&letter[x][y]=='D'){
        resp.push_back(letter[x-1][y]);
        bfsprint(x-1,y);
        return;
    }
    if(verifica(x+1,y)&&letter[x][y]=='U'){
        resp.push_back(letter[x+1][y]);
        bfsprint(x+1,y);
        return;
    }
    if(verifica(x,y+1)&&letter[x][y]=='L'){
        resp.push_back(letter[x][y+1]);
        bfsprint(x,y+1);
        return;
    }
    if(verifica(x,y-1)&&letter[x][y]=='R'){
        resp.push_back(letter[x][y-1]);
        bfsprint(x,y-1);
        return;
    }
}


void solve() {
    cin>>n>>m;
    mat=vector<vector<char>>(n,vector<char>(m));
    siz=vector<vector<int>>(n,vector<int>(m,0));
    vis=vector<vector<bool>>(n,vector<bool>(m,false));
    letter=vector<vector<char>>(n,vector<char>(m));
    int bgnx=-1,bgny=-1;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='A'){
                bgnx=i;
                bgny=j;
            }
        }
    }
    siz[bgnx][bgny]=0;
    vis[bgnx][bgny]=true;
    bfs(bgnx,bgny);
    if(!ok){ 
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n"<<siz[bx][by]<<"\n";
    resp.push_back(letter[bx][by]);
    bfsprint(bx,by);
    int k=resp.size();
    for(i=k-2;i>=0;i--) cout<<resp[i];
    cout<<"\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
