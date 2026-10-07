class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>m;
        for(auto w : strs){
            vector<int>freq(26,0);
            for(auto x : w) freq[x-'a']++;
            m[freq].push_back(w);
        }
        vector<vector<string>> resp;
    
        for(auto [a,b] : m) resp.push_back(b);
        return resp;
    }
};
