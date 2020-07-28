package JW._7_17;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class _2437 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		int[] A;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		s.nextLine();
		
		A = new int[N];
		
		for(int i =0;i<N;i++) {
			A[i] = s.nextInt();
		}

		A = sort(A);
		
		int weight = 0;
		int ans = 0;
		while(true) {
			ans = ans + 1;
			weight = ans;
			for(int i =0; i<N; i++) {
				if(weight >= A[i]) {
					weight = weight - A[i];
				}
				if(weight == 0)
					break;
			}
			if(weight != 0)
				break;
		}
		System.out.println(ans);
	}
	
	public static int[] sort(int[] A) {
		
		int tmp;
		for(int i =0; i<A.length;i++) {
			for(int j=i; j<A.length; j++) {
				if(A[i] < A[j]) {
					tmp = A[i];
					A[i] = A[j];
					A[j] = tmp;
				}
			}
		}
		
		return A;
	}

}
