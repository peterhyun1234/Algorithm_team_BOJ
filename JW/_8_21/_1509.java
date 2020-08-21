package JW._8_21;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//펠린드롬? 10942번 먼저 풀고 오기
//펠린드롬 i~j 구한 후 구하여야 한다.
//DP 어려운 문제는 진짜 어렵다..
public class _1509 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str = br.readLine();
		
		int len = str.length();
		boolean[][] mem = new boolean[len+1][len+1];
		int[] DP = new int[len+1];
		
		//길이 1
		for(int i =1;i<=len;i++) {
			mem[i][i] = true;
		}
		//길이 2
		for(int i=1;i<len;i++) {
			if(str.charAt(i-1) == str.charAt(i))
				mem[i][i+1] = true;
		}
		//길이 3이상
		for(int i=2;i<len;i++) {
			for(int j=1;j<=len-i;j++) {
				if(str.charAt(j-1) == str.charAt(j+i-1) && mem[j+1][j+i-1] == true)
					mem[j][j+i] = true;
			}
		}
		
		Arrays.fill(DP, len);
		DP[0] = 0;
		
		for(int i=1;i<=len;i++) {
			for(int j=1;j<=i;j++) {
				if(mem[j][i])
					if(DP[i] > DP[j-1] + 1)
						DP[i] = DP[j-1] + 1;
			}
		}
		
		System.out.println(DP[len]);
		
	}

}
