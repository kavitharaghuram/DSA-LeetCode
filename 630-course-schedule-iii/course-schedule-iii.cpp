class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
        [](auto &a, auto &b){
            return a[1]<b[1];
        });
        priority_queue<int>maxHeap;
        int time=0;
        for(auto& c: courses){
            int duration= c[0];
            int lastday= c[1];
            time+=duration;
            maxHeap.push(duration);
            if(time>lastday){
                time-=maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};