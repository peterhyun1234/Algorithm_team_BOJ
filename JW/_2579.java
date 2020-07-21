package _7_21;

import java.util.Scanner;

public class _2579 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		int score[];
		int DP[];
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		
		score = new int[N+1];
		DP = new int[N+1];
		
		for(int i =1;i <N+1;i++) {
			score[i] = s.nextInt();
		}
		
		DP[1] = score[1];
		if(N != 1) {
			DP[2] = score[1] + score[2];
		}
		for(int i=3;i<N+1;i++) {
			DP[i] = Math.max(DP[i-2] + score[i], score[i] + score[i-1] + DP[i-3]);
		}
		
		System.out.println(DP[N]);
	}

}
