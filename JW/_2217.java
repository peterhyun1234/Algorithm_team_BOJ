package _7_21;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class _2217 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		int N;
		int[] R;
		
		int max;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		R = new int[N];
		
		for(int i =0; i< N; i++) {
			R[i] = Integer.parseInt(br.readLine());
		}
		
		Arrays.sort(R);
		max = 0;
		
		for(int i=N-1;i>=0;i--) {
			if(max <= R[i] * (N-i))
				max = R[i] * (N-i);
		}
		
		System.out.println(max);
		br.close();
	}

}
