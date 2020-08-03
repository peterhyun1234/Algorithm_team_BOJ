package JW._7_31;

import java.util.Scanner;

//다시 풀기 헷갈림???
public class _6603 {

	static int[] print;
	static int[] S;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int k;
		
		Scanner s = new Scanner(System.in);
		print = new int[6];
		while(true) {
			k = s.nextInt();
			
			if(k == 0)
				break;
			
			S = new int[k];
			
			for(int i =0;i<k;i++) {
				S[i] = s.nextInt();
			}
			
			
			DFS(0, 0);
			
			
			System.out.println();
		}

	}
	
	public static void DFS(int idx, int i) {
		if(idx == 6) {
			for(int p =0;p<6;p++) {
				System.out.print(print[p] + " ");
			}
			System.out.println();
			return;
		}
		
		
		for(int j =i; j<S.length;j++) {
			print[idx] = S[j];
			DFS(idx + 1, j+1);
		}
		
	}

}
