package JW._7_27;

import java.util.Scanner;

public class _14500 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, M;
		int[][] Score;
		
		int max = 0;
		int sum1, sum2, sum3, sum4;
		Scanner s = new Scanner(System.in);
		

		N = s.nextInt();
		M = s.nextInt();
		
		Score = new int[N+6][M+6];
		for(int i = 3;i<N+3;i++) {
			for(int j =3;j<M+3;j++) {
				Score[i][j] = s.nextInt();
			}
		}
		
		for(int i =3;i<N+3;i++) {
			for(int j=3;j<M+3;j++) {
				
				// ㅡ 모양 4가지
				sum1 = Score[i][j] + Score[i][j+1] + Score[i][j+2] + Score[i][j+3];
				sum2 = Score[i][j] + Score[i+1][j] + Score[i+2][j] + Score[i+3][j];
				sum3 = Score[i][j] + Score[i][j-1] + Score[i][j-2] + Score[i][j-3];
				sum4 = Score[i][j] + Score[i-1][j] + Score[i-2][j] + Score[i-3][j];
				
				max = Math.max(max, Math.max(sum1, Math.max(sum2, Math.max(sum3, sum4))));
				
				// ㅁ 모양 4가지
				sum1 = Score[i][j] + Score[i][j+1] + Score[i+1][j+1] + Score[i+1][j];
				sum2 = Score[i][j] + Score[i+1][j] + Score[i+1][j-1] + Score[i][j-1];
				sum3 = Score[i][j] + Score[i][j-1] + Score[i-1][j-1] + Score[i-1][j];
				sum4 = Score[i][j] + Score[i-1][j] + Score[i-1][j+1] + Score[i][j+1];
				
				max = Math.max(max, Math.max(sum1, Math.max(sum2, Math.max(sum3, sum4))));
				
				// L 모양 4가지
				sum1 = Score[i][j] + Score[i-1][j] + Score[i-2][j] + Score[i][j+1];
				sum2 = Score[i][j] + Score[i][j+1] + Score[i][j+2] + Score[i+1][j];
				sum3 = Score[i][j] + Score[i+1][j] + Score[i+2][j] + Score[i][j-1];
				sum4 = Score[i][j] + Score[i][j-1] + Score[i][j-2] + Score[i-1][j];
				
				max = Math.max(max, Math.max(sum1, Math.max(sum2, Math.max(sum3, sum4))));
				
				// L 대칭 모양 4가지
				sum1 = Score[i][j] + Score[i-1][j] + Score[i-2][j] + Score[i][j-1];
				sum2 = Score[i][j] + Score[i][j+1] + Score[i][j+2] + Score[i-1][j];
				sum3 = Score[i][j] + Score[i+1][j] + Score[i+2][j] + Score[i][j+1];
				sum4 = Score[i][j] + Score[i][j-1] + Score[i][j-2] + Score[i+1][j];
				
				max = Math.max(max, Math.max(sum1, Math.max(sum2, Math.max(sum3, sum4))));
				
				// ㄹ? 모양 4가지
				sum1 = Score[i][j] + Score[i][j-1] + Score[i+1][j] + Score[i+1][j+1];
				sum2 = Score[i][j] + Score[i-1][j] + Score[i][j-1] + Score[i+1][j-1];
				sum3 = Score[i][j] + Score[i-1][j] + Score[i-1][j-1] + Score[i][j+1];
				sum4 = Score[i][j] + Score[i][j+1] + Score[i-1][j+1] + Score[i+1][j];
				
				max = Math.max(max, Math.max(sum1, Math.max(sum2, Math.max(sum3, sum4))));
				
				// ㄹ? 대칭 모양 4가지
				sum1 = Score[i][j] + Score[i][j+1] + Score[i+1][j] + Score[i+1][j-1];
				sum2 = Score[i][j] + Score[i+1][j] + Score[i][j-1] + Score[i-1][j-1];
				sum3 = Score[i][j] + Score[i][j-1] + Score[i-1][j] + Score[i-1][j+1];
				sum4 = Score[i][j] + Score[i-1][j] + Score[i][j+1] + Score[i+1][j+1];
				
				max = Math.max(max, Math.max(sum1, Math.max(sum2, Math.max(sum3, sum4))));
				
				// ㅗ 모양 4가지
				sum1 = Score[i][j] + Score[i][j-1] + Score[i-1][j] + Score[i][j+1];
				sum2 = Score[i][j] + Score[i+1][j] + Score[i][j-1] + Score[i-1][j];
				sum3 = Score[i][j] + Score[i][j-1] + Score[i+1][j] + Score[i][j+1];
				sum4 = Score[i][j] + Score[i+1][j] + Score[i][j+1] + Score[i-1][j];
				
				max = Math.max(max, Math.max(sum1, Math.max(sum2, Math.max(sum3, sum4))));
			}
		}
		
		System.out.println(max);
	}

}
