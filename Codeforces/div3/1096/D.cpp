#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int>v;
int n;

int sol(int l,int r){
    int mid=(l+r)/2;
    int ant=mid,prox=mid;
    if(l!=r&&(l+r)%2==1) prox++;
    while(ant>=0&&prox<(2*n)&&v[ant]==v[prox]){
        prox++;
        ant--;
    }
    set<int> s;
    for(int i=ant+1;i<=mid;i++) s.insert(v[i]);
    int trk=0;
    while(s.find(trk)!=s.end()) trk++;
    return trk;
}




void solve() {
    int i;
    cin>>n;
    v=vector<int>(2*n);
    for(auto &w : v) cin>>w;
    int resp=0,id00=-1,id01=-1;
    for(i=0;i<2*n;i++){
        if(v[i]==0){
            if(id00 == -1){ 
                id00=i;
                resp=sol(id00,id00);
            }
            else{
                id01=i;
                resp=max(resp,sol(id01,id01));
            }
           
        }
    }
    resp=max(resp,sol(id00,id01));
    cout<<resp<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin>>q;
    while(q--) solve();
    return 0;
}

