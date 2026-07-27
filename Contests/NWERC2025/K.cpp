#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int h,w,k,i,j,t,u;
    cin>>h>>w>>k>>i>>t;
    vector<vector<char>>grid(h,vector<char>(w));
    grid[0][0]='K';
    grid[0][1]='I';
    grid[0][2]='T';
    k--;
    i--;
    t--;
    bool ok=true;
    for(u=0;u<h;u++){
        for(j=0;j<w;j++){
            if(u==0&&ok){j+=3; ok=false;}
            if(j>=w)continue;
            if(k>0){ grid[u][j]='K'; k--;}
            else if(t>0){ grid[u][j]='T';t--;}
            else {grid[u][j]='I';i--;}
        }
    }
    for(u=0;u<h;u++){
        for(j=0;j<w;j++){
            cout<<grid[u][j];
        }
        cout<<"\n";
    }
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
            
                    while(q--) solve();
                        return 0;
}

