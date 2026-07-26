#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<ll>sa(30),sp(30);
    string auxa,auxp;
    cin>>auxa>>auxp;
    for(auto w : auxa) sa['a'-w]++;
    for(auto w : auxp) sp['a'-w]++;

    ll jog,num; cin>>jog;
    while(jog--){
        cin>>num;
        if(num==3){
            for(int i=0;i<26;i++){
                if(sa[i]>sp[i]){
                    cout<<"ADA\n";
                    break;
                }
                else if(sp[i]>sa[i]){
                    cout<<"PY\n";
                    break;
                }
                else if(i==26){
                    cout<<"EMPATE\n";
                }
            }
        }
        else{
            ll k; string s;
            cin>>k;
            cin>>s;
            for(auto w : s) num==1 ? sa['a'-w]+=k : sp['a'-w]+=k;
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
