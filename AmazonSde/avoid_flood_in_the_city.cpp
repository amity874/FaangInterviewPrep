class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        std::unordered_map<int,int> mp;
        std:set<int> st;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                st.insert(i);
            }
            else{
                if(mp.find(rains[i])!=mp.end()){
                    auto idx=st.upper_bound(mp[rains[i]]);
                    if(idx!=st.end()){
                      ans[*idx]=rains[i];
                     st.erase(*idx);
                    }else{
                         return {};
                    }
                }
                mp[rains[i]]=i;
                ans[i]=-1;
            }
        }
        return ans;
    }
};