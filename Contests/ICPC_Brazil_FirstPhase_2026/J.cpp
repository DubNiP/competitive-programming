#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long



void solve(){
    set<int>s;
    int aux;
    for(int i=0;i<10;i++){
        cin>>aux;
        s.insert(aux);
    }
    cout<<4-s.size();

}



int main() {
    _
    int t=1;
    //cin >> t
    while (t--) {
        solve();
    }
    return 0;
}
