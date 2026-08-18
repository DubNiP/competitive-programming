// NAO TESTADO E CONHECIMENTO BAIXO
vi get_pi(const string& s) {
    int n = sz(s);
    vi p(n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) p[i] = ++j;
    }
    return p;
}

vi kmp_search(const string& txt, const string& pat) {
    int n = sz(txt), m = sz(pat);
    if (m == 0) return {};
    
    vi p = get_pi(pat), ans;
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && txt[i] != pat[j]) j = p[j - 1];
        if (txt[i] == pat[j]) j++;
        if (j == m) {
            ans.pb(i - m + 1);
            j = p[j - 1];      
        }
    }
    return ans;
}

vi find_borders(const string& s) {
    vi p = get_pi(s), ans;
    int i = p.back();
    
    while (i > 0) {
        ans.pb(i);
        i = p[i - 1];
    }
    reverse(all(ans));
    return ans;
}
