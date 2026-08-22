class Solution {
public:
    typedef pair<int,int> Pair; 
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // Add original index to each task to preserve it after sorting
        for(int i = 0; i < n; i++){
            tasks[i].push_back(i);
        }
        
        // Sort tasks by enqueueTime
        sort(tasks.begin(), tasks.end());

        // Min-heap stores pairs of {processingTime, originalIndex}
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        vector<int> result;
        
        long long completion_time = 0;
        int i = 0;
        
        while(i < n || !pq.empty()){
            // If CPU is idle and next task arrives in the future, jump time forward
            if(pq.empty() && completion_time < tasks[i][0]){
                completion_time = tasks[i][0];
            }
            
            // Push all tasks that have arrived by the current completion_time
            while(i < n && tasks[i][0] <= completion_time){
                pq.push({tasks[i][1], tasks[i][2]}); // {processingTime, originalIndex}
                i++;
            }
            
            // Process the task with the shortest processing time (or smallest index)
            Pair cur_task = pq.top(); 
            pq.pop();
            
            completion_time += cur_task.first;
            result.push_back(cur_task.second);
        }
        return result;
    }
};
