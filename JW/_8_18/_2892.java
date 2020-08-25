package JW._8_18;

import java.util.Scanner;

public class _2892 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		String[] crypto;
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		s.nextLine();
		crypto = new String[N];
		
		for(int i =0;i<N;i++) {
			crypto[i] = s.next();
		}
		
		for(int i =0;i<N;i++) {
			int num = Integer.parseInt(crypto[i], 16);
			if(check(num))
				System.out.printf("-");
			else
				System.out.printf(".");
		}

		
		/*//space hexcode : 20
		int space = Integer.parseInt("20", 16);
		// . hexcode : 
		int point = Integer.parseInt("2E", 16);
		
		for(int i = 0;i<10;i++) {
			String hkey = Integer.toString(i+30);
			int key = Integer.parseInt(hkey, 16);
			int alpha = Integer.parseInt("7A", 16);
			System.out.println(Integer.toHexString(point ^ key));
		}*/
	}
	
	public static boolean check(int num) {
		
		if(num >= 16 && num < 32)
			return false;
		/*//space or .
		if(hex.equals("10") || hex.equals("11") ||
				hex.equals("12") || hex.equals("13") ||
				hex.equals("14") || hex.equals("15") ||
				hex.equals("16") || hex.equals("17") ||
				hex.equals("18") || hex.equals("19") ||
				hex.equals("1e") || hex.equals("1f") ||
				hex.equals("1c") || hex.equals("1d") ||
				hex.equals("1a") || hex.equals("1b")){
			return false;
		}*/
		return true;
	}

}
