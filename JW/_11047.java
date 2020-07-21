package _7_21;

import java.util.Scanner;

public class _11047 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int N, K;
		
		int[] A;
		
		int result = 0;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		K = s.nextInt();
		
		A = new int[N];
		
		for(int i=0;i<N;i++) {
			A[i] = s.nextInt();
		}
		
		for(int i=N-1;i>=0;i--) {
			while(true) {
				if(A[i] <= K) {
					K = K - A[i];
					result = result + 1;
				}
				else
					break;
			}
		}
		
		System.out.println(result);
	}

}
