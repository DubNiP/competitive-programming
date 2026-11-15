#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

void solve(){
    string s; cin>>s;
    string a;
    for(int i=0;i<s.size();i++){
        if(i<s.size()-5&&s[i]=='m'&&s[i+1]=='e'
            &&s[i+2]=='s'&&s[i+3]=='e'
            &&s[i+4]=='r'&&s[i+5]=='o'){
            a+="taquero";
            i+=5;
        }
        else a+=s[i];
    }
    cout<<a<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


