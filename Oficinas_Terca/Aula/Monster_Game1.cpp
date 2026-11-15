#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    
    int n;
    cin>>n;

    vector<int>espadas(n);
    vector<int>niveis(n+1);
    niveis[0]=0;

    for(int i=0;i<n;i++) cin>>espadas[i];

    sort(espadas.begin(),espadas.end());

    for(int i=1;i<=n;i++){
        int aux;
        cin>>aux;
        niveis[i]=niveis[i-1]+aux;
    }
    
    int resp=0;

    for(int i=0;i<n;i++){
        int disp=n-i;

        auto x = upper_bound(niveis.begin(),niveis.end(),disp);
        int pos = (x-niveis.begin())-1;

        resp = max(resp,pos * espadas[i]);
    }
    cout<<resp<<endl;
}



signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();

}
