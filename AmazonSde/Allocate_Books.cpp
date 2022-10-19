bool isPossible(vector<int> &A, int B,int mid){
    int  s=1;
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum>mid){
            sum=A[i];
            s+=1;
        }
        if(s>B){
            return false;
        }
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    if(A.size()<B){
        return -1;
    }
    int lo=*max_element(A.begin(),A.end());
    int hi=0;
    for(auto &it:A){
        hi+=it;
    }
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(isPossible(A,B,mid)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
