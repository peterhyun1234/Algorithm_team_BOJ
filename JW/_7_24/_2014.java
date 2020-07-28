package JW._7_24;

import java.util.PriorityQueue;
import java.util.Scanner;

public class _2014 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int K, N;
		long head = 0;
		long[] P;
		Scanner s = new Scanner(System.in);
		PriorityQueue<Long> q = new PriorityQueue<>();

		K = s.nextInt();
		N = s.nextInt();
		
		P = new long[K];
		
		for(int i =0;i<K;i++) {
			P[i] = s.nextLong();
			q.add(P[i]);
		}
		
		for(int i = 0;i<N;i++) {
			head = q.poll();
			for(int j =0;j<K;j++) {
				long value = head * P[j];
				q.add(value);
				
				if(head % P[j] == 0)
					break;
			}
		}
		System.out.println(head);

	}

}
