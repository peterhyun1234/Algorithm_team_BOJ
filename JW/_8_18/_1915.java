package JW._8_18;

import java.util.Scanner;

//DP로 생각하기가 어려움
//일반적인 시뮬레이션으로 계산하면 시간초과
public class _1915 {

	//static int[] dx = {1, 1, -1, -1};
	//static int[] dy = {1, -1, -1, 1};
	
	
	static int[][] map;
	static int N;
	static int M;
	static int maxsize = 0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		int[][] DP;
		N = s.nextInt();
		M = s.nextInt();
		
		s.nextLine();
		
		map = new int[N][M];
		DP = new int[N][M];
		
		for(int i=0;i<N;i++) {
			String line = s.nextLine();
			String[] num = line.split("");
			for(int j=0;j<M;j++) {
				map[i][j] = Integer.parseInt(num[j]);
				if(i == 0 || j == 0)
					DP[i][j] = map[i][j];
			}
		}
		
		for(int i=1;i<N;i++) {
			for(int j=1;j<M;j++) {
				if(DP[i-1][j-1] != 0 && DP[i-1][j] != 0 && DP[i][j-1] != 0 & map[i][j] == 1)
					DP[i][j] = Math.min(DP[i-1][j-1], Math.min(DP[i-1][j], DP[i][j-1])) + 1;
				else {
					if(map[i][j] == 1)
						DP[i][j] = 1;
					else
						DP[i][j] = 0;
				}
			}
		}
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<M;j++) {
				maxsize = Math.max(maxsize, DP[i][j]);
			}
		}
		System.out.println(maxsize * maxsize);
	}
	
	/*public static int FindSquare(int x, int y) {
		
		int foursize = 0;
		int direction = 0;
		
		for(int i =0;i<4;i++) {
			
			int size = 1;
			
			while(true) {
				int nx = x + size*dx[i];
				int ny = y + size*dy[i];
			
				if(nx >= N || ny >= M || nx < 0 || ny <0)
					break;
			
				else{
					if(map[nx][y] == 0 || map[x][ny] == 0)
						break;
			
					size++;
				}
			}
			if(foursize <= size) {
				foursize = size;
				direction = i;
			}
		}
		if(foursize <= maxsize)
			return -1;
		
		//direction
		// 0 , 1 , 2 , 3
		// ++, +-, --, -+
		if(direction == 0) {
			for(int i =x;i<x+foursize;i++) {
				for(int j=y;j<y+foursize;j++) {
					if(map[i][j] == 0)
						return -1;
				}
			}
		}
		else if(direction == 1) {
			for(int i =x;i<x+foursize;i++) {
				for(int j=y;j>y-foursize;j--) {
					if(map[i][j] == 0)
						return -1;
				}
			}
		}
		else if(direction == 2) {
			for(int i =x;i>x-foursize;i--) {
				for(int j=y;j>y-foursize;j--) {
					if(map[i][j] == 0)
						return -1;
				}
			}
		}
		else if(direction == 3) {
			for(int i =x;i>x-foursize;i--) {
				for(int j=y;j<y+foursize;j++) {
					if(map[i][j] == 0)
						return -1;
				}
			}
		}
		
		return foursize;
	}*/

}
