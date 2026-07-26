#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;

void solve() {
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    int diff;
    if(l<=r) diff=r-l+1;
    else diff=n-l+r+1;
    double resp;
    if((l<=r&&k>=l&&k<=r)||(l>r&&(k>=l||k<=r))){
        resp=(double)(diff-1)/(double)(n-1);
    }
    else resp=(double)diff/(double)(n-1);
    cout<<fixed<<setprecision(9)<<resp<<"\n";
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
            while(q--) solve();
                        return 0;
}

