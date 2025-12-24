class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxheap;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int d= x*x + y*y;
            maxheap.push({d, i});
            if(maxheap.size()>k)maxheap.pop();
        }
        vector<vector<int>> res;
        while(!maxheap.empty()){
            res.push_back(points[maxheap.top().second]);
            maxheap.pop();
        }
        return res;
    }
};