package JW._7_21;

import java.util.Scanner;

public class _1700 {

	//�ٽ��ѹ� Ǯ��
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, K;
		int[] S;
		
		int[] Use;
		int result = 0;
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		K = s.nextInt();
		
		S = new int[K];
		Use = new int[N];
		
		for(int i =0;i<K;i++) {
			S[i] = s.nextInt();
		}
		
		boolean isUse = false;
		for(int i=0;i<K;i++) {
			
			//�����ǰ�� �����ִ��� Ȯ��
			for(int j =0;j<N;j++) {
				if(Use[j] == S[i]) {
					isUse = true;
					break;
				}
			}
			
			if(isUse) {
				isUse= false;
				continue;
			}
			
			//����ִ� �ڵ� Ȯ��
			for(int j =0;j<N;j++) {
				if(Use[j] == 0) {
					Use[j] = S[i];
					isUse = true;
					break;
				}
			}
			
			if(isUse) {
				isUse= false;
				continue;
			}
			
			//���� ���߿� ����ϴ� �����ǰ ã��
			int swap = 0, val = -1;
			
			for(int j=0;j<N;j++) {
				int term = 0;
				for(int k=i+1;k<K && Use[j]!=S[k];k++) {
					term = term + 1;
					if(term > val) {
						swap = j;
						val = term;
					}
				}
			}
			result = result + 1;
			
			Use[swap] = S[i];
			
		}
		System.out.println(result);
	}

}
