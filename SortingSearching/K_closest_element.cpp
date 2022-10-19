class Solution {
public:
int binary_Search(vector<int> &arr,int x){
    int lo=0;
    int hi=arr.size()-1;
    int ans=0;
    int mid=0;
    while(lo<=hi){
         mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
            break;
        }
        if(arr[mid]<x){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return mid;
}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int idx=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        int lo=idx-1;
        int hi=idx;
        std::vector<int> ans;
        while(lo>=0 && hi<n && k>0){
            int x1=abs(arr[lo]-x);
            int y1=abs(arr[hi]-x);
            if(x1<=y1){
                ans.push_back(arr[lo]);
                lo--;
            }
            else{
                ans.push_back(arr[hi]);
                hi++;
            }
            k--;
        } 
        while(k>0 && lo>=0){
            ans.push_back(arr[lo]);
            lo--;
            k--;
        }
        while(k>0 && hi<n){
            ans.push_back(arr[hi]);
            hi++;
            k--;
        }
        std::sort(ans.begin(),ans.end());
        return ans;
    }
};