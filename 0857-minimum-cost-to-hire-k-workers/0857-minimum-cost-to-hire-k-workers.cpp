class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n=min_wage.size();
        double result=DBL_MAX;

        vector<pair<double,int>> workerRatio(n);
        for(int w=0; w<n; w++){
            workerRatio[w]=make_pair((double)min_wage[w]/quality[w], quality[w]);
        }
        sort(workerRatio.begin(),workerRatio.end());

        priority_queue<int> pq;
        int sum_quality=0;
        for(int i=0; i<k; i++){
            pq.push(workerRatio[i].second);
            sum_quality+=workerRatio[i].second;
        }
        
        double managerRatio=workerRatio[k-1].first;
        result=managerRatio*sum_quality;
        for(int m=k; m<n; m++){
            double managerRatio=workerRatio[m].first;
            pq.push(workerRatio[m].second);
            sum_quality += workerRatio[m].second;

            sum_quality-=pq.top();
            pq.pop();

            result=min(result,managerRatio*sum_quality);
        }        
        return result;
    }
};