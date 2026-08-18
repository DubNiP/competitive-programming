mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int get_rand_base(int mod) {
    int b = uniform_int_distribution<int>(300, mod - 1)(rng);
    return b % 2 == 0 ? b - 1 : b;
}

const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int BASE1 = get_rand_base(MOD1);
const int BASE2 = get_rand_base(MOD2);

struct DoubleHash {
    vector<int> h1, h2, p1, p2;

    DoubleHash(const string& s) {
        int n = s.size();
        h1.assign(n + 1, 0); h2.assign(n + 1, 0);
        p1.assign(n + 1, 1); p2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + s[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + s[i]) % MOD2;
            
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }
    }

    pair<int, int> get(int l, int r) {
        int len = r - l + 1;
        
        int val1 = (h1[r + 1] - (h1[l] * p1[len]) % MOD1 + MOD1) % MOD1;
        int val2 = (h2[r + 1] - (h2[l] * p2[len]) % MOD2 + MOD2) % MOD2;
        
        return {val1, val2};
    }
};
