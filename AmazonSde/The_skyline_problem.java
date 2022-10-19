class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<Pair> list=new ArraList<>();
        int n=buildings.length();
        for(int i=0;i<n;i++){
        	int st=buildings[i][0];
        	int en=buildings[i][1];
        	int ht=buildings[i][2];
        	list.add(new Pair(st,-ht));
        	list.add(new Pair(en,ht));
        }
        Collections.sort(list);
        List<List<Integer>> ans=new ArraList<>();
        PriorityQueue<Integer> pq=new PriorityQueue<Integer>(Collections.reverseOrder);
        int curr=0;
        for(int i=0;i<n;i++){
        	int x=list.get(i).x;
        	int ht=list.get(i).ht;
        	if(ht<0){
        		pq.add(-ht);
        	}
        	else{
        		pq.remove(ht);
        	}
        	if(curr!=pq.peek()){
        		List<Integer> temp=new ArraList<>();
        		temp.add(x);
        		temp.add(pq.peek());
        		ans.add(temp);
        		curr=pq.peek();
        	}
        }
        return ans;
    }
}
public class Pair implements Comparable<Pair>{
	int x;
	int ht;
	public Pair(int x,int ht){
		this.x=x;
		this.ht=ht;
	}
	@Override
	public int compareTo(Pair o){
		if(this.x!=o.x){
			this.x-o.x;
		}
		else{
			this.ht-o.ht;
		}
	}
}