#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<ll>sa(30),sp(30);
    string auxa,auxp;
    getline(cin,auxa);
    getline(cin,auxp);
    for(auto w : auxa) sa[w-'a']++;
    for(auto w : auxp) sp[w-'a']++;
    ll jog,num; cin>>jog;
    while(jog--){
        cin>>num;
        if(num==3){
            bool ok=false,merdaa=false,merdap=false;
            for(int i=0;i<=26;i++){
                if(merdaa&&sa[i]>0){
                    cout<<"PY\n";
                    break;
                }
                if(merdap&&sp[i]>0){
                    cout<<"ADA\n";
                    break;
                }
                if(sa[i]<sp[i]) merdaa=true;
                else if(sa[i]>sp[i]) merdap=true;
                if(i==26){
                    if(merdaa) cout<<"ADA\n";
                    else if(merdap) cout<<"PY\n";
                    else cout<<"EMPATE\n";
                }
            }
        }
        else{
            ll k; string s;
            cin>>k;
            cin>>s;
            for(auto w : s) num==1 ? sa[w-'a']+=k : sp[w-'a']+=k;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
}

