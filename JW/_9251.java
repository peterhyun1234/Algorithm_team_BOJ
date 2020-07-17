package _7_17;

import java.util.Scanner;

public class _9251 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String A, B;
		int result;
		int[][] DP;
		Scanner s = new Scanner(System.in);

		A = s.nextLine();
		B = s.nextLine();
		
		DP = new int[A.length()+1][B.length()+1];
	
		
		for(int i = 1; i<B.length()+1;i++) {
			for(int j = 1; j<A.length()+1;j++) {
				if(A.charAt(j-1) == B.charAt(i-1)) {
					DP[j][i] = DP[j-1][i-1] + 1;
				}
				else {
					DP[j][i] = Math.max(DP[j][i-1], DP[j-1][i]);
				}
			}
		}
		
		System.out.println(DP[A.length()][B.length()]);
	}

}
