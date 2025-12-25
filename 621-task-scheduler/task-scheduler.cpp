class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count (26, 0);
        for (char task: tasks){
            count[task-'A']++;
        }
        priority_queue<int>maxheap;
        for(int c : count){
            if(c>0)maxheap.push(c);
        }
        queue<pair<int, int>> q;
        int time=0;
        while(!maxheap.empty()|| !q.empty()){
            time++;
            if(maxheap.empty()){
                time= q.front().second;
            }
            else{
                int c= maxheap.top()-1;
                maxheap.pop();
                if(c>0)q.push({c, time+n});
            }
            if(!q.empty() && q.front().second==time){
                maxheap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};