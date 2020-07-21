package _7_21;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class _1931 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		
		int N;

		int result = 0;
		
		int[][] cur = {{0,0}};
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(bf.readLine());
		int[][] T = new int[N][2];
		
		for(int i =0;i<N;i++) {
			String s = bf.readLine();
			String[] stmp = s.split(" ");
			T[i][0] = Integer.parseInt(stmp[0]);
			T[i][1] = Integer.parseInt(stmp[1]);
		}
		
        Arrays.sort(T, new Comparator<int[]>(){
            @Override
            public int compare(int[] arg0, int[] arg1) {
                if (arg0[1] == arg1[1]) {
                    return Integer.compare(arg0[0], arg1[0]);
                }
                return Integer.compare(arg0[1], arg1[1]);
            }
        });
		
		cur[0][1] = -1;
		
		for(int i = 0;i<N;i++) {
			if(cur[0][1] <= T[i][0]) {
				cur[0][0] = T[i][0];
				cur[0][1] = T[i][1];
				result = result + 1;
			}
		}

		System.out.println(result);
	}
	
}
