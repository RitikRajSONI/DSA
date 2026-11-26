class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        bool aw = false;
        int x=10;
        while(n>=x){
            n-=x;
            aw=!aw;
            x--;
        }

        return aw;
    }
};