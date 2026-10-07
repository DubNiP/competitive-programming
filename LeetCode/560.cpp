class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0]=1; 
        
        int soma=0;
        int cont=0;
        
        for (auto w : nums) {
            soma+=w;
            int aux=soma-k;
            if (m.find(aux)!=m.end()){
                cont+=m[aux];
            }
            m[soma]++;
        }
        
        return cont;
    }
};
