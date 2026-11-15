#include <bits/stdc++.h>

using namespace std;


void solve(){
    int s,n;

    cin>>s>>n;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        if(s<=v[i].first){
            cout<<"NO\n";
            return;
        }
        s+=v[i].second;
    }
    
    cout<<"YES\n"<<endl;

}


int main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
}
