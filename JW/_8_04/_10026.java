package JW._8_04;

import java.util.Scanner;

public class _10026 {

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int N;
	static String[][] picture;
	static boolean[][] visited;
	
	static int abled_zone = 0;
	static int disabled_zone = 0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		s.nextLine();
		picture = new String[N][N];
		
		
		for(int i =0;i<N;i++) {
			picture[i] = s.nextLine().split("");
		}
		
		//沥惑 备开
		visited = new boolean[N][N];
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(visited[i][j] == false) {
					String curColor = picture[i][j];
					visited[i][j] = true;
					DFS(i, j, curColor);
					abled_zone++;
				}
			}
		}

		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(picture[i][j].equals("G"))
					picture[i][j] = "R";
			}
		}
		//利废祸距 备开
		visited = new boolean[N][N];
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(visited[i][j] == false) {
					String curColor = picture[i][j];
					visited[i][j] = true;
					DFS(i, j, curColor);
					disabled_zone++;
				}
			}
		}
		
		System.out.println(abled_zone + " " + disabled_zone);
	}
	
	public static void DFS(int x, int y, String curColor) {
		
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if(picture[nx][ny].equals(curColor) && visited[nx][ny] == false) {
					visited[nx][ny] = true;
					DFS(nx, ny, curColor);
				}
			}
		}
	}

}
