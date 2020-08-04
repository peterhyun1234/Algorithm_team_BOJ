package JW._8_04;

import java.util.Scanner;

public class _2468 {

	static int N;

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int[][] map;
	static int maxsafezone = 0;
	static boolean[][] visited;
	static int count = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);

		N = s.nextInt();
		
		map = new int[N][N];
		
		
		for(int i =0;i<N;i++) {
			for(int j =0;j<N;j++) {
				map[i][j] = s.nextInt();
			}
		}
		
		for(int i=0;i<100;i++) {
			visited = new boolean[N][N];
			for(int j =0;j<N;j++) {
				for(int k=0;k<N;k++) {
					if(map[j][k] > i && visited[j][k] == false) {
						visited[j][k] = true;
						DFS(j,k,i);
						count++;
					}
				}
			}
			if(maxsafezone < count)
				maxsafezone = count;
			count = 0;
		}
		
		System.out.println(maxsafezone);
		
	}
	
	public static void DFS(int x, int y, int height) {
		
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if(map[nx][ny] > height && visited[nx][ny] == false) {
					visited[nx][ny] = true;
					DFS(nx, ny, height);
				}
			}
		}
	}

}
