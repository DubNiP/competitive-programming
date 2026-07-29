#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

set<string> conjunto;
map<string,bool> mapa;

void brute(string s){
    if(mapa.count(s)) return;
    else mapa[s]=true;
    if(s.size()==11){
        if(s[0]=='1'&&s[1]!='0'&&s[2]=='9') conjunto.insert(s);
        return;
    }

    for(int i=0;i<s.size()+1;i++){
        string aux1=s,aux2=s;
        aux1.insert(i, 1, '1');
        aux2.insert(i, 1, '9');
        brute(aux1); brute(aux2);
    }
}


void solve() {

    string s; cin>>s;
    int n=s.size();
    if(n>11){ cout<<"0\n"; return;}
    brute(s);
    cout<<conjunto.size()<<"\n";
    for(auto w : conjunto) cout<<w<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
