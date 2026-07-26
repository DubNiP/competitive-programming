#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s,par,imp;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%2==0) par.push_back(s[i]);
        else imp.push_back(s[i]);
    }
    cout<<par<<"\n"<<imp<<"\n";

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}


