class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projectDetails;
        projectDetails.reserve(n); // Pre-allocate memory for performance - optional
        
        for (int i = 0; i < n; i++) {
            projectDetails.push_back({capital[i], profits[i]});
        }
        
        // Sort projectDetails by required capital ascending
        sort(projectDetails.begin(), projectDetails.end());
        
        priority_queue<int> max_profit_pq;
        int i = 0;
        
        while (k--) {
            // Add all affordable projectDetails to the max-heap
            while (i < n && projectDetails[i].first <= w) {
                max_profit_pq.push(projectDetails[i].second);
                i++;
            }
            
            // If no projectDetails can be funded, stop early
            if (max_profit_pq.empty()) break;
            
            // Take the project with the highest profit
            w += max_profit_pq.top();
            max_profit_pq.pop();
        }
        
        return w;
    }
};
