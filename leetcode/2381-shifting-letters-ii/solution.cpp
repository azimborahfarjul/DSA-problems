class Solution {
public:

    char shift(char ch, int k){
        return (((ch-'a'+k)%26+26))%26 + 'a'; 
    }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> v(n+1, 0);
        for(auto i : shifts){
            int a = i[0], b = i[1], c = i[2];
            if(c == 1){
                v[a]++;
                v[b+1]--;
            }else{
                v[a]--;
                v[b+1]++; 
            }
        }
        for(int i = 1; i<n; ++i){
            v[i] += v[i-1];
        }
        string ans = "";
        int k = 0;
        for(auto i : s){
            ans += shift(i, v[k]);
            k++;
        }
        return ans; 

    }
};