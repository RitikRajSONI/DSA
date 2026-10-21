class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int a = 1, b = 2;

        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=2) return n;
//         vector<int> t(n+1);
//         t[0]=0,t[1]=1,t[2]=2;
//         for(int i=3; i<=n; i++){
//             t[i]=t[i-1]+t[i-2];
//         }
//         return t[n];
//     }
// };


// class Solution {
// public:
//     vector<int> t;
//     int solve(int n){
//         if(n<0) return 0;
//         if(n==0) return 1;
//         if(t[n]!=-1) return t[n];
//         int oneStep=solve(n-1);
//         int twoStep=solve(n-2);

//         return t[n] = oneStep+twoStep;
//     } 
//     int climbStairs(int n) {
//         t.resize(n+1,-1);
//         return solve(n);
//     }   
// };


// class Solution {
// public:
//     int solve(int n){
//         if(n<0) return 0;
//         if(n==0) return 1;

//         int oneStep=solve(n-1);
//         int twoStep=solve(n-2);

//         return oneStep+twoStep;
//     } 
//     int climbStairs(int n) {
//         return solve(n);
//     }   
// };