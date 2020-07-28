package JW._7_27;

import java.util.Scanner;

public class _2798 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int N, M;
		
		int[] Card;
		int sum;
		int max = 0;
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		Card = new int[N];
		
		for(int i =0;i<N;i++) {
			Card[i] = s.nextInt();
		}
		
		for(int i =0;i<N-2;i++) {
			sum = Card[i];
			if(sum >= M)
				continue;
			for(int j =i+1;j<N-1;j++) {
				sum = Card[i] + Card[j];
				if(sum >= M)
					continue;
				for(int k=j+1;k<N;k++) {
					sum = Card[i] + Card[j] + Card[k];
					if(max < sum && M >= sum)
						max = sum;
				}
			}
		}
		
		System.out.println(max);
	}

}
