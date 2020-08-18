package JW._8_18;

import java.util.Scanner;

//LIS 변형 문제!!
//N^2 으로 풀리지 않음
//어렵다
//https://devowen.com/290 참고
public class _2352 {

	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		int port[];
		int n;
		int DP[];
		
		n = s.nextInt();
		
		port = new int[n+1];
		DP = new int[n+1];
		
		for(int i =1;i<=n;i++) {
			port[i] = s.nextInt();
		}
		
		DP[1] = port[1];
		int count = 1;
		
		for(int i =1;i<=n;i++) {
			if(port[i] <= DP[count]) {
				//이분탐색을 쓰면 시간이 더 줄을 듯
				for(int j=1;j<=count;j++) {
					if(DP[j] >= port[i]) {
						DP[j] = port[i];
						break;
					}
				}
			}
			else {
				count = count + 1;
				DP[count] = port[i];
			}
		}
		
		System.out.println(count);

	}

}
