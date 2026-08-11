#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int i,j,n,sum=0; cin>>n;
    vi v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if(sum%2==1){
        cout<<"-1\n";
        return;
    }

    vi freq(10900,-1);
    for(i=0;i<n;i++){
        int w=v[i];
        for(j=10090;j>=w;j--){
            if(freq[j]==-1&&freq[j-w]!=-1) freq[j]=w;
        }
        if(freq[w]==-1)freq[w]=w;
    }

    vi resp;
    int cont;
    if(freq[sum/2]==-1){
        cout<<"-1\n";
        return;
    }
    cont=sum/2;
    while(cont>0){
        resp.pb(freq[cont]);
        cont-=freq[cont];
    }
    multiset<int>conj;
    for(auto w : v) conj.insert(w);
    for(auto w : resp){
        auto t = conj.find(w);
        conj.erase(t);
    }
    int a=0,b=0,p=0;
    auto t=conj.begin();
    while(t!=conj.end()&&p!=(int)resp.size()){
        if(a>b){
            cout<<*t<<" ";
            b+=*t;
            t++;
        }
        else{
            cout<<resp[p]<<" ";
            a+=resp[p];
            p++;
        }
    }
    while(t!=conj.end()){
        cout<<*t<<" ";
        t++;
    }
    while(p!=(int)resp.size()){
        cout<<resp[p]<<" ";
        p++;
    }


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
