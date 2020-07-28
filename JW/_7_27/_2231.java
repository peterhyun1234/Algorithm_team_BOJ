package JW._7_27;

import java.util.Scanner;

public class _2231 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, M;
		int num = 1;
		int ans = 0;
		int tmp;
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		for(int i =0;i<N;i++) {
			M = i;
			tmp = i;
			while(tmp > 0) {
				M = M + tmp % 10;
				tmp = tmp / 10;
			}
			
			if(M == N) {
				ans = i;
				break;
			}
		}
		
		System.out.println(ans);
	}

}
