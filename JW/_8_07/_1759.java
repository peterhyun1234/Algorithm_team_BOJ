package JW._8_07;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class _1759 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);

		int L = s.nextInt();
		int C = s.nextInt();
		s.nextLine();
		
		String[] alpha = new String[C];
		
		for(int i =0;i<C;i++) {
			alpha[i] = s.next();
		}
		Arrays.sort(alpha);
		makecode(L, alpha, "", 0);
	}
	
	public static void makecode(int L, String[] alpha, String code, int idx) {
		if(code.length() == L) {
			if(check(code, L)) {
				System.out.println(code);
			}
			return;
		}
		if(alpha.length <= idx)
			return;
		
		makecode(L, alpha, code + alpha[idx], idx+1);
		makecode(L, alpha, code, idx+1);
		
	}
	
	public static boolean check(String code, int L) {
		
		int ja = 0;
		int mo = 0;
		for(int i=0;i<L;i++){
			char x = code.charAt(i);
			if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                mo += 1;
            }else {
            	ja += 1;
            }
		}
		
		return ja >=2 && mo >=1;
	}

}
