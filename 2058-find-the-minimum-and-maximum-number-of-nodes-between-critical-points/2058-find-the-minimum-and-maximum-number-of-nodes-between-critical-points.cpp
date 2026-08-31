/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int first_cp = -1;
        int prev_cp = -1;
        int min_dist = INT_MAX;
        
        ListNode* prev=head;
        ListNode* temp=head->next;
        int i=1;
        while(temp->next){
            int tv=temp->val;
            int tnv=temp->next->val;
            int pv=prev->val;
            if((tv>pv && tv>tnv) || (tv<pv && tv<tnv)){
                if (first_cp==-1) {
                    first_cp = i; // Record the first critical point
                } else {
                    min_dist = min(min_dist, i - prev_cp); // Update the running minimum distance
                }
                prev_cp = i; // Update the previous critical point tracker
            }
            i++;
            prev=temp;
            temp=temp->next;
        }
        
        if(first_cp == prev_cp) return {-1,-1};
        int max_dist = prev_cp - first_cp;
        return {min_dist, max_dist};
    }
};