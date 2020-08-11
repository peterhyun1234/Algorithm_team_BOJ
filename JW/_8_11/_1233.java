package JW._8_11;

import java.util.Scanner;

public class _1233 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] sum;
		int S1, S2, S3;
		int summax = 0;
		int ans = 0;
		
		Scanner s = new Scanner(System.in);
		
		S1 = s.nextInt();
		S2 = s.nextInt();
		S3 = s.nextInt();
		
		sum = new int[S1+S2+S3+1];
		
		for(int i =1;i<=S1;i++) {
			for(int j =1;j<=S2;j++) {
				for(int k=1;k<=S3;k++) {
					sum[i+j+k]++;
				}
			}
		}
		
		for(int i =0;i<sum.length;i++) {
			if(summax < sum[i]) {
				ans = i;
				summax = sum[i];
			}
		}
		
		System.out.println(ans);

	}

}
