class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0, res = 0;
        for(int i = 0; i<n; ++i){
            if(s[i] == '('){
                ans++;    
            }else if(s[i] == ')'){
                ans--;
            }
            res = max(ans, res);
        }
        res = max(ans, res);
        return res;
    }
};