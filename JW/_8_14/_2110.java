package JW._8_14;

import java.util.Arrays;
import java.util.Scanner;

public class _2110 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, C;

		long[] house;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		C = s.nextInt();
		
		house = new long[N];
		
		for(int i =0;i<N;i++) {
			house[i] = s.nextLong();
		}
		
		Arrays.sort(house);
		
		long left = house[0];
		long right = house[N-1] - house[0];
		long mid;
		
		while(left<=right) {
			mid = (left + right) / 2;
			int d = 0;
			
			for(int i =0;i<N;i++) {
				
			}
		}
		
	}
	
}
