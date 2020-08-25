package JW._8_14;

import java.util.Scanner;

public class _1799 {

	
	static boolean[][] map;
	static int[][] board;
	static int max = 0;
	static int N;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		
		board = new int[N][N];
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				board[i][j] = s.nextInt();
			}
		}
		
		map = new boolean[N][N];
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				BackTracking(i, j, 0);
			}
		}

		System.out.println(max);
	}
	
	public static void BackTracking(int x, int y, int count) {
		if(x >= N || y >= N) {
			if(y >= N)
				BackTracking(x+1, 0, count);
			else if(x >= N) 
				max = Math.max(max, count);
		}
		else {
			if(checking(x,y)) {
				map[x][y] = true;
				BackTracking(x, y+1, count+1);
				map[x][y] = false;
			}
			else
				BackTracking(x, y+1, count);
		}
	}

	public static boolean checking(int x, int y) {
		
		if(board[x][y] == 0)
			return false;
		for(int i =0; i<N;i++) {
			for(int j= 0;j<N;j++) {
				if(map[i][j] == true) {
					if(Math.abs(i - x) == Math.abs(j - y))
						return false;
				}
			}
		}
		
		return true;
	}
}

// 시간초과
/*
 * static boolean[][] map;
	static int[][] board;
	static int max = 0;
	static int N;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		
		board = new int[N][N];
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				board[i][j] = s.nextInt();
			}
		}
		
		map = new boolean[N][N];
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				BackTracking(i, j, 0);
			}
		}

		System.out.println(max);
	}
	
	public static void BackTracking(int x, int y, int count) {
		if(x >= N || y >= N) {
			if(y >= N)
				BackTracking(x+1, 0, count);
			else if(x >= N) 
				max = Math.max(max, count);
		}
		else {
			if(checking(x,y)) {
				map[x][y] = true;
				BackTracking(x, y+1, count+1);
				map[x][y] = false;
			}
			else
				BackTracking(x, y+1, count);
		}
	}

	public static boolean checking(int x, int y) {
		
		if(board[x][y] == 0)
			return false;
		for(int i =0; i<N;i++) {
			for(int j= 0;j<N;j++) {
				if(map[i][j] == true) {
					if(Math.abs(i - x) == Math.abs(j - y))
						return false;
				}
			}
		}
		
		return true;
	}
 */