package JW._8_28;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class 가장먼노드 {

	static int n = 6;
	static int[][] edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(n, edge));

	}
	public static int solution(int n, int[][] edge) {
        int answer = 0;
        int[] dist = new int[n+1];
        int max = 0;
        boolean[] visited = new boolean[n+1];
        
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        PriorityQueue<Pair> q = new PriorityQueue<Pair>();
        
        for(int i=0;i<=n;i++) {
        	list.add(new ArrayList<Integer>());
        }
        
        for(int i=0;i<edge.length;i++) {
        	int a = edge[i][0];
        	int b = edge[i][1];
        	
        	list.get(a).add(b);
        	list.get(b).add(a);
        }
        
        for(int i=0;i<=n;i++) {
        	dist[i] = Integer.MAX_VALUE;
        }
        dist[1] = 0;
        
        q.add(new Pair(1, 0));
        
        while(!q.isEmpty()) {
        	Pair p = q.poll();
        	int tmpn = p.n;
        	int tmpdist = p.dist;
        	
        	
        	for(int i=0;i<list.get(tmpn).size();i++) {
        		int linknode = list.get(tmpn).get(i);
        		if(visited[linknode] == false && dist[linknode] > dist[tmpn] + 1) {
        			dist[linknode] = dist[tmpn] + 1;
        			q.add(new Pair(linknode, dist[linknode]));
        		}
        	}
        	
        	visited[tmpn] = true;
        	max = Math.max(max, dist[tmpn]);
        }
        
        for(int i=1;i<=n;i++) {
        	if(max == dist[i])
        		answer++;
        }
        return answer;
    }
	
	public static class Pair implements Comparable<Pair>{
		int n, dist;
		Pair(int n, int dist){
			this.n = n;
			this.dist= dist;
		}
		@Override
		public int compareTo(Pair o) {
			// TODO Auto-generated method stub
			return this.dist - o.dist;
		}
	}

}
