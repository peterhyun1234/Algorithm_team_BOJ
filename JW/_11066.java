package _7_17;

import java.util.Arrays;
import java.util.Scanner;

public class _11066 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int T;
		
		int C;
		int[] P;
		
		int[] DP;
		
		int result = 0;
		
		Scanner s = new Scanner(System.in);
		
		T = s.nextInt();
		s.nextLine();
		
		for(int i =0;i<T;i++) {
			C = s.nextInt();
			s.nextLine();
			P = new int[C];
			for(int j=0;j<C;j++) {
				P[j] = s.nextInt();
			}
			s.nextLine();
			for(int j =0; j<P.length - 1;j++) {
				sort(P, j);
				P[j+1] = P[j] + P[j+1];
				result = result + P[j+1];
			}
			System.out.println(result);
			result = 0;
			
		}

	}

	public static int[] sort(int[] A, int n) {
		
		int tmp;
		for(int i =n; i<A.length;i++) {
			for(int j=i; j<A.length; j++) {
				if(A[i] > A[j]) {
					tmp = A[i];
					A[i] = A[j];
					A[j] = tmp;
				}
			}
		}
		
		return A;
	}
}
