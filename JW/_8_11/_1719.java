package JW._8_11;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class _1719 {

	static ArrayList<ArrayList<Pair>> list = new ArrayList();
	static int n;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int m;
		Scanner s = new Scanner(System.in);
		
		n = s.nextInt();
		m = s.nextInt();
		
		for(int i =0;i<=n;i++) {
			list.add(new ArrayList<Pair>());
		}
		for(int i=0;i<m;i++) {
			int start = s.nextInt();
			int end = s.nextInt();
			int time = s.nextInt();
			
			list.get(start).add(new Pair(start, end, time));
			list.get(end).add(new Pair(end, start, time));
		}
		
		for(int i =1;i<=n;i++) {
			DA(i);
		}
	}
	
	public static void DA(int a) {
		
		int[] dist = new int[n+1];
		int[] trace = new int[n+1];
		boolean[] visited = new boolean[n+1];
		PriorityQueue<Pair> q = new PriorityQueue<Pair>();
		
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[a] = 0;
		trace[a]= a;
		q.add(new Pair(a, 0, 0));
		
		while(!q.isEmpty()) {
			
			Pair pair = q.poll();
			
			int start = pair.start;
			
			//vistied 안쓰면 시간초과???
			if(visited[start])
				continue;
			for(int i =0;i<list.get(start).size();i++) {
				int endidx = list.get(start).get(i).end;
				int time = list.get(start).get(i).time;
				
				if(dist[start] + time < dist[endidx]) {
					dist[endidx] = dist[start] + time;
					trace[endidx] = start;
					q.add(new Pair(endidx, 0, dist[endidx]));
				}
				
			}
			
			visited[start] = true;
		}
		//메모리 초과
		print(a, trace);
	}

	public static void print(int start, int[] trace) {
		for(int i =1; i<=n;i++) {
			if(i == start) {
				System.out.printf("- ");
				continue;
			}
				int answer = 0;
				for(int j =i;j != start; j = trace[j]) {
					answer = j;
				}
				System.out.printf(answer + " ");
		}
		System.out.println();
	}
	public static class Pair implements Comparable<Pair>{
		int start, end, time;
		Pair(int start, int end, int time){
			this.start = start;
			this.end = end;
			this.time = time;
		}
		public int compareTo(Pair p) {
            return this.time - p.time;
        }
	}
}

/*public static int DA(int a, int b) {
		int nextnode = 0;
		int mintime = Integer.MAX_VALUE;
		for(int i =0;i<list.get(a).size();i++) {
			
			int time = list.get(a).get(i).time;
			int secondnode = list.get(a).get(i).end;
			int[] dist = new int[n+1];
			boolean[] visited = new boolean[n+1];
			
			PriorityQueue<Pair> q = new PriorityQueue<Pair>();
			q.add(new Pair(secondnode, 0, 0));
			Arrays.fill(dist, Integer.MAX_VALUE);
			dist[secondnode] = 0;
			
			while(!q.isEmpty()) {
				Pair p = q.poll();
				
				int start = p.start;
				
				for(int j =0;j<list.get(start).size();j++) {
					int endidx = list.get(start).get(j).end;
					int ttime = list.get(start).get(j).time;
					
					
					if(visited[start] == false && dist[start] + ttime < dist[endidx]) {
						dist[endidx] = dist[start] + ttime;
						q.add(new Pair(endidx, 0, dist[endidx]));
					}
				}
				visited[start] = true;
			}
			
			time = time + dist[b];
			
			if(mintime > time) {
				mintime = time;
				nextnode = secondnode;
			}
		}
		
		return nextnode;
	}
	*/
