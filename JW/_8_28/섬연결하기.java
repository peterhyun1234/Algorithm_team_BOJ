package JW._8_28;

import java.util.ArrayList;

public class º∂ø¨∞·«œ±‚ {

	static int n = 4;
	static int[][] costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(n, costs));

	}
	
	public static int solution(int n, int[][] costs) {
        int answer = 0;
        boolean[] visited = new boolean[n];
        
        ArrayList<ArrayList<Pair>> list = new ArrayList<ArrayList<Pair>>();
        
        for(int i=0;i<n;i++) {
        	list.add(new ArrayList<Pair>());
        }
        
        for(int i=0;i<costs.length;i++) {
        	int s = costs[i][0];
        	int e = costs[i][1];
        	int cost = costs[i][2];
        	
        	list.get(s).add(new Pair(e, cost));
        	list.get(e).add(new Pair(s, cost));
        }
        
        visited[0] = true;
        
        for(int i=0;i<n-1;i++) {
        	
        	int e = -1;
        	int cost = Integer.MAX_VALUE;
        	for(int j=0;j<n;j++) {
        		if(visited[j]) {
        			for(int k=0;k<list.get(j).size();k++) {
        				Pair p = list.get(j).get(k);
        				if(visited[p.e] == false && p.cost < cost) {
        					e = p.e;
        					cost = p.cost;
        				}
        			}
        		}
        	}
        	
        	visited[e] = true;
        	answer += cost;
        }
        
        return answer;
    }

	public static class Pair{
		int e, cost;
		Pair(int e, int cost){
			this.e = e;
			this.cost = cost;
		}
	}
}
