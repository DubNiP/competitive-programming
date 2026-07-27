#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>>precos;

void clc(){
    ll aux = 3;
    ll cont=1;
    precos.push_back({1,3});
    for(int i=0;i<25;i++){
        precos.push_back({aux,aux*3+cont*aux/3});
        cont++;
        aux*=3;
    }
}

void solve() {
    int n,maxi,i=precos.size()-1,deals=0;
    ll preco=0;
    cin>>n>>maxi;
    int aux=n;
    while(n){
        if(precos[i].first<=n){
            n-=precos[i].first;
            deals++;
        }
        else i--;
    }
    if(deals>maxi){
        cout<<"-1\n";
        return;
    }
    int cont=0,dealsaux=maxi-deals;
    bool ok=false;
    while(i>=0){
        int contaux=cont;
        if(contaux!=0&&ok){
            while(contaux&&dealsaux>=2){
                preco-=precos[i+1].second;
                preco+=3*precos[i].second;
                dealsaux-=2;
                contaux--;
            }
        }
        if(precos[i].first<=aux){
            ok=false;
            preco+=precos[i].second;
            aux-=precos[i].first;
            cont++;
        }
        else {
            i--;
            ok=true;
        }
    }

    cout<<preco<<"\n";

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        clc();
        int q = 1;
        cin >> q;
        while(q--) solve();
        return 0;
}

