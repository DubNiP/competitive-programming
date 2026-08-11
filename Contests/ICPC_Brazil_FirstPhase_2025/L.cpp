#include <bits/stdc++.h>
#define int ll
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
    int n,i; cin>>n;
    vector<tuple<string,int,int>>dicionario(n);
    for(i=0;i<n;i++){
        string s; int x;int y; cin>>s>>x>>y;
        auto t = make_tuple(s,x,y);
        dicionario[i]=t;
    }


    int m; cin>>m;
    vector<string>seq(m);
    for(i=0;i<m;i++) cin>>seq[i];
   

    int q,k; cin>>q>>k;
    while(q--){
        int t; cin>>t; 
        vector<string>window; vector<string>frase(t);
        for(i=0;i<t;i++){
            cin>>frase[i];
            if(i>=t-k) window.pb(frase[i]);
        }

        int xtot=0,ytot=0;
        bool found=false;
        int reps=0;
        while(reps<k&&!found){
            for(i=0;i<m-k+reps;i++){
                bool ok=true;
                for(int j=0;j<k-reps;j++){
                    if(window[j+reps]!=seq[i+j]){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    found = true;
                    for(int j=0;j<n;j++){
                        if(seq[i+k-reps]==get<0>(dicionario[j])){
                            xtot+=get<1>(dicionario[j]);
                            ytot+=get<2>(dicionario[j]);
                        }
                    }
                }
            }
            reps++;
        }

        if(found==false){
            for(auto w : frase) cout<<w<<" ";
            cout<<"*\n";
            continue;
        }


        int pointsmax=-1e18;
        string resp;

        for(i=0;i<n;i++){
            int points=xtot*get<1>(dicionario[i])+ytot*get<2>(dicionario[i]);
            if(points>pointsmax){
                resp=get<0>(dicionario[i]);
                pointsmax=points;
            }
        }
        for(auto w : frase) cout<<w<<" ";
        if(resp.size()==0) cout<<"*\n";
        else cout<<resp<<"\n";
      
    }


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
