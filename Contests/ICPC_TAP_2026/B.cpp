#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

void solve(){
    string s; cin >> s;
    int n = s.length();
    vector<string> ans;
    for(int i = 3; i < n; i++){
        if(s[i-2] == 'G' && s[i-1] == 'A' && s[i] == 'S'){
            if(i+1 < n && s[i-3] == s[i+1]){
                if(s[i+1] == 'A' || s[i+1] == 'E' || s[i+1] == 'I' || s[i+1] == 'O' || s[i+1] == 'U'){
                    ans.push_back(s.substr(0, i-3) + s.substr(i+1, n));
                }
            }
        }
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    if(ans.size() == 0) cout << "-\n";
    else if(ans.size() > 1) cout << "+\n";
    else{
        cout << ans[0] << '\n';
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
