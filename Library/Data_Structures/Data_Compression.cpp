void compress(vi& a) {
    vi b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    
    for (int& x : a) 
        x = lower_bound(all(b), x) - b.begin(); 
}
