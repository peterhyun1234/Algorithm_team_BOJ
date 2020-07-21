package _7_21;

import java.util.Scanner;

public class _4796 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int L, P, V;
		int i = 1;
		int result;
		Scanner s = new Scanner(System.in);
		
		while(true) {
			L = s.nextInt();
			
			P = s.nextInt();
			
			V = s.nextInt();
			s.nextLine();
			
			if(L == 0 && P == 0 && V ==0)
				break;
			
			if((V % P) > L)
				result = (V / P) * L + L;
			else
				result = (V / P) * L + (V % P);
			
			System.out.println("Case "+ i + ": " + result);
			i = i + 1;
		}
	}

}
