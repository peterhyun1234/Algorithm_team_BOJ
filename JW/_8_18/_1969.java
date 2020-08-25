package JW._8_18;

import java.util.Scanner;

public class _1969 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, M;
		String[] DNA;
		String ans = "";
		int sum = 0;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		DNA = new String[N];
		
		s.nextLine();
		
		for(int i=0;i<N;i++) {
			DNA[i] = s.nextLine();
		}
		
		//A C G T
		for(int i=0;i<M;i++) {
			int[] alpha = new int[4];
			for(int j=0;j<N;j++) {
				char c = DNA[j].charAt(i);
				if(c == 'A')
					alpha[0]++;
				else if(c == 'C')
					alpha[1]++;
				else if(c == 'G')
					alpha[2]++;
				else if(c == 'T')
					alpha[3]++;
			}
			
			int idx = 0;
			int count = 0;
			for(int j =0;j<alpha.length;j++) {
				if(count < alpha[j]) {
					count = alpha[j];
					idx = j;
				}
			}
			if(idx == 0)
				ans += "A";
			else if(idx == 1)
				ans += "C";
			else if(idx == 2)
				ans += "G";
			else if(idx == 3)
				ans += "T";
		}

		for(int i =0;i<N;i++) {
			int HD = 0;
			for(int j=0;j<M;j++) {
				if(ans.charAt(j) != DNA[i].charAt(j))
					HD++;
			}
			sum += HD;
		}
		System.out.println(ans);
		System.out.println(sum);
	}

}
