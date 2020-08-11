package JW._8_11;

import java.util.PriorityQueue;
import java.util.Scanner;


public class _1261 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int M, N;
		int[][] map;
		int[][] breakwall;
		boolean[][] visited;

		int[] dx = {1, 0, -1, 0};
		int[] dy = {0, -1, 0, 1};
		
		PriorityQueue<Pair> q = new PriorityQueue<Pair>();

		Scanner s = new Scanner(System.in);
		
		M = s.nextInt();
		N = s.nextInt();

		s.nextLine();
		map = new int[N][M];
		breakwall = new int[N][M];
		visited = new boolean[N][M];
		
		
		for(int i =0;i<N;i++) {
			String input = s.nextLine();
			for(int j =0;j<M;j++) {
				String[] tmp = input.split("");
				map[i][j] = Integer.parseInt(tmp[j]);
				breakwall[i][j] = Integer.MAX_VALUE;
			}
		}
		
		q.add(new Pair(0, 0, map[0][0]));
		breakwall[0][0] = 0;
		
		while(!q.isEmpty()) {
			Pair pair = q.poll();
			int x = pair.x;
			int y = pair.y;
			
			for(int i =0;i<4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx >=0 && ny >= 0 && nx < N && ny < M) {
					if(visited[nx][ny] == false) {
						if(breakwall[x][y] + map[nx][ny] < breakwall[nx][ny]) {
							breakwall[nx][ny] = breakwall[x][y] + map[nx][ny];
							q.add(new Pair(nx, ny, breakwall[nx][ny]));
						}
					}
				}
			}
			
			visited[x][y] = true;
		}
		
		System.out.println(breakwall[N-1][M-1]);
	}

	public static class Pair implements Comparable<Pair>{
		int x, y, count;
		Pair(int x, int y, int count){
			this.x = x;
			this.y = y;
			this.count = count;
		}
		public int compareTo(Pair p) {
            return this.count - p.count;
        }
	}
	
}
