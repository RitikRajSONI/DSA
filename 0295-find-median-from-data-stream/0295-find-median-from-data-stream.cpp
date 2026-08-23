class MedianFinder {
public:
    // Max-heap for the lower half of numbers
    priority_queue<int, vector<int>> lmxh; 
    // Min-heap for the upper half of numbers
    priority_queue<int, vector<int>, greater<int>> rmnh; 

    MedianFinder() { }
    
    void addNum(int num) {
        // Step 1: Add to the appropriate heap
        if (lmxh.empty() || num <= lmxh.top()) {
            lmxh.push(num);
        } else {
            rmnh.push(num);
        }
        
        // Step 2: Balance the heaps so lmxh can only have equal 
        // or exactly 1 more element than rmnh
        if (lmxh.size() > rmnh.size() + 1) {
            rmnh.push(lmxh.top());
            lmxh.pop();
        } else if (rmnh.size() > lmxh.size()) {
            lmxh.push(rmnh.top());
            rmnh.pop();
        }
    }
    
    double findMedian() {
        // If even number of elements, take the average of both tops
        if (lmxh.size() == rmnh.size()) {
            return (lmxh.top() + rmnh.top()) / 2.0; 
        }
        // If odd, lmxh always holds the extra middle element
        return lmxh.top();
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */