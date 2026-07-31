#include <bits/stdc++.h>
#define f first
#define s second
#define int ll
#define push_back pb
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

int MOD=1e9+7;
int pot=31;

vi p,h,hinv;

void calc_p(){
    p[0]=1;
    for(int i=1;i<p.size();i++) p[i]=(p[i-1]*pot)%MOD;
}

void calc_hash(string s,string sinv){
    h[0]=0;
    hinv[0]=0;
    for(int i=1;i<=s.size();i++){
        h[i]=((h[i-1]*pot)%MOD+(s[i-1]-'a'+1))%MOD;
        hinv[i]=((hinv[i-1]*pot)%MOD+(sinv[i-1]-'a'+1))%MOD;
    }
}

int get_hash(int l,int r,bool a){
   if(a){
       if(r>=h.size()) return -1;
       return (h[r+1]-(h[l]*p[r-l+1])%MOD+MOD)%MOD;
   }
   if(r>=h.size()) return -2;
   return (hinv[r+1]-(hinv[l]*p[r-l+1])%MOD+MOD)%MOD;
}


void solve(){
    string s,sinv; cin>>s;
    sinv=s; reverse(sinv.begin(),sinv.end());
    int n=s.size(),i;
    p=vi(n+1);
    h=vi(n+1);
    hinv=vi(n+1);
    calc_p();
    calc_hash(s,sinv);
    int lresp=0,rresp=0, resp=0;
    for(i=0;i<n;i++){
        int l=resp+1,r=min(i,n-i-1),mid;
        if(i-(resp+1)>=0&&i+(resp+1)<n&&get_hash(i,i+(resp + 1),1)==get_hash(n-i-1,n-1-i+resp+1,0)){
            while(l<=r){
                mid=(l+r)/2;
                if(get_hash(i,i+mid,1)==get_hash(n-i-1,n-i-1+mid,0)){
                    l=mid+1;
                    if(mid>resp){
                        lresp=i-mid;
                        rresp=i+mid;
                        resp=mid;
                    }
                }
                else r=mid-1;
            }
        }
        l=resp,r=min(i,n-i-2);
        if(i-resp>=0&&i+1+resp<n&&get_hash(i+1,i+1+resp,1)==get_hash(n-i-1,n-i-1+resp,0)){   
            while(l<=r){
                mid=(l+r)/2;
                if(get_hash(i+1,i+mid+1,1)==get_hash(n-i-1,n-i-1+mid,0)){
                    l=mid+1;
                    if(mid>=resp){
                        lresp=i-mid;
                        rresp=i+mid+1;
                        resp=mid;
                    }
                }
                else r=mid-1;
            }
        }
    }
    for(i=lresp;i<=rresp;i++){
        cout<<s[i];
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
