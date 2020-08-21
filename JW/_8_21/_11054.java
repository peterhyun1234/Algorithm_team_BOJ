package JW._8_21;

import java.util.Scanner;

//N�� 1000�̱� ������ n^2�ص� �ɵ�??
//�������� ������ LIS�� �����ʺ��� ������ LIS�� ���̸� ����
public class _11054 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		int[] num;
		int[] front;
		int[] flen;
		int[] back;
		int[] blen;
		
		int maxlen = 0;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		num = new int[N];
		front = new int[N];
		back = new int[N];
		flen = new int[N];
		blen = new int[N];
		
		for(int i=0;i<N;i++) {
			num[i] = s.nextInt();
		}
		
		
		front[0] = num[0];
		back[0] = num[N-1];
		int fidx = 0;
		int bidx = 0;
		for(int i=0;i<N;i++) {
			
			//front
			if(num[i] <= front[fidx]) {
				for(int j=0;j<=fidx;j++) {
					if(front[j] >= num[i]) {
						front[j] = num[i];
						flen[i] = j + 1;
						break;
					}
				}
			}else {
				fidx = fidx + 1;
				front[fidx] = num[i];
				flen[i] = fidx + 1;
			}
			
			//back
			if(num[N-i-1] <= back[bidx]) {
				for(int j=0;j<=bidx;j++) {
					if(back[j] >= num[N-i-1]) {
						back[j] = num[N-i-1];
						blen[i] = j + 1;
						break;
					}
				}
			}
			else {
				bidx = bidx + 1;
				back[bidx] = num[N-i-1];
				blen[i] = bidx + 1;
			}
			
		}
		
		for(int i =0;i<N;i++) {
			maxlen = Math.max(maxlen, flen[i] + blen[N-i-1] -1);
		}
		
		System.out.println(maxlen);

	}

}
