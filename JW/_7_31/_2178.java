package JW._7_31;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class _2178 {

	
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	static int N, M;
	static int[][] Maze;
	static boolean[][] visited;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		String tmp = "";
		Maze = new int[N][M];
		visited = new boolean[N][M];
		
		for(int i=0;i<N;i++) {
			tmp = s.next();
			for(int j =0;j<M;j++) {
				Maze[i][j] = tmp.charAt(j) - 48;
				visited[i][j] = false;
			}
		}
		
		visited[0][0] = true;
		System.out.println(BFS(0, 0));

	}
	
	public static int BFS(int x, int y) {
		
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(x,y));
		
		int count = 1;
		
		int qsize;
		while(!q.isEmpty()) {
			
			qsize = q.size();
			for(int i=0;i<qsize;i++) {
				
				int a, b;
				
				Pair pair = q.poll();
				
				a = pair.x;
				b = pair.y;
				
				if(a == N-1 && b == M-1)
					return count;
	
				for(int j =0;j<4;j++) {
					int nx = a + dx[j];
					int ny = b + dy[j];
					
					if(nx >=0 && ny >=0 && nx<N && ny <M) {
						if(Maze[nx][ny] == 1 && visited[nx][ny] == false) {
							visited[nx][ny] = true;
							q.add(new Pair(nx,ny));
					}
				}
			}
		}
			count++;
	}
		
		return count;
	}
	
	public static class Pair{
		int x, y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}

}
