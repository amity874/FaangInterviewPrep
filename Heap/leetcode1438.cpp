// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mindq;
        deque<int>maxdq;
        int ans=INT_MIN;
        int s=0;
        int e=0;
        int n=nums.size();
        while(e<n){
            int x=nums[e];
            while(not mindq.empty() && nums[mindq.back()]>=x){
                mindq.pop_back();
            }
            mindq.push_back(e);
            while(not maxdq.empty() && nums[maxdq.back()]<=x){
                maxdq.pop_back();
            }
            maxdq.push_back(e);
            if(nums[maxdq.front()]-nums[mindq.front()]>limit){
                s++;
                if(s>mindq.front()) mindq.pop_front();
                if(s>maxdq.front()) maxdq.pop_front();
            }
            else{
                int len=(e-s)+1;
                ans=max(ans,len);
                e++;
            }
            
        }
        
        return ans;
    }
};