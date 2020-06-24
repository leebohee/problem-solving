class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        mset.insert(num);
        if(mset.size() == 1){
            mid = mset.begin();
        }
        else{
            if(mset.size() % 2 == 0){
                if(*mid <= num) mid++;
            }
            else{
                if(*mid > num) mid--;
            }
        }
    }
    
    double findMedian() {
        double median = *mid;
        if(mset.size() % 2 == 0){
            median += *prev(mid, 1);
            median /= 2;
        }
        return median;
    }
private:
    multiset<int> mset;
    multiset<int>::iterator mid;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
