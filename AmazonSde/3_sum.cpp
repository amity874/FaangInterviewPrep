class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
        int lo=i+1,hi=n-1,sum=0-nums[i];
            if(i==0 or (i>0 && nums[i]!=nums[i-1])){
                while(lo<hi){
                    if(nums[lo]+nums[hi]==(sum)){
                        ans.push_back({nums[i],nums[lo],nums[hi]});
                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                        lo+=1;
                        hi-=1;
                    }
                    else if(nums[lo]+nums[hi]<(sum)){
                        lo++;
                    }
                    else{
                        hi--;
                    }
                }
            }
        }
        return ans;
    }
};