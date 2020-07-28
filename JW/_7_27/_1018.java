package JW._7_27;

import java.util.Scanner;

public class _1018 {

	//첫번째 칸이 다른 색깔일때도 확인
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, M;
		
		String[][] B;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		s.nextLine();
		
		B = new String[N][M];
		
		int ans = N*M;
		int W_min;
		int B_min;
		
		for(int i=0;i<N;i++) {
			String tmp = s.nextLine();
			B[i] = tmp.split("");
		}

		for(int i =0;i<=N-8;i++) {
			for(int j =0;j<=M-8;j++) {
				
				W_min = 0;
				B_min = 0;
				
				if(B[i][j].equals("W")) {
					
					for(int k=0;k<8;k++) {
						for(int l=0;l<8;l++) {
							if((k+l) %2 == 0) {
								if(B[i+k][j+l].equals("B"))
									W_min++;
								else if (B[i+k][j+l].equals("W"))
									B_min++;
							}
							else if((k+l)%2 == 1) {
								if(B[i+k][j+l].equals("W"))
									W_min++;
								else if(B[i+k][j+l].equals("B"))
									B_min++;
							}
						}
					}
				}
				else {
					
					for(int k=0;k<8;k++) {
						for(int l=0;l<8;l++) {
							if((k+l) %2 == 0) {
								if(B[i+k][j+l].equals("W"))
									B_min++;
								else if(B[i+k][j+l].equals("B"))
									W_min++;
							}
							else if((k+l)%2 == 1) {
								if(B[i+k][j+l].equals("B")) {
									B_min++;
								}
								else if(B[i+k][j+l].equals("W")) {
									W_min++;
								}
							}
						}
					}
					
				}
				
				ans = Math.min(ans, Math.min(W_min, B_min));
				
			}
		}
		
		System.out.println(ans);
	}

}
