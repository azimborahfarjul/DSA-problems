class Solution {
public:
    int n; 
    int dp[101][101]; 
    bool solve(int i, string s, int ct){
        if(ct < 0){
            return false;
        }
        if(i == n){
            return ct == 0;
        }
        if(dp[i][ct] != -1){
            return dp[i][ct]; 
        }
        bool ans = false;
        if(s[i] == '*'){
            ans = ans | solve(i+1, s, ct) | solve(i+1, s, ct+1) | solve(i+1, s, ct-1);
        }else if(s[i] == ')'){
            ans = ans | solve(i+1, s, ct-1);
        }else{
            ans = ans | solve(i+1, s , ct+1);
        }
        return dp[i][ct] = ans; 

    }
    bool checkValidString(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp)); 
        return solve(0, s, 0);
    }
};