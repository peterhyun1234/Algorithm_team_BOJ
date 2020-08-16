package JW._8_14;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class _1939 {

	
	static ArrayList<island> list[];
	static int N, M;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		int left = 1;
		int right = 0;
		
		list = new ArrayList[N+1];
		
		for(int i = 0;i<=N;i++) {
			list[i] = new ArrayList<island>();
		}
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			
			list[A].add(new island(A, B, weight));
			list[B].add(new island(B, A, weight));
			left = Math.min(left, weight);
			right = Math.max(weight, right);
		}
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		int ans = 0;
		
		while(left<=right) {
			int mid = (right + left) / 2;
			
			if(check(start, end, mid)) {
				left = mid + 1;
				ans = Math.max(ans, mid);
			}else {
				right = mid - 1;
			}
		}
		
		System.out.println(ans);
	}
	
	public static boolean check(int start, int end, int mid) {
		Queue<Integer> q = new LinkedList<Integer>();
		boolean[] visited = new boolean[N+1];
		visited[start] = true;
		q.add(start);
		
		while(!q.isEmpty()) {
			
			int A = q.poll();
			
			if(A == end)
				return true;
			
			for(int i =0;i<list[A].size();i++) {
				int B = list[A].get(i).B;
				int weight = list[A].get(i).weight;
				
				if(visited[B] == false && weight >= mid) {
					q.add(B);
					visited[B] = true;
					
				}
			}
		}
		
		return false;
		
		
	}
	
	//메모리 초과 왜???
	/*
	 * public static boolean check(int start, int end, int mid) {
		Queue<Integer> q = new LinkedList<Integer>();
		boolean[] visited = new boolean[N+1];
		
		q.add(start);
		
		while(!q.isEmpty()) {
			
			int A = q.poll();
			
			for(int i =0;i<list[A].size();i++) {
				
				if(visited[list[A].get(i).B] == false && list[A].get(i).weight >= mid) {
					if(list[A].get(i).B == end) {
						return true;
					}else {
						q.add(list[A].get(i).B);
					}
				}
			}
			
			visited[A] = true;
		}
		
		return false;
		
		
	}
	 */
	
	public static class island implements Comparable<island> {
		int A, B, weight;
		island(int A, int B, int weight){
			this.A = A;
			this.B = B;
			this.weight = weight;
		}
		
		
		public int compareTo(island i) {
			return i.weight - this.weight;
		}
	}
	

}


/*
public static void main(String[] args) {
// TODO Auto-generated method stub

int N, M;

Scanner s = new Scanner(System.in);

ArrayList<ArrayList<island>> list = new ArrayList();

PriorityQueue<island> q = new PriorityQueue<island>();

N = s.nextInt();
M = s.nextInt();
int[] dist;
boolean[] visited;

for(int i = 0;i<=N;i++) {
	list.add(new ArrayList<island>());
}
for(int i=0;i<M;i++) {
	int A = s.nextInt();
	int B = s.nextInt();
	int weight = s.nextInt();
	
	list.get(A).add(new island(A, B, weight));
	list.get(B).add(new island(B, A, weight));
}

int ansstart = s.nextInt();
int ansend = s.nextInt();

dist = new int[N+1];
visited = new boolean[N+1];

dist[ansstart] = Integer.MAX_VALUE;

q.add(new island(ansstart, 0, 0));

while(!q.isEmpty()) {
	int start = q.poll().A;
	
	for(int i =0;i<list.get(start).size();i++) {
		int end = list.get(start).get(i).B;
		int weight = list.get(start).get(i).weight;
		
		if(visited[start] == false && dist[end] < Math.min(dist[start], weight)) {
			dist[end] = Math.min(dist[start], weight);
			q.add(new island(end, 0, dist[end]));
		}
	}
	visited[start] = true;
	
}

System.out.println(dist[ansend]);

}

public static class island implements Comparable<island> {
int A, B, weight;
island(int A, int B, int weight){
	this.A = A;
	this.B = B;
	this.weight = weight;
}


public int compareTo(island i) {
	return i.weight - this.weight;
}
}*/