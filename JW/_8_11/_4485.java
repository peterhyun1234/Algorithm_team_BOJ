package JW._8_11;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class _4485 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		int[][] theifrupee;
		int[][] map;
		
		int[] dx = {1, 0, -1, 0};
		int[] dy = {0, -1, 0, 1};
		
		Scanner s = new Scanner(System.in);
		
		boolean[][] visited;
		int problem = 1;
		while(true) {
			
			N = s.nextInt();
			if(N == 0)
				break;
			
			PriorityQueue<Pair> q = new PriorityQueue<Pair>();
			theifrupee = new int[N][N];
			map = new int[N][N];
			
			visited = new boolean[N][N];
			
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					theifrupee[i][j] = s.nextInt();
					map[i][j] = Integer.MAX_VALUE;
				}
			}
			
			q.add(new Pair(0, 0, theifrupee[0][0]));
			map[0][0] = theifrupee[0][0];
			
			while(!q.isEmpty()) {
				
				Pair pair = q.poll();
				int x = pair.x;
				int y = pair.y;
				int rupee = pair.rupee;
				
				for(int i =0;i<4;i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					if(nx >=0 && ny >= 0 && nx < N && ny < N) {
						if(visited[nx][ny] == false) {
							if(map[x][y] + theifrupee[nx][ny] < map[nx][ny]) {
								map[nx][ny] = map[x][y] + theifrupee[nx][ny];
								q.add(new Pair(nx, ny, map[nx][ny]));
								
							}
						}
					}
				}
				visited[x][y] = true;
			}
			
			
			System.out.println("Problem " + problem + ": " + map[N-1][N-1]);
			problem = problem + 1;
		}

	}

	
	public static class Pair implements Comparable<Pair>{
		int x, y, rupee;
		Pair(int x, int y, int rupee){
			this.x = x;
			this.y = y;
			this.rupee = rupee;
		}
		public int compareTo(Pair p) {
            return this.rupee - p.rupee;
        }
	}
	
}
