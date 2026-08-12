#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
#define int ll
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){

    int i,n,resp=0; cin>>n;
    vector<ii>v(n);
    for(auto &w : v) cin>>w.f;
    for(auto &w : v) cin>>w.s;

    int k,l; cin>>k>>l;

    int cont=0,contseg=0;

    multiset<int>conjpego,conj;



    for(i=0;i<k;i++){
        cont+=v[i].f;
        if(i<l){
            contseg+=v[i].s;
            conjpego.insert(v[i].s);
        }
        else{
            if(*(conjpego.begin())<v[i].s){
                contseg-=(*(conjpego.begin()));
                contseg+=v[i].s;
                conj.insert(*conjpego.begin());
                conjpego.erase(conjpego.begin());
                conjpego.insert(v[i].s);
            }
            else{
                conj.insert(v[i].s);
            }
        }
    }
    int idx=n-1;
    for(i=0;i<k;i++){
        resp=max(resp,cont+contseg);
        int ind=k-i-1;

        cont-=v[ind].f;
        cont+=v[idx].f;

        
        auto it=conj.find(v[ind].s);
        if(it==conj.end()){
            contseg-=v[ind].s;
            contseg+=*conj.rbegin();
            conjpego.erase(conjpego.find(v[ind].s));
            conjpego.insert(*conj.rbegin());
            conj.erase(conj.find(*conj.rbegin()));
            if(v[idx].s>(*conjpego.begin())){
                contseg-=(*conjpego.begin());
                contseg+=v[idx].s;
                conj.insert(*conjpego.begin());
                conjpego.erase(conjpego.begin());
                conjpego.insert(v[idx].s);
            }
            else conj.insert(v[idx].s);
        }
        else{
            conj.erase(it);
            if(v[idx].s>(*conjpego.begin())){
                contseg-=(*conjpego.begin());
                contseg+=v[idx].s;
                conj.insert(*conjpego.begin());
                conjpego.erase(conjpego.begin());
                conjpego.insert(v[idx].s);
            }
            else conj.insert(v[idx].s);
        }
        idx--;
    }
    cout<<max(resp,cont+contseg);

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
