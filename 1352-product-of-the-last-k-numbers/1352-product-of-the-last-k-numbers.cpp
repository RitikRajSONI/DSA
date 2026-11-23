class ProductOfNumbers {
public:
    vector<int> prefix;

    ProductOfNumbers() {
        // Initialize with 1 to handle k == total elements cleanly
        prefix = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset prefix products because any product including this 0 is 0
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        // If k >= n, a 0 was added within the last k elements
        if (k >= n) {
            return 0;
        }
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */