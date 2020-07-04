class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // check intersect
        int n = intersect.size();
        for(int i=0; i<n; i++){
            if(end <= intersect[i].first) continue;
            if(start >= intersect[i].second) continue;
            return false;
        }
        
        // add to ranges
        n = ranges.size();
        for(int i=0; i<n; i++){
            if(end <= ranges[i].first) continue;
            if(start >= ranges[i].second) continue;
            intersect.emplace_back(max(start, ranges[i].first), min(end, ranges[i].second));
        }
        ranges.emplace_back(start, end);
        return true;
    }
private:
    vector<pair<int, int> > ranges;
    vector<pair<int, int> > intersect;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */