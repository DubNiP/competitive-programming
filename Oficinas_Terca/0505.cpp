#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

void solve() {
    int q,i,j,k;
    string s;
    cin>>s;
    cin>>q;
    int n=s.size();
    vector<vector<int>>ps(n+1,vector<int>(26,0);
    for(i=1;i<n;i++){
        for(j=0;j<26;j++){
            ps[i][j]=ps[i-1][j];
        }
        ps[i][s[i]-'a']++;
    }

    for(i=0;i<q;i++){
        string a,b;
        int l,r;
        cin>>a>>l>>r;
        l--,r--;
        if(a=='INSIDE'){
            cin>>b;
            
        }
        else{

        }
    }

}

signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                cin >> q;
                    while(q--) solve();
                        return 0;
} 
