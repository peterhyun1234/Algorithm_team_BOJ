package JW._8_18;

import java.util.Scanner;

public class test {

	static int[] A, B, C;
	static int N;
	static int min, max;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		
		A = new int[N];
		B = new int[N];
		C = new int[N];
		
		min = Integer.MAX_VALUE;
		max = 0;
		for(int i =0;i<N;i++) {
			A[i] = s.nextInt();
			C[i] = s.nextInt();
			B[i] = s.nextInt();
			
			min = Math.min(min, A[i]);
			max = Math.max(max, C[i]);
		}
		max++;
		
		
		binarySearch();
		
	}

	public static void binarySearch() {
		long left = min;
		long right = max;
		
		while(left < right) {
			long mid = (left + right) / 2;
			
			// 누적 합이 짝수면 오른쪽 어딘가에 홀 수 누적합이 있을 것!
			long sum = getSum(mid);
			if(sum % 2 == 0) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		
		// 홀수인게 없으면 계속 오른쪽으로 가다가 초기 right 값에 도달한다.
		if(left == max)
			System.out.println("NOTHING");
		else {
			long num = getSum(left) - getSum(left - 1);
			System.out.println(left + " " + num);
		}
	}
	
	public static long getSum(long mid) {
		long sum = 0;
		for(int i=0; i<N; i++){
			if(mid >= A[i])
				sum += (Math.min(mid, C[i]) - A[i]) / B[i] + 1;
		}
		return sum;
	}
}
