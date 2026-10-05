class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int sz=seq.size();
        vector<int>v(sz);
        int open=0;
        for(int i=0;i<sz;i++){
            if(seq[i]=='('){
                v[i]=open&1;
                open++;
            }
            else{
                open--;
                v[i]=open&1;
            }
        }
        return v;
    }
};