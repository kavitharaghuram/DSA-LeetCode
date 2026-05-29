class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccur (26, 0);
        for(int i=0; i<s.size(); i++){
            lastOccur[s[i]-'a']=i;
        }
        vector<int>res;
        int start=0;
        int end=0;
        for(int i=0; i<s.size(); i++){
            int last= lastOccur[s[i]-'a'];
            end=max(end, last);
            if(i==end){
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
};