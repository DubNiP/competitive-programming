#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


void solve() {
    int n; cin>>n;
    string s1,s2; cin>>s1>>s2;
    ll resp=0;
    bool trade=false;

    int par1=0,impar1=0,par2=0,impar2=0;

    for(int i=0;i<n;i++){
        if(s1[i]=='1'){
            if(i%2==0) par1++;
            else impar1++;
        }
        if(s2[i]=='1'){
            if(i%2==0) par2++;
            else impar2++;
        }
    }
    if(par1!=par2||impar1!=impar2){
        cout<<"-1\n"; 
        return;
    }

    int aux=0;
    for(int i=0;i<n;i+=2){
        resp+=abs(aux);
        if(s1[i]!=s2[i]){
            if(s1[i]=='1') aux++;
            else aux--;
        }
    }

    for(int i=1;i<n;i+=2){
        resp+=abs(aux);
        if(s1[i]!=s2[i]){
            if(s1[i]=='1') aux++;
            else aux--;
        }
    }


    cout<<resp<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}

