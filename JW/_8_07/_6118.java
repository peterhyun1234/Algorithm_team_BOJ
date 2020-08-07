package JW._8_07;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//메모리 초과 배열?? -> list로 변경
public class _6118 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArrayList<ArrayList<Integer>> connect;
		
		int N, M;
		int dist[];
		boolean visited[];
		Scanner s = new Scanner(System.in);
		
		int ansnum = Integer.MAX_VALUE, ansdis = 0, anscount = 0;
		
		N = s.nextInt();
		M = s.nextInt();
		
		
		connect = new ArrayList();
		dist = new int[N+1];
		visited = new boolean[N+1];
		
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		dist[1] = 0;
		
		for(int i =0;i<=N;i++) {
			connect.add(new ArrayList<>());
		}
		for(int i =0;i<M;i++) {
			int a = s.nextInt();
			int b = s.nextInt();
			
			connect.get(a).add(b);
			connect.get(b).add(a);
		}
		
		for(int a =0;a<N;a++) {
			int distmin = Integer.MAX_VALUE;
			int idx = 0;
			
			for(int i =1;i<=N;i++) {
				if(visited[i] == false && distmin > dist[i]) {
					distmin = dist[i];
					idx = i;
				}
			}
			
			for(int j = 0;j< connect.get(idx).size();j++) {
				int tmp = connect.get(idx).get(j);
				if(visited[tmp] == false) {
					dist[tmp] = Math.min(dist[tmp], dist[idx] + 1);
					ansdis = Math.max(dist[tmp], ansdis);
				}
			}
			visited[idx] = true;
		}

		for(int i =1;i<=N;i++) {
			if(dist[i] == ansdis) {
				anscount++;
				ansnum = Math.min(i, ansnum);
			}
		}
		
		System.out.println(ansnum + " " + ansdis + " " + anscount);
	}

}
