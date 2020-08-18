package JW._8_18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

//자바는 BFS 안되나..?
//DFS시 거꾸로 저장
public class _1325 {

	static ArrayList<ArrayList<Integer>> list;
	static boolean[] visited;
	static int[] count;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		StringBuilder sb = new StringBuilder();

		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int N, M;
		list = new ArrayList<>();
		
		String s = bf.readLine();
		StringTokenizer st = new StringTokenizer(s);
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		count = new int[N+1];
		
		for(int i=0;i<=N;i++) {
			list.add(new ArrayList<Integer>());
		}
		
		for(int i =0;i<M;i++) {
			String s1 = bf.readLine();
			StringTokenizer stt = new StringTokenizer(s1);
			int com1 = Integer.parseInt(stt.nextToken());
			int com2 = Integer.parseInt(stt.nextToken());
			
			list.get(com1).add(com2);
		}
		
		for(int i =1;i<=N;i++) {
			visited = new boolean[N+1];
			DFS(i);
		}

		int max = 0;
		
		for(int i =1;i<=N;i++) {
			max = Math.max(max, count[i]);
		}
		for(int i =1;i<=N;i++) {
			if(count[i] == max)
				sb.append(i + " ");
		}
		
		System.out.println(sb.toString());
	}
	
	public static void DFS(int num) {
		visited[num] = true;
		
		for(int v : list.get(num)) {
			if(!visited[v]) {
				count[v]++;
				DFS(v);
			}
		}
	}

}

// BFS 풀이
/*
 * for(int i =1;i<=N;i++) {
			boolean[] visited = new boolean[N+1];
			
			Queue<Integer> q = new LinkedList();
			q.add(i);
			
			while(!q.isEmpty()) {
				int num = q.poll();
				
				for(int j =0;j<list.get(num).size();j++) {
					int trustcom = list.get(num).get(j);
					if(visited[trustcom] == false) {
						visited[trustcom] = true;
						q.add(trustcom);
						count[i]++;
					}
				}
			}
			
			max = Math.max(max, count[i]);
		}
 */