package JW._7_31;

import java.beans.Visibility;
import java.util.Scanner;

public class _1012 {

	
	static int[] nx = {1, 0, -1, 0};
	static int[] ny = {0, -1, 0, 1};
	static int M, N;
	static boolean[][] visited;
	static int[][] A;
	static int count = 0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int T, K;
		
		Scanner s = new Scanner(System.in);
		
		T = s.nextInt();
		
		for(int t =0;t<T;t++) {
			M = s.nextInt();
			N = s.nextInt();
			K = s.nextInt();
			
			A = new int[M][N];
			visited = new boolean[M][N];
			
			for(int k=0;k<K;k++) {
				int a, b;
				a = s.nextInt();
				b = s.nextInt();
				
				A[a][b] = 1;
			}
			
			for(int i=0;i<M;i++) {
				for(int j=0;j<N;j++) {
					if(A[i][j] == 1 && visited[i][j] == false) {
						count++;
						visited[i][j] = true;
						A[i][j] = count + 1;
						DFS(i, j);
					}
				}
			}
			System.out.println(count);
			count = 0;
		}
		

	}
	
	public static void DFS(int x, int y) {
		
		int lx, ly;
		for(int i=0;i<4;i++) {
			lx = x + nx[i];
			ly = y + ny[i];

			if(lx >=0 && ly >=0 && lx < M && ly < N) {
				
				if(visited[lx][ly] == false) {
					visited[lx][ly] = true;
					if(A[lx][ly] == 1) {
						A[lx][ly] = count + 1;
						DFS(lx, ly);
					}
				}
			}
		}
	}

}
