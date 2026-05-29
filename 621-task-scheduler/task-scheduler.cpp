class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(char task: tasks){
            count[task-'A']++;
        }
        int maxFreq= *max_element(count.begin(), count.end());
        int maxCount=0;
        for(int cn: count){
            if (cn==maxFreq){
                maxCount++;
            }
        }
        return max((int)tasks.size(), ((n+1)*(maxFreq-1)+maxCount));
    }
};