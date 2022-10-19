class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int n1=nums1.size();
    	int n2=nums2.size();
        if(n2<n1){
            return findMedianSortedArrays(nums2,nums1);
        }
        int lo=0;
        int hi=n1;
        double ans=0.0;
        while(lo<=hi){
        	int cut1=lo+(hi-lo)/2;//cur for nums1
        	int cut2=((n1+n2+1)/2) -cut1;//cut for remaining lenght for left half
        	int l1=(cut1>=1)?nums1[cut1-1]:INT_MIN;
        	int l2=(cut2>=1)?nums2[cut2-1]:INT_MIN;
            
            
        	int r1=(cut1<n1)?nums1[cut1]:INT_MAX;
        	int r2=(cut2<n2)?nums2[cut2]:INT_MAX;
        	if(l1<=r2 && l2<=r1){
        		if((n1+n2)%2==0){
        			ans=(max(l1,l2)+min(r1,r2))/2.0;
        			return ans;
        		}
        		else{
        			ans=max(l1,l2);
        			return ans;
        		}
        	}
        	else if(l1>r2){
        		hi=cut1-1;
        	}
        	else if(l2>r1){
        		lo=cut1+1;
        	}
        }
        return 0.0;
    }
}; 