package JW._8_14;

import java.util.Arrays;
import java.util.Scanner;

public class _1339 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		int[] alpha = new int[26];
		
		String[] word;
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		word = new String[N];
		s.nextLine();
		
		for(int i =0;i<N;i++) {
			word[i] = s.nextLine();
		}
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<word[i].length();j++) {
				char c = word[i].charAt(j);
				alpha[c - 'A'] += Math.pow(10, word[i].length() - j-1);
			}
		}
		
		Arrays.sort(alpha);
		int num = 9;
		int ans = 0;
		for(int i=25;i>0;i--) {
			if(alpha[i] == 0)
				break;
			ans += alpha[i] * num;
			num--;
		}
		
		System.out.println(ans);
	}

}
