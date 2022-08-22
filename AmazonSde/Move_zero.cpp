class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        if(nums.size()==1){
            return {nums[0]};
        }
        if(nums.size()==0){
            return {};
        }
        int s=0;
        int e=s+1;
        while(s<e && e<nums.size()){
            if(abs(nums[s])>=1 && abs(nums[e])>=1){
                s+=2;
                e+=2;
            }
            else if(abs(nums[s])==0 && abs(nums[e])>=1){
                swap(nums[s],nums[e]);
                s+=1;
                e+=1;
            }
            else if(abs(nums[s])==0 && abs(nums[e])==0){
                e+=1;
            }
            else{
                e+=1;
                s+=1;
            }
        }
        return nums;
    }
};