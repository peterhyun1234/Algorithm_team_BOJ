package _7_17;

import java.util.Scanner;

public class _11053 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		int[] A;
		int[] DP;
		
		int result = 0;  
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		s.nextLine();
		A = new int[N];
		DP = new int[N];
		
		for(int i =0 ;i<DP.length;i++) {
			DP[i] = 1;
		}
		
		for(int i =0;i<N;i++) {
			A[i] = s.nextInt();
		}
		
		for(int i =0;i<N;i++) {
			for(int j =0;j<i;j++) {
				if(A[i] > A[j] && DP[i] <= DP[j])
					DP[i] = DP[j] + 1;
			}
		}
		
		for(int i=0;i<DP.length;i++) {
			if(result < DP[i])
				result = DP[i];
		}
		
		System.out.println(result);
	}

}
