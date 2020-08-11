package JW._8_11;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _17471 {

	
	static int N;
	static ArrayList<ArrayList<Integer>> list;
	static int min = Integer.MAX_VALUE;
	static int[] population;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		list = new ArrayList<>();
		
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		
		population = new int[N+1];

		for(int i =1;i<=N;i++) {
			population[i] = s.nextInt();
		}
		
		for(int i =0;i<=N;i++) {
			list.add(new ArrayList<Integer>());
		}
		for(int i =1;i<=N;i++) {
			int M = s.nextInt();
			for(int j=0;j<M;j++) {
				list.get(i).add(s.nextInt());
			}
		}
		
		
		//정점 두개일 때 생각?
		if(N == 2) {
			System.out.println(Math.abs(population[1] - population[2]));
			return;
		}
			for(int i =1;i<N;i++) {
			ArrayList<Integer> area = new ArrayList<Integer>();
			DFS(i, 1, area);
		}
		
		if(min == Integer.MAX_VALUE)
			min = -1;
		System.out.println(min);
	}
	
	public static void DFS(int count, int idx, ArrayList<Integer> area) {
		if(area.size() == count) {
			calculate(area);
			return;
		}
		if(N < idx)
			return;

		area.add(idx);
		DFS(count, idx + 1, area);
		area.remove(area.size()-1);
		DFS(count, idx + 1, area);
		
	}
	
	public static void calculate(ArrayList<Integer> area) {
		ArrayList<Integer> another = new ArrayList<Integer>();
		
		for(int i =1;i<=N;i++) {
			if(!area.contains(i)) {
				another.add(i);
			}
		}
		
		//possible?
		Queue<Integer> q = new LinkedList<Integer>();
		boolean[] visited = new boolean[N+1];
		q.add(area.get(0));
		while(!q.isEmpty()) {
			int node = q.poll();
			
			for(int i =0;i<list.get(node).size();i++) {
				int nextnode = list.get(node).get(i);
				if(area.contains(nextnode) && visited[nextnode] == false)
					q.add(nextnode);
			}
			visited[node] = true;
		}
		for(int i =0;i<area.size();i++) {
			if(visited[area.get(i)] == false)
				return;
		}
		visited = new boolean[N+1];
		q.add(another.get(0));
		while(!q.isEmpty()) {
			int node = q.poll();
			
			for(int i =0;i<list.get(node).size();i++) {
				int nextnode = list.get(node).get(i);
				if(another.contains(nextnode) && visited[nextnode] == false)
					q.add(nextnode);
			}
			visited[node] = true;
		}
		for(int i =0;i<another.size();i++) {
			if(visited[another.get(i)] == false)
				return;
		}
		if(list.get(area.get(0)).size() == 0 && list.get(another.get(0)).size() == 0)
			return;
		
		//최솟값 계산
		int area1 = 0;
		int area2 = 0;
		
		for(int i = 0;i<area.size();i++) {
			area1 = area1 + population[area.get(i)];
		}
		for(int i = 0;i<another.size();i++) {
			area2 = area2 + population[another.get(i)];
		}
		
		min = Math.min(Math.abs(area1 - area2), min);
	}
	

}
