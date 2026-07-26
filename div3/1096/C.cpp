#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>dois;
    vector<int>tres;
    vector<int>seis;
    vector<int>none;
    for(int i=0;i<n;i++){
        int aux;
        cin>>aux;
        if(aux%6==0) seis.push_back(aux);
        else if(aux%2==0) dois.push_back(aux);
        else if(aux%3==0) tres.push_back(aux);
        else none.push_back(aux);
    }
    for(int i=0;i<seis.size();i++) cout<<seis[i]<<" ";
    for(int i=0;i<dois.size();i++) cout<<dois[i]<<" ";
    for(int i=0;i<none.size();i++) cout<<none[i]<<" ";
    for(int i=0;i<tres.size();i++) cout<<tres[i]<<" ";
    cout<<endl;
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                cin >> q;
                    while(q--) solve();
                        return 0;
} 
