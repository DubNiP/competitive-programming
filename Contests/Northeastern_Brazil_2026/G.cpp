#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


const int INF = 2e18;
const int MOD = 1e9+7;

void solve(){
    int n; cin>>n;
    int resp=0;
    deque<char>v;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        int l;char c; cin>>l;
        if(l==1){
            cin>>c;
            if(c=='A') a++;
            else{
                b++;
                resp+=a;
            }
            v.pb(c);
        }
        else if(l==2){
            cin>>c;
            if(c=='B') b++;
            else{
                a++;
                resp+=b;
            }
            v.push_front(c);
        }
        else if(l==3){
            char c=v[sz(v)-1];
            if(c=='B'){
                resp-=a;
                b--;
            }
            else a--;
            v.pop_back();
        }
        else{
            char c=v[0];
            if(c=='A'){
                resp-=b;
                a--;
            }
            else b--;
            v.pop_front();
        }
        cout<<resp<<endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
