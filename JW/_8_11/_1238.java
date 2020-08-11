package JW._8_11;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class _1238 {

	static 	ArrayList<ArrayList<Pair>> list = new ArrayList();

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		int N, M, X;

		int resultgo, resultback, resultmax = 0;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());
		
		for(int i=0;i<=N;i++) {
			list.add(new ArrayList<Pair>());
		}
		for(int i =0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int time = Integer.parseInt(st.nextToken());
			
			list.get(start).add(new Pair(start, end, time));
		}
		
		for(int i =1;i<=N;i++) {
			
			if(X == i)
				continue;
			
			//go Party
			int[] dist = new int[N+1];
			PriorityQueue<Pair> q = new PriorityQueue<Pair>();

			q.add(new Pair(i, 0, 0));
			Arrays.fill(dist, Integer.MAX_VALUE);
			dist[i] = 0;
			
			while(!q.isEmpty()) {
				Pair pair = q.poll();
				
				int start = pair.start;
				
				
				for(int j =0;j<list.get(start).size();j++) {
					int endidx = list.get(start).get(j).end;
					int time = list.get(start).get(j).time;
					
					
					if(dist[start] + time < dist[endidx]) {
						dist[endidx] = dist[start] + time;
						q.add(new Pair(endidx, 0, dist[endidx]));
					}
						
					
				}
			}
			
			resultgo = dist[X];
			
			//back home
			dist = new int[N+1];
			q = new PriorityQueue<Pair>();

			q.add(new Pair(X, 0, 0));
			Arrays.fill(dist, Integer.MAX_VALUE);
			dist[X] = 0;
			
			while(!q.isEmpty()) {
				Pair pair = q.poll();
				
				int start = pair.start;
				
				for(int j =0;j<list.get(start).size();j++) {
					int endidx = list.get(start).get(j).end;
					int time = list.get(start).get(j).time;
					
					
					if(dist[start] + time < dist[endidx]) {
						dist[endidx] = dist[start] + time;
						q.add(new Pair(endidx, 0, dist[endidx]));
					}
						
					
				}
			}
			
			resultback = dist[i];
			
			resultmax = Math.max(resultmax, resultgo + resultback);
		}
		
		System.out.println(resultmax);

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

/*
 * class Main {
    static int stoi(String s) { return Integer.parseInt(s);}
 
    static final int INF = 987654321;
    static int N, M, X;
    static int[] dist, revDist;
    static List<List<Node>> list, revList;
 
    // 마을의 번호와 시작점으로부터의 거리를 저장하는 Node 클래스
    // 거리가 짧은 순으로 자동으로 정렬되게 comparable 를 오버라이드
    static class Node implements Comparable<Node> {
        int index;
        int distance;
 
        public Node(int index, int distance) {
            this.index = index;
            this.distance = distance;
        }
 
        public int compareTo(Node n) {
            return this.distance - n.distance;
        }
    }
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
 
        // input data
        st = new StringTokenizer(br.readLine());
        N = stoi(st.nextToken());
        M = stoi(st.nextToken());
        X = stoi(st.nextToken());
        dist = new int[N+1];
        revDist = new int[N+1];
        list = new ArrayList<List<Node>>();
        revList = new ArrayList<List<Node>>();
 
        // 각 거리 초기화
        init();
 
        for(int i=1; i<=M; i++) {
            st = new StringTokenizer(br.readLine());
            
            int v1 = stoi(st.nextToken());
            int v2 = stoi(st.nextToken());
            int dist = stoi(st.nextToken());
 
            list.get(v1).add(new Node(v2, dist));
            revList.get(v2).add(new Node(v1, dist));
        }
 
        // solve
        // 다익스트라 2번을 이용해서 구할 수 있다
        // 주어진 간선에서 X번 마을에서 각 마을로 가는 최단 경로를 구하고
        dijkstra(list, dist, X);
 
        // 간선을 뒤집은 다음에 X번 마을에서 각 마을로 가는 최단 경로를 구하면
        // 각 마을에서 X번 마을로 가는 최단 경로를 구할 수 있음
        dijkstra(revList, revDist, X);
 
        // answer
        int max = -1;
        for(int i=1; i<=N; i++)
            max = Math.max(max, dist[i] + revDist[i]);
        System.out.println(max);
    }
 
    static void init() {
        Arrays.fill(dist, INF);
        Arrays.fill(revDist, INF);
 
        for(int i=0; i<=N; i++) {
            list.add(new ArrayList<Node>());
            revList.add(new ArrayList<Node>());
        }
    }
 
    static void dijkstra(List<List<Node>> list, int[] distance, int start) {
        boolean[] visited = new boolean[N+1];
        PriorityQueue<Node> pq = new PriorityQueue<Node>();
 
        distance[start] = 0;
        pq.add(new Node(start, 0));
 
        while(!pq.isEmpty()) {
            int idx = pq.poll().index;
 
            // 방문한 곳은 또 방문할 필요 없음
            if(visited[idx]) continue;
            visited[idx] = true;
 
            for(Node node : list.get(idx)) {
                // node.index 까지의 거리는 (시작점->idx 거리 + idx->node.index 거리) 중 더 작은 것
                if(distance[node.index] > distance[idx] + node.distance) {
                    distance[node.index] = distance[idx] + node.distance;
                    pq.add(new Node(node.index, distance[node.index]));
                }
            }
        }
    }
}
             
*/