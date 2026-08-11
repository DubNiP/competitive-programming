#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
#define int ll
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


void solve() {
    int n,i; cin>>n;
    vector<ii>v(n);
    vector<ii> resps(n);
    for(i=0;i<n;i++){
        cin>>v[i].f;
        v[i].s=i;
    }

    sort(v.begin(),v.end());
    for(i=0;i<n;i++){
        resps[i].f=v[i].s;
        resps[i].s=-1;
    }
    //for(auto[a,b] : resps) cout<<a<<" "<<b<<"\n";
    int acumul=0,num=v[0].f,same=1,minimo=0;
    if(v[0].f!=0){
        cout<<"-1\n";
        return;
    }

    for(i=1;i<n;i++){
        if(num==v[i].f) same++;
        else{
            if((v[i].f-acumul)%same!=0||(v[i].f-acumul)/same<=minimo){
                cout<<"-1\n";
                return;
            }
            int j=i-1;
            while(resps[j].s==-1&&j>=0){
                resps[j].s=(v[i].f-acumul)/same;
                j--;
            } 
            minimo=(v[i].f-acumul)/same;
            acumul=v[i].f;
            same=1;
            num=v[i].f;
        }
    }
    int j=n-1;
    while(resps[j].s==-1&&j>=0){
        resps[j].s=minimo+1;
        j--;
    }
    sort(resps.begin(),resps.end());
    for(auto [a,b] : resps) cout<<b<<" ";
    cout<<"\n";


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
