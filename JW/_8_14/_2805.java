package JW._8_14;

import java.util.Arrays;
import java.util.Scanner;

public class _2805 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int N, M;
		long[] tree;
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		tree = new long[N];
		
		for(int i =0;i<N;i++) {
			tree[i] = s.nextLong();
		}
		
		Arrays.sort(tree);
		
		long left = 1;
		long right = tree[N-1];
		
		while(left<=right) {
			long mid = (left + right) / 2;
			
			long height = 0;
			for(int i =0;i<tree.length;i++) {
				if(tree[i] - mid >= 0)
					height += tree[i] - mid;
			}
			
			if(height >= M) {
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		
		System.out.println(right);
	}

}
