package JW._8_21;

import java.util.Scanner;

public class _14501 {

	static int N;
	static int[] T, P;
	static int max = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		T = new int[N+2];
		P = new int[N+2];
		
		for(int i =1;i<=N;i++) {
			T[i] = s.nextInt();
			P[i] = s.nextInt();
		}
		T[N+1] = 1;
		P[N+1] = 0;
		
		for(int i=1;i<=N;i++) {
			consult(i, 0);
		}

		System.out.println(max);
	}
	
	public static void consult(int day, int money) {
		
		if(day >= N + 1) {
			max = Math.max(max, money);
			return;
		}
		
		consult(day + 1, money);
		
		if(day + T[day] > N + 1) {
			max = Math.max(max, money);
			return;
		}
		
		
		consult(day + T[day], money + P[day]);
		
	}

}
