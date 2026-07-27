#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,q,i; cin>>n>>q;
    string s; cin>>s;
    vector<int>erra(n),errb(n),psuma(n+1),psumb(n+1);
    psuma[0]=0;
    psumb[0]=0;
    for(i=0;i<n;i++){
        if(i%2==0){
            erra[i]=1;
            errb[i]=0;
        }
        else{
            erra[i]=0;
            errb[i]=1;
        }

        psuma[i+1]=psuma[i]+(erra[i]^(s[i]-'0'));
        psumb[i+1]=psumb[i]+(errb[i]^(s[i]-'0'));
    }

    vector<int>psumar(n+1),psumbr(n+1);
    psumar[0]=0;
    psumbr[0]=0;
    for(i=1;i<=n;i++){
        psumar[i]=psumar[i-1];
        psumbr[i]=psumbr[i-1];
        if(psuma[i]==1&&psuma[i-1]==0) psumar[i]++;
        if(psumb[i]==1&&psumb[i-1]==0) psumbr[i]++;
    }

    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        int aux1=psumar[b]-psumar[a-1],aux2 = psumbr[b]-psumbr[a-1];
        min(aux1,aux2)<=c ? cout<<"YES\n" : cout<<"NO\n"; 
    }
   
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
