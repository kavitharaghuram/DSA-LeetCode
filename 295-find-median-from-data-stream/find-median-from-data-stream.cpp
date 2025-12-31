class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallheap;
    priority_queue<int, vector<int>, greater<int>> largeheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallheap.push(num);
        if(!largeheap.empty()&& smallheap.top()>largeheap.top()){
            largeheap.push(smallheap.top());
            smallheap.pop();
        }
        if(smallheap.size()>largeheap.size()+1){
            largeheap.push(smallheap.top());
            smallheap.pop();
        }
        if(largeheap.size()>smallheap.size()+1){
            smallheap.push(largeheap.top());
            largeheap.pop();
        }
    }
    
    double findMedian() {
        if(smallheap.size()==largeheap.size()){
            return (smallheap.top()+largeheap.top())/2.0;
        }
        else if(smallheap.size()>largeheap.size()){
            return smallheap.top();
        }
        else return largeheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */