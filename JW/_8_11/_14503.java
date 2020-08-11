package JW._8_11;

import java.util.Scanner;

public class _14503 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, M;
		int map[][];
		boolean[][] clean;
		int count = 1;
		
		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, 1, 0, -1};
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		map = new int[N][M];
		clean = new boolean[N][M];
		
		int r, c, d;
		
		r = s.nextInt();
		c = s.nextInt();
		d = s.nextInt();
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<M;j++) {
				map[i][j] = s.nextInt();
				if(map[i][j] == 1)
					clean[i][j] = true;
			}
		}
		
		clean[r][c] = true;
		
		while(true) {
			
			int cantgo = 0;
			
			for(int i =0;i<4;i++) {
				int nx = r + dx[i];
				int ny = c + dy[i];
				
				if(map[nx][ny] == 1 || clean[nx][ny] == true)
						cantgo++;
			}
			
			if(cantgo == 4) {
				int back = (d+2) % 4;
				int backX = r + dx[back];
				int backY = c + dy[back];
				if(map[backX][backY] == 0) {
					r = backX;
					c = backY;
				}
				else
					break;
			}else {
				d = (d + 3) % 4;
				//x, y´Â ¿ÞÂÊ  r, c´Â ·Îº¿ Ã»¼Ò±â
				int x = r + dx[d];
				int y = c + dy[d];
				if(map[x][y] == 0 && clean[x][y] == false) {
					clean[x][y] = true;
					r = x;
					c = y;
					count++;
				}
				else if(clean[x][y] == true) {
				
				}
			}
		}
		
		System.out.println(count);

	}

}
