#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

void solve(){
    int x1,y1,r1; cin>>x1>>y1>>r1;
    int x2,y2,r2; cin>>x2>>y2>>r2;
    int k; cin>>k;


    int x=abs(x1-x2);
    int y=abs(y1-y2);
    int z=r1+r2; z*=z;
    int dist = x*x+y*y;

    if(dist>z){
        int aux=max(r1,r2);
        aux*2 >= k ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    else if(dist==z){
        int aux=r1+r2;
        aux*2 >= k ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    else {
        int aux=(r1+r2)+sqrt(dist); int rm=max(r1,r2);
        aux=max(aux,rm*2);
        aux >= k ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int q; cin>>q;
    while(q--)solve();
}
