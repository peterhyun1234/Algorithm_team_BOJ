package JW._8_21;

import java.util.Scanner;

//���� left < right �� count(mid) < k �κ��� �򰥸� (= �� �־���ϴ°�??)
public class _1300 {

	static long N;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		long k;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextLong();
		k = s.nextLong();
		
		long left = 1;
		long right = k;
		
		while(left < right) {
			long mid = (left + right) / 2;
			
			if(count(mid) < k) {
				left = mid + 1;
			}
			else
				right = mid;
		}
		
		System.out.println(left);
	}
	
	public static long count(long mid) {
		
		long count = 0;
		for(int i=1;i<=N;i++) {
			count += Math.min(N, mid/i);
		}
		
		return count;
	}
	
}
