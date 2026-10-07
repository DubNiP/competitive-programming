class RecentCounter {
public:
    deque<int>val;
    RecentCounter() {
    }
    
    int ping(int t) {
        while(val.size()>0&&val[0]+3000<t)val.pop_front();
        val.push_back(t);
        return val.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
