// https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems/

class Solution {
public:
    long long colosseum(int N, vector<int> a) {

      vector<long long> L(N * 3 + 1), R(N * 3 + 1); // create 
      for (int i = 0; i <= 3 * N; ++i) {
         L[i] = -1e18, R[i] = 1e18;
      }
      priority_queue<long long, vector<long long>, greater<long long> > minHeap;
      long long sum = 0;
      for(int i=0;i<3*N;i++){
      	sum+=a[i];
      	minHeap.push(a[i]);
      	if(minHeap.size()>N){
      		sum-=minHeap.top();
      		minHeap.pop();
      	}
      	if(minHeap.size()==N){
      		L[i]=sum;
      	}
      }
      priority_queue<long long> maxHeap;
      sum = 0;
      for(int j=3*N-1;j>=0;j--){
      	sum+=a[j];
      	maxHeap.push(a[j]);
      	if(maxHeap.size()>N){
      		sum-=maxHeap.top();
      		maxHeap.pop();
      	}
      	if(maxHeap.size()==N){
      		R[j]=sum;
      	}
      }
       long long ans = -1e18;
      for (int a = 0; a <3 * N; ++a) {
         ans=max(ans,L[a] - R[a+1]);
      }
      return ans;
  }
};