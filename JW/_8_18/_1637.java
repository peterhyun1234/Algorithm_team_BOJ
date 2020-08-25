package JW._8_18;

import java.util.Scanner;

//생각하기 어려움 이분 탐색으로 풀었다.
//홀수가 하나인것을 이용하여 품
//누적합으로 푼다
public class _1637 {

	
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

		Search();
		
	}
	
	public static void Search() {
		long left = min;
		long right = max;
		
		while(left < right) {
			long mid = (left + right) / 2;
			
			if(getSum(mid) % 2 == 0) {
				left = mid + 1;
			}
			else {
				//왜 mid + 1이 아닌 mid??
				right = mid;
			}
		}
		
		if(left == max)
			System.out.println("NOTHING");
		else
			System.out.println(left + " " + (getSum(left) - getSum(left- 1)));
	}
	
	public static long getSum(long mid) {
		long sum = 0;
		for(int i =0;i<N;i++) {
			if(mid >= A[i]) {
				sum += ((Math.min(mid, C[i]) - A[i]) / B[i]) + 1;
			}
		}
		
		return sum;
	}

}
