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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy;
        ListNode* curr = &dummy;
        ListNode* temp = l1;
        ListNode* temp2 = l2;
        while(temp!=NULL && temp2!=NULL){
            if(temp->val<=temp2->val){
                curr->next = temp;
                temp = temp->next;
            }else{
                curr->next = temp2;
                temp2 = temp2->next;
            }
            curr = curr->next;
        }
        if(temp){
            curr->next = temp;
        }
        if(temp2){
            curr->next = temp2;
        }
        return dummy.next;
    }

    ListNode* DivideAndMerge(int start,int end, vector<ListNode*> lists){
        if(start>end) return NULL;
        if(start==end) return lists[start];
        int m = start + (end-start)/2;
        ListNode* l1= DivideAndMerge(start,m,lists);
        ListNode* l2= DivideAndMerge(m+1,end,lists);

        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int start=0,end=lists.size();
        if(end==0) return NULL;
        return DivideAndMerge(start,end-1,lists);
    }
};