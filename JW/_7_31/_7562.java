package JW._7_31;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _7562 {

	
	static int[] dx = {-2, -1, 1, 2, 2, 1, -1, -2};
	static int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};
	
	static int end_x, end_y;
	static boolean[][] visited;
	static int l;
	static int count = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		int T;
		int[][] chess;
		int start_x, start_y;
		
		Scanner s = new Scanner(System.in);
		
		T = s.nextInt();

		
		for(int t=0;t<T;t++) {
			l = s.nextInt();
			
			visited = new boolean[l][l];
			start_x = s.nextInt();
			start_y = s.nextInt();
			
			end_x = s.nextInt();
			end_y = s.nextInt();
			
			System.out.println(BFS(start_x, start_y));
			count = 0;
		}
		

	}
	
	public static int BFS(int x, int y) {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(x, y));
		
		visited[x][y] = true;
		
		while(!q.isEmpty()) {
			
			int qsize = q.size();
			for(int i =0;i<qsize;i++) {
				int a, b;
			
				Pair pair = q.poll();
			
				a = pair.x;
				b = pair.y;
			
				if(a == end_x && b == end_y)
					return count;
			
				for(int j =0;j<8;j++) {
					int nx = a + dx[j];
					int ny = b + dy[j];
				
					if(nx >= 0 && ny >=0 && nx < l && ny < l) {
						if(visited[nx][ny] == false) {
							visited[nx][ny] = true;
							q.add(new Pair(nx, ny));
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
