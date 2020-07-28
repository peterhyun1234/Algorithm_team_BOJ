package JW._7_21;

import java.util.Scanner;

public class _10610 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String a;
		char c;
		Scanner s = new Scanner(System.in);
		int tmp;
		
		int[] num = new int[10];
		
		int sum = 0;
		boolean check = false;
		
		a = s.nextLine();
		for(int i =0;i< a.length();i++) {
			c = a.charAt(i);
			
			tmp = c - '0';
			if(tmp == 0)
				check = true;
			
			num[tmp] = num[tmp] + 1;
			sum = sum + tmp;
		}
		
		if(check == true && sum % 3 == 0){
			for(int i=9;i>=0;i--) {
				for(int j=0;j<num[i];j++){
					System.out.print(i);
				}
			}
		}
		else
			System.out.println("-1");
	}

}
