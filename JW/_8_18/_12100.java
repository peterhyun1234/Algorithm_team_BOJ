package JW._8_18;

import java.util.ArrayList;
import java.util.Scanner;

public class _12100 {

	static int N;
	static int ans = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[][] map;
		
		Scanner s = new Scanner(System.in);

		N = s.nextInt();
		
		map = new int[N][N];
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				map[i][j] = s.nextInt();
			}
		}
		
		start(map, 0);
		
		System.out.println(ans);
	}
	
	public static void start(int[][] map, int count) {
		
		if(count == 5) {
			for(int i =0;i<N;i++) {
				for(int j=0;j<N;j++) {
					ans = Math.max(map[i][j], ans);
				}
			}
			return;
		}
		start(up(map), count + 1);
		start(down(map), count + 1);
		start(left(map), count + 1);
		start(right(map), count + 1);
	}

	public static int[][] up(int[][] map) {
		
		int[][] result = new int[N][N];
		
		for(int j=0;j<N;j++) {
			
			ArrayList<Integer> line = new ArrayList<Integer>();
			
			for(int i=0;i<N;i++) {
				if(map[i][j] != 0)
					line.add(map[i][j]);
			}
			
			for(int i=0;i<line.size()-1;i++) {
				if(line.get(i).compareTo(line.get(i+1)) == 0) {
					line.set(i, line.get(i) * 2);
					line.remove(i+1);
				}
			}
			
			for(int i =0;i<line.size();i++) {
				result[i][j] = line.get(i);
			}
		}
		return result;
	}
	public static int[][] down(int[][] map) {
		
		int[][] result = new int[N][N];
		
		for(int j=0;j<N;j++) {
			
			ArrayList<Integer> line = new ArrayList<Integer>();
			
			for(int i=N-1;i>=0;i--) {
				if(map[i][j] != 0)
					line.add(map[i][j]);
			}
			

			for(int i=0;i<line.size()-1;i++) {
				if(line.get(i).compareTo(line.get(i+1)) == 0) {
					line.set(i, line.get(i) * 2);
					line.remove(i+1);
				}
			}
			
			for(int i =0;i<line.size();i++) {
				result[N-i-1][j] = line.get(i);
			}
		}
		
		return result;
	}
	public static int[][] left(int[][] map) {
		
		int[][] result = new int[N][N];
		
		for(int i =0;i<N;i++) {
			
			ArrayList<Integer> line = new ArrayList<Integer>();

			for(int j=0;j<N;j++) {
				if(map[i][j] != 0)
					line.add(map[i][j]);
			}
			
			for(int j=0;j<line.size()-1;j++) {
				if(line.get(j).compareTo(line.get(j+1)) == 0) {
					line.set(j, line.get(j) * 2);
					line.remove(j+1);
				}
			}
			
			for(int j =0;j<line.size();j++) {
				result[i][j] = line.get(j);
			}
		}
		
		return result;
	}
	public static int[][] right(int[][] map) {
		
		int[][] result = new int[N][N];
		
		for(int i =0;i<N;i++) {
			
			ArrayList<Integer> line = new ArrayList<Integer>();

			for(int j=N-1;j>=0;j--) {
				if(map[i][j] != 0)
					line.add(map[i][j]);
			}
			
			for(int j=0;j<line.size()-1;j++) {
				if(line.get(j).compareTo(line.get(j+1)) == 0) {
					line.set(j, line.get(j) * 2);
					line.remove(j+1);
				}
			}
			
			for(int j =0;j<line.size();j++) {
				result[i][N - j - 1] = line.get(j);
			}
		}
		
		return result;
	}
	
}
