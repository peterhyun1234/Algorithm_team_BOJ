package JW._8_07;

import java.beans.Visibility;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class _1753 {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		PriorityQueue<Node> q = new PriorityQueue<Node>();
		ArrayList<ArrayList<Pair>> connect = new ArrayList();
		
		int V, E;
		int start;
		Scanner s = new Scanner(System.in);

		V = s.nextInt();
		E = s.nextInt();
		
		start = s.nextInt();
		int[] dist = new int[V+1];
		boolean[] visited = new boolean[V+1];
		
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[start] = 0;
		
		q.add(new Node(start, dist[start]));
		
		for(int i =0;i<=V;i++) {
			connect.add(new ArrayList<Pair>());
		}
		
		for(int i =0; i<E;i++) {
			int u, v, w;
			u = s.nextInt();
			v = s.nextInt();
			w = s.nextInt();
			
			connect.get(u).add(new Pair(v, w));
			
		}
		
		while(!q.isEmpty()) {
			int distmin = Integer.MAX_VALUE;
			int idx = 0;
			
			//우선순위 큐를 써야한다 O(V^2)돈다
			/*for(int j=1;j<=V;j++) {
				if(visited[j] == false && distmin > dist[j]) {
					distmin = dist[j];
					idx= j;
				}
			}*/
			Node n = q.poll();
			distmin = n.distance;
			idx = n.index;
			
			for(int j=0;j<connect.get(idx).size();j++) {
				Pair pair = connect.get(idx).get(j);
				int v = pair.v;
				int w = pair.w;
				
				if(visited[v] == false && dist[v] > distmin + w) {
					dist[v] = distmin + w;
					q.add(new Node(v, dist[v]));
				}
			}
			
			visited[idx] = true;
		}

		for(int i =1;i<=V;i++) {
			int tmp = dist[i];
			if(tmp == Integer.MAX_VALUE)
				System.out.println("INF");
			else
				System.out.println(tmp);
		}
	}
	
	
	static class Node implements Comparable<Node> {
        int index, distance;
 
        public Node(int index, int distance) {
            this.index = index;
            this.distance = distance;
        }
 
        public int compareTo(Node n) {
            return this.distance - n.distance;
        }
    }
	
	public static class Pair{
		int v, w;
		Pair(int v, int w){
			this.v = v;
			this.w = w;
		}
	}

}
