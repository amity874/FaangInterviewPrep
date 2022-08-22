class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxHeap;
        for(auto &it:points){
            int x1=it[0];
            int y1=it[1];
            int euclidDist=((x1*x1)+(y1*y1));
            maxHeap.push({euclidDist,x1,y1});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
           vector<int> tp=maxHeap.top();
            ans.push_back({tp[1],tp[2]});
            maxHeap.pop();
        }
        return ans;
    }
};