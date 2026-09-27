class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> opened;
        unordered_map<int, int> pair;
        
        // Step 1: Pair up the matching parentheses
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                opened.push_back(i);
            } else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        // Step 2: Traverse and build the result string
        string result = "";
        int direction = 1; // 1 means moving right, -1 means moving left
        
        for (int i = 0; i < s.length(); i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];       // Teleport to the matching parenthesis
                direction = -direction; // Reverse the direction
            } else {
                result += s[i];    // Append normal characters
            }
        }
        
        return result;
    }
};
