class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    unordered_map<int,bool> mp;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++){
            minheap.push(i);
            mp[i]=true;
        }
    }
    
    int popSmallest() {
        int ans=minheap.top(); 
        minheap.pop();
        mp[ans]=false;
        return ans;
    }
    
    void addBack(int num) {
        if(mp[num]) return;
        minheap.push(num);
        mp[num]=true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */