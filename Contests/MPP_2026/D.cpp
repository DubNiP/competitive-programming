#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using vi = vector<int>;

using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int n,i,j,k; cin>>n;

    for(i=0;i<n;i++) cout<<" ";
    for(i=0;i<n+1;i++) cout<<"_";

    cout<<"\n";

    for(i=0;i<n-1;i++){
        for(j=0;j<2*(n+1)+i;j++){
            if(j<n-i-1) cout<<" ";
            else if(j==n-i-1) cout<<"/";
            else if (j!=2*(n+1)+i-1) cout<<" ";
            else cout<<"\\";
        }
        cout<<"\n";
    }

    cout<<"/"; 
    for(i=0;i<n;i++) cout<<"_"; 
    for(i=0;i<2*n-1;i++) cout<<" "; 
    cout<<"\\"; 
    for(i=0;i<n+1;i++) cout<<"_";

    cout<<"\n";

    for(i=0;i<n-1;i++){
        for(j=0;j<4*n+2-i;j++){
            if(j<n+1+i) cout<<" ";
            else if(j==n+1+i) cout<<"\\";
            else if(j!=4*n+1-i) cout<<" ";
            else cout<<"/";
        }
        cout<<"\n";
    }

    for(i=0;i<2*n;i++) cout<<" ";
    cout<<"\\";
    for(i=0;i<n+1;i++) cout<<"_";
    cout<<"/";


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
