package JW._7_21;

import java.util.Scanner;

public class _11726 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int n;
		int[] DP = new int[1001];
		
		Scanner s = new Scanner(System.in);

		n = s.nextInt();
		
		DP[1] = 1;
		DP[2] = 2;
		
		for(int i =3;i<=n;i++) {
			DP[i] = (DP[i-1] + DP[i-2])%10007;
		}
		
		System.out.println(DP[n]);
	}

}
