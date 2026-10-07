class Solution {
public:
    struct SparseTable {
        int n,K;
        vector<vector<pair<int,int>>>st;
        inline pair<int,int> f( pair<int,int> l, pair<int,int> r) { return min(l,r);}

        SparseTable(const vector<int> &a){
            n=a.size();
            K = __lg(n) + 1;
            st.assign(K, vector<pair<int,int>>(n));

            for(int i=0;i<n;i++) st[0][i]={a[i],i};

            for(int i=1;i < K;i++){
                for(int j=0;j + (1<<i) <=n;j++){
                    st[i][j]=f(st[i-1][j],st[i-1][j+(1<<(i-1))]);
                }
            }
        }
        pair<int,int> query(int L,int R){
            int k = __lg(R-L+1);
            return f(st[k][L],st[k][R-(1<<k)+1]);
        }

        int solve(int L, int R, const vector<int>& heights) {
            if(L>R)return 0;
            
            int mini=query(L,R).second;
            int at=heights[mini]*(R-L+1);
            
            int l = solve(L,mini-1,heights);
            int r = solve(mini+1,R,heights);
            
            return max({at,l,r});
        }
    };

    int largestRectangleArea(vector<int>& heights) {
        SparseTable st(heights);

        return st.solve(0,heights.size()-1,heights);
    }
};
