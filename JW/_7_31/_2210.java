package JW._7_31;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class _2210 {

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int[][] A;
	static Set<String> sixnumber = new HashSet<String>();
	static String[] print = new String[6];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		A = new int[5][5];
		
		Scanner s = new Scanner(System.in);
		
		for(int i =0;i<5;i++) {
			for(int j =0;j<5;j++) {
				A[i][j] = s.nextInt();
			}
		}
		
		for(int i =0;i<5;i++) {
			for(int j =0;j<5;j++) {
				print[0] = Integer.toString(A[i][j]);
				DFS(i,j, 1);
			}
		}
		
		System.out.println(sixnumber.size());

	}
	
	public static void DFS(int x, int y, int idx) {
		if(idx == 6) {
			String tmp = "";
			for(int i =0;i<6;i++) {
				tmp = tmp + print[i];
			}
			sixnumber.add(tmp);
			return;
		}
		
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
				print[idx] = Integer.toString(A[nx][ny]);
				DFS(nx, ny, idx+1);
			}
		}
	}

}
