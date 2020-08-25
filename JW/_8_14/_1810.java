package JW._8_14;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class _1810 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, F;
		
		Scanner s = new Scanner(System.in);
		ArrayList<Pair> list = new ArrayList();
		PriorityQueue<Pair> q = new PriorityQueue<Pair>();
		
		double[] dist;
		boolean[] visited;
		
		N = s.nextInt();
		F = s.nextInt();
		
		dist = new double[N+1];
		visited = new boolean[N+1];
		list.add(new Pair(0, 0, 0, 0));
		for(int i =1;i<=N;i++) {
			int x = s.nextInt();
			int y = s.nextInt();
			list.add(new Pair(x, y, 0, i));
		}
		
		Collections.sort(list, new Comparator<Pair>() {

			@Override
			public int compare(Pair p1, Pair p2) {
				// TODO Auto-generated method stub
				if(p1.y > p2.y) {
					return 1;
				}
				else if(p1.y == p2.y) {
					if(p1.x >= p2.x)
						return 1;
					else
						return -1;
				}
				else
					return -1;
			}
		});
		
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		dist[0] = 0;
		q.add(new Pair(0, 0, 0, 0));
		
		while(!q.isEmpty()){
			Pair p = q.poll();
			int x = p.x;
			int y = p.y;
			int idx = p.idx;
			
			
			
			if(y >= F) {
				System.out.println(Math.round(p.distance));
				return;
			}
			
			if(visited[idx])
				continue;
			
			visited[idx] = true;
			
			for(int i=-2;i<3;i++) {
				int dy = y + i;
				
				if(dy < 0 || dy > 1000000)
					continue;
				
			}
			
			for(int i =0;i<list.size();i++) {
				Pair tmp = list.get(i);
				int nx = tmp.x;
				int ny = tmp.y;
				if(nx == x && ny == y)
					continue;
				if(Math.abs(x - nx) <= 2 && Math.abs(y - ny) <= 2) {
					dist[i] = Math.min(dist[i], Math.sqrt((nx-x) * (nx-x) + (ny-y) * (ny-y)) + dist[idx]);
					q.add(new Pair(nx, ny, dist[i], i));
				}
			}
			
			
		}
		
		System.out.println(-1);
	}
	
	public static class Pair implements Comparable<Pair>{
		int x, y;
		double distance;
		int idx;
		
		Pair(int x, int y, double distance, int idx){
			this.x = x;
			this.y = y;
			this.distance = distance;
			this.idx = idx;
		}
		
		 public int compareTo(Pair p) {
			 if(this.distance >= p.distance)
				 return 1;
			 else
				 return -1;
		 }

	}

}
