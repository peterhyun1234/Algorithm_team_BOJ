package JW._8_07;

import java.util.Scanner;

public class _1987 {


	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int R, C;
	static String[][] Board;
	static int max = 0;
	static boolean[] alpha;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);

		alpha = new boolean[26];
		R = s.nextInt();
		C = s.nextInt();
		s.nextLine();
		Board = new String[R][C];
		
		for(int i =0;i<R;i++) {
			Board[i] = s.nextLine().split("");
		}
		
		alpha[Board[0][0].charAt(0) - 'A'] = true;
		DFS(0, 0, 1);
		System.out.println(max);
	}

	public static void DFS(int x, int y, int idx) {
		
		alpha[Board[x][y].charAt(0) - 'A'] = true;
		for(int i =0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if(alpha[Board[nx][ny].charAt(0) - 'A'] == false) {
					DFS(nx, ny, idx+1);
				}
			}
		}
		//다시 false로 바꾸어 주어야함
		alpha[Board[x][y].charAt(0) - 'A'] = false;
		max = Math.max(max, idx);
	}
}
