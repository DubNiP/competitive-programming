class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>v1(26),v2(26);
        for(auto w : s) v1[w-'a']++;
        for(auto w : t) v2[w-'a']++;
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};
