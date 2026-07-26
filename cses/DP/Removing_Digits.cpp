#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> memo(1e6+9,100000000);
int i;

void dp(int n){
    for(i=1;i<10;i++) memo[i]=1;
    for(i=10;i<=n;i++){
        int aux=i;
        vector<int>dig;
        while(aux!=0){
            dig.push_back(aux%10);
            aux/=10;
        }
        for(int j=0;j<dig.size();j++) memo[i]=min(memo[i],memo[i-dig[j]]+1);
    }
}



void solve() {
    int n;
    cin>>n;
    dp(n);
    cout<<memo[n];

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
