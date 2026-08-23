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
using ii = pair<int, int>;
using vvi = vector<vi>;

const int INF = 2e18;
const int MOD = 1e9+7;

vector<string> vs; 
vector<vector<string>> ans;

// 0
// 10
// 10000 -> 10^4
// 12340000 -> 1234*10^4


// eh numero?
// eh o primeiro numero que encontrei?
// tem algo que nao seja numero adjancete a esses numeros?
// 12300000RA
// RA12300000 
// PRA SER UM NUMERO, antes do primeiro e depois do ultimo precisa ser ' ', '\n', (i=0)    {} 12(3)

bool is_number(char ch){
    if(ch>='0' && ch<='9'){
        return true;
    }
    return false;
}

bool is_letter(char ch){
    if(ch>='a' && ch<='z'){
        return true;
    }
    if(ch>='A' && ch<='Z'){
        return true;
    }

    return false;
}

vector<string> sanitize(string vstr){
    vector<string> vstemp;
    string temp;

    // ' ' -> 123456435 

    // a- <- push back
    // -a <- push back
    // --
    for(int i=0; i<sz(vstr); i++){
        if(i == sz(vstr)-1){
            temp+=vstr[i];
            vstemp.push_back(temp);
            temp = "";
        }
        else if(i>0 && vstr[i-1]==' ' && vstr[i]!=' '){
            vstemp.push_back(temp);
            temp = "";
        }
        else if(i>0 && vstr[i-1]!=' ' && vstr[i]==' '){
            vstemp.push_back(temp);
            temp = "";
        }
        temp += vstr[i];
        
    }

    return vstemp;
}

string clean(string &v){
    for(auto w : v) if(!is_number(w)) return v;
    int cont=0;
    if(v[0]=='1'){
        for(int i=1;i<sz(v);i++){
            if(v[i]!='0') break;
            cont++;
            if(i==sz(v)-1&&cont>=4){
                return "10^{"+to_string(cont)+"}";
            }
        }
    }
    cont=0; int j=-1;
    for(int i=sz(v)-1;i>=0;i--){
        if(v[i]!='0'){
            j=i;
            break;
        } 
        cont++;
    }
    if(cont>=4){
        string s="";
        for(int i=j;i>=0;i--){
            if(i==0&&j!=0) s+='.';
            else if(j!=0) cont++;
            s+=v[i];
        }
        reverse(all(s));
        return s+"\\cdot10^{"+to_string(cont)+"}";
    }
    return v;

}

void solve(){
    int n;
    cin >> n;

    // input
    for(int i=0; i<n+1; i++){
        string s;
        getline(cin, s);
        vs.push_back(s);
    }

    // sanitize
    ans = vector<vector<string>>(n);
    for(int i=1; i<n+1; i++){
        ans[i-1] = sanitize(vs[i]);
    }

    // cleaning
    for(int i=0; i<n; i++){
        for(int j=0;j<sz(ans[i]);j++){
            ans[i][j] = clean(ans[i][j]);
        }
    }

    // output
    for(int i=0; i<n; i++){
        for(int j=0;j<sz(ans[i]);j++){
            cout << ans[i][j];
        }
        cout<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

