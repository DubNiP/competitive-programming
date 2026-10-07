class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>v(26);
        int resp=-1;
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']==0)v[s[i]-'a']=1;
            else v[s[i]-'a']=-1;
        }
        for(auto w : v){
            if(w>-1){
                resp=1e9;
                resp=min(resp,w);
            }
        }
        return resp;
    }
};
