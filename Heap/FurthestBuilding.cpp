class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
        std::priority_queue<int> pq;
        int i=0;
        for(i;i<heights.size()-1;i++){
            if(heights[i+1]<=heights[i]){
                continue;
            }
            int jump=heights[i+1]-heights[i];
            if(jump<=b){
                b-=jump;
                pq.push(jump);
            }
            else{
                if(l>0){
                    if(not pq.empty()){
                        int mx_jump=pq.top();
                        if(mx_jump>jump){
                        b+=mx_jump;
                        pq.pop();
                        b-=jump;
                        pq.push(jump);
                        }
                    }
                    l--;
                }
                else{
                    break;
                }
            }
        }
        return i;
    }
};