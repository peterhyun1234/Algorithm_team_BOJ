package JW._8_07;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class _1916 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//최소 dist 찾기
		PriorityQueue<Pair> q = new PriorityQueue<Pair>();
		
		ArrayList<ArrayList<Bus>> list = new ArrayList();
		
		int N, M;
		int startnum, endnum;
		int[] costArray;
		boolean[] visited;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		costArray = new int[N+1];
		visited = new boolean[N+1];
		
		Arrays.fill(costArray, Integer.MAX_VALUE);
		
		for(int i=0;i<=N;i++) {
			list.add(new ArrayList<Bus>());
		}
		for(int i =0;i<M;i++) {
			int start = s.nextInt();
			int arrive = s.nextInt();
			int cost = s.nextInt();
			
			list.get(start).add(new Bus(start, arrive, cost));
		}
		startnum = s.nextInt();
		endnum = s.nextInt();
		
		costArray[startnum] = 0;
		
		q.add(new Pair(startnum, costArray[startnum]));
		
		while(!q.isEmpty()) {
			Pair pair = q.poll();
			int node = pair.node;
			int cost = pair.cost;
			
			for(int i =0;i<list.get(node).size();i++) {
				Bus bus = list.get(node).get(i);
				int tmpcost = bus.cost;
				int tmparrive = bus.arrive;
				
				if(visited[tmparrive] == false && costArray[tmparrive] > costArray[node] + tmpcost) {
					costArray[tmparrive] = costArray[node] + tmpcost;
					q.add(new Pair(tmparrive, costArray[tmparrive]));
				}
			}
			
			visited[node] = true;
		}
		
		System.out.println(costArray[endnum]);
	}
	
	public static class Pair implements Comparable<Pair>{
		int node, cost;
		Pair(int node, int cost){
			this.node = node;
			this.cost = cost;
		}
		public int compareTo(Pair p) {
            return this.cost - p.cost;
        }
	}
	
	public static class Bus{
		int start, arrive, cost;
		Bus(int start, int arrive, int cost){
			this.start = start;
			this.arrive = arrive;
			this.cost = cost;
		}
	}

}
