package JW._8_07;

import java.util.Scanner;

//��� ������� Ǯ�������� �Ϻ��� ���ش� ���� ���� 70%? ������ Ǯ�� �򰥸� Ȯ�� ����
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
