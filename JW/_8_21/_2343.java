package JW._8_21;

import java.util.Scanner;

public class _2343 {

	static int[] record;
	static int N, M;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int left = 0, right = 0;
		int sum = 0;
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		record = new int[N];
		
		for(int i =0;i<N;i++) {
			record[i] = s.nextInt();
			left = Math.max(left, record[i]);
			right += record[i];
		}
		
		while(left <= right) {
			int mid = (left + right) / 2;
			if(check(mid)) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		
		System.out.println(left);

	}

	public static boolean check(int mid) {
		
		int count = 0;
		int sum = 0;
		
		for(int i =0;i<N;i++) {
			sum += record[i];
			
			if(sum > mid) {
				count++;
				sum = record[i];
			}
			else if(sum == mid) {
				count++;
				sum = 0;
			}
		}
		
		if(sum != 0)
			count++;
		
		if(count <= M)
			return false;
		else
			return true;
	}
}
