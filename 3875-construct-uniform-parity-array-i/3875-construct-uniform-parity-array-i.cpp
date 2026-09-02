class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oc=0,ec=0;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]%2==0){
                ec++;
            }else{
                oc++;
            }
        }
        bool canalle=false;
        if(oc==0 || oc>=2){
            canalle=true;
        }

        bool canallo=false;
        if(ec==0 || oc>=1){
            canallo=true;
        }

        if(canalle || canallo) return true;
        else return false;
        
    }
};