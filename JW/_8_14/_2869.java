package JW._8_14;

import java.util.Scanner;

public class _2869 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int A, B, V;
		
		int curheight = 0;
		int ans = 0;
		
		Scanner s = new Scanner(System.in);
		
		A = s.nextInt();
		B = s.nextInt();
		V = s.nextInt();
		
		if(((V - A) % (A - B)) == 0)
			ans = (V - A) / (A - B) + 1;
		else {
			ans = (V - A) / (A - B) + 2;
		}

		System.out.println(ans);
	}

}
