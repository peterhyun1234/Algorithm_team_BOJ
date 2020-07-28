package JW._7_27;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

import javax.print.DocFlavor.INPUT_STREAM;
import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MaximizeAction;

public class _2075 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		
		int N;
		int[][] table;
		
		int row;
		int currow;
		
		int ans = 0;
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
		
		N = Integer.parseInt(bf.readLine());
		
		row = N-1;
		currow = N-1;
		
		table = new int[N][N];
		String[] tmp = new String[N];
		for(int i =0;i<N;i++) {
			tmp = bf.readLine().split(" ");
			for(int j = 0;j<N;j++) {
				table[i][j] = Integer.parseInt(tmp[j]);
			}
		}
		
		for(int i=0;i<N;i++) {
			priorityQueue.add(table[N-1][i]);
		}
		
		for(int i =N;i>0;i--) {
			
			ans = priorityQueue.poll();
			
			for(int j =N; j>row;j--) {
				for(int k=N;k>0;k--) {
					if(ans == table[j-1][k-1]) {
						currow = j-1;
						j = row;
						break;
					}
				}
			}
			
			if(row == currow && row != 0) {
				row = row -1;
				for(int j=0;j<N;j++) {
					priorityQueue.add(table[row][j]);
				}
			}
			
		}
		
		System.out.println(ans);

	}

}
