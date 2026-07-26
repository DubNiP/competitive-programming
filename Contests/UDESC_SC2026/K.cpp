#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int>freqr(1e7,0);
vector<int>freqnum(1e7,0);

void decompose(int a,bool w){
    for(int i=1;i*i<=a;i++){
        if(a%i==0){
            w ? freqr[i]++ : freqr[i]--;
            if(i!=a/i) w ? freqr[a/i]++ : freqr[a/i]--;
        }
    }
}

void solve() {
    int n,q,i;
    cin>>n>>q;
    vector<int>v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
        if(freqnum[v[i]]!=0){
            decompose(freqnum[v[i]],false);
        }
        freqnum[v[i]]++;
        decompose(freqnum[v[i]],true);
    }

   
    
    while(q--){
        int a,b,c; cin>>a;
        if(a==1){
            cin>>b>>c; b--;
            decompose(freqnum[v[b]],false);
            freqnum[v[b]]--;
            if(freqnum[v[b]]!=0) decompose(freqnum[v[b]],true);
            v[b]=c;
            if(freqnum[c]!=0) decompose(freqnum[c],false);
            freqnum[c]++;
            decompose(freqnum[c],true);
        }
        else{
            cin>>b;
            cout<<freqr[b]<<"\n";
        }
    }
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}

