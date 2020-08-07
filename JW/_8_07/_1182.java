package JW._8_07;

import java.util.Scanner;

//재귀 방식으로 풀긴했지만 완벽히 이해는 가지 않음 70%? 다음에 풀때 헷갈릴 확률 높음
public class _1182 {

	static int ans = 0;
	static int N, S;
	static int[] A;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		S = s.nextInt();
		
		A = new int[N];
		for(int i =0;i<N;i++) {
			A[i] = s.nextInt();
		}

		for(int i =0;i<N;i++) {
			sum(0, i);
		}
		
		System.out.println(ans);
	}
	
	public static void sum(int n, int idx) {
		
		if(idx == N)
			return;
		
		n = n + A[idx];
		
		if(n == S)
			ans++;
		
		for(int i =idx+1;i<N;i++) {
			sum(n, i);
		}
	}

}
