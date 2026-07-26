#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

    int n,i,j; cin>>n;
    vector<int>freq(1010,0);
    vector<int>v(n);
    vector<bool>can(100010,false);
    for(i=0;i<n;i++){
        int aux; cin>>aux;
        v[i]=aux;
        freq[aux]++;
    }
    for(i=0;i<n;i++){
        j=100005;
        while(j>=0){
            if(can[j]&&(freq[v[i]]>1||v[i]!=j)) can[v[i]+j]=true;
            j--;
        }
        can[v[i]]=true;
    }
    int resp=0;
    for(i=0;i<100007;i++) if(can[i]) resp++;
    cout<<resp<<"\n";
    for(i=0;i<100007;i++) if(can[i]) cout<<i<<" ";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
