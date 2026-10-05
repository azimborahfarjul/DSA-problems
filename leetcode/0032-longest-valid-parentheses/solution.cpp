class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int ans = 0;
        for(auto i : s){
            if(i == '('){
                left++;
            }else{
                right++;
            }
            if(left == right){
                ans = max(ans, 2*left);
            }else if(right > left){
                left = 0, right = 0;
            }
        }
        left = 0, right = 0;
        int n = s.size();
        for(int i = n-1; i>=0; --i){
            if(s[i] == '('){
                left++;
            }else{
                right++;
            }
            if(left == right){
                ans = max(ans, 2*left);
            }else if(right < left){
                left = 0, right = 0;
            }
        }
        return ans;
    }
};