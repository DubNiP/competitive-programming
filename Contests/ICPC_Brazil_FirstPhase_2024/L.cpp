#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    
    int n,i,j; cin>>n;
    vi bits(36,0);
    for(i=0;i<n;i++){
        int num;
        cin>>num;
        int idx=0;
        while(num){
            if(num%2==1) bits[idx]++;
            num/=2;
            idx++;
        }
    }

    for(i=0;i<n;i++){
        int resp=0;
        for(j=34;j>=0;j--){
            resp*=2;
            if(bits[j]>0) resp++;
            bits[j]--;
        }
        cout<<resp<<" ";
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
