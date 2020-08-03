package JW._7_31;

import java.util.Scanner;

public class _1107 {

	static boolean[] btn;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, M;
		
		int count = 0;
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		btn = new boolean[10];
		
		for(int i =0;i<M;i++) {
			int x = s.nextInt();
			btn[x] = true;
		}

		int ans = Math.abs(N - 100);
		
		for (int i = 0; i < 1000000; i++) {
			int c = i;
			int len = possible(c);
			
			if (len > 0) {
				int press = Math.abs(c - N);
				if (ans > len + press) {
					ans = len + press;
				}

			}

		}
		System.out.println(ans);
	}
	
	static int possible(int c) {
		if (c == 0) { 
			if (btn[0]) {
				return 0;
			} else {
				return 1;
			}
		}
		int len = 0;
		while (c > 0) {
			if (btn[c % 10]) {
				return 0;
			}
			len += 1;
			c /= 10;
		}
		return len;
	}

}
