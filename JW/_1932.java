package _7_17;

import java.util.Scanner;


public class _1932 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int high;
		int result = 0;
		
		int[][] T;
		
		Scanner s = new Scanner(System.in);
		
		high = s.nextInt();
		s.nextLine();
		
		T = new int[high][high];
		
		for(int i =0;i<high;i++) {
			for(int j =0;j<i+1;j++) {
				T[i][j] = s.nextInt();
			}
		}
		
		for(int i =1;i<high;i++) {
			for(int j =0;j<i+1;j++) {
				if(j==0) 
					T[i][j] = T[i][j] + T[i-1][j];
				else if(j==i) 
					T[i][j] = T[i][j] + T[i-1][j-1];
				else {
					if(T[i][j] + T[i-1][j-1] >= T[i][j] + T[i-1][j]) {
						T[i][j] = T[i][j] + T[i-1][j-1];
					}
					else if(T[i][j] + T[i-1][j-1] < T[i][j] + T[i-1][j]) {
						T[i][j] = T[i][j] + T[i-1][j];
					}
				}
				
				if(T[i][j] > result)
					result = T[i][j];
			}
		}

		System.out.println(result);
	}

}
