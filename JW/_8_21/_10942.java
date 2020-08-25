package JW._8_21;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class _10942 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		
		int N, M;
		int[] num;
		boolean[][] mem;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		N = Integer.parseInt(br.readLine());
		num = new int[N+1];
		mem = new boolean[N+1][N+1];
		
		String[] tmp = br.readLine().split(" ");
		for(int i=1;i<=N;i++) {
			num[i] = Integer.parseInt(tmp[i-1]);
		}
		
		//길이 1
		for(int i =1;i<=N;i++) {
			mem[i][i] = true;
		}
		//길이 2
		for(int i=1;i<N;i++) {
			if(num[i] == num[i+1])
				mem[i][i+1] = true;
		}
		//길이 3이상
		for(int i=2;i<N;i++) {
			for(int j=1;j<=N-i;j++) {
				if(num[j] == num[j+i] && mem[j+1][j+i-1] == true)
					mem[j][j+i] = true;
			}
		}
		
		M = Integer.parseInt(br.readLine());
		StringBuffer sb = new StringBuffer();
		
		for(int i=0;i<M;i++) {
			tmp = br.readLine().split(" ");
			int S = Integer.parseInt(tmp[0]);
			int E = Integer.parseInt(tmp[1]);
			if(mem[S][E])
				sb.append("1\n");
			else
				sb.append("0\n");
		}
		
		System.out.println(sb);
	}

}
