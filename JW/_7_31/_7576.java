package JW._7_31;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _7576 {
	
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int M, N;
	static int[][] box;
	static Queue<Pair> q = new LinkedList<Pair>();
	static int day = -1;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Scanner s = new Scanner(System.in);
		
		M = s.nextInt();
		N = s.nextInt();
		
		box = new int[N][M];
		
		for(int i =0;i<N;i++) {
			for(int j =0;j<M;j++) {
				box[i][j] = s.nextInt();
				if(box[i][j] == 1) {
					q.add(new Pair(i,j));
				}
			}
		}
		
		BFS();

		System.out.println(day);
	}
	
	public static void BFS() {
		
		while(!q.isEmpty()) {
			
			int qsize = q.size();
			for(int i =0;i<qsize;i++) {
				Pair pair = q.poll();
			
				int a = pair.x;
				int b = pair.y;
			
				for(int j =0;j<4;j++) {
					int nx = a + dx[j];
					int ny = b + dy[j];
				
					if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
						if(box[nx][ny] == 0) {
							box[nx][ny] = 1;
							q.add(new Pair(nx, ny));
						}
					}
				}
			}
			
			day++;
		}
		
		for(int i=0;i<N;i++) {
			for(int j= 0;j<M;j++) {
				if(box[i][j] == 0) {
					day = -1;
					break;
				}
			}
			if(day == -1)
				break;
		}
	}
	
	
	public static class Pair{
		int x, y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}

}
