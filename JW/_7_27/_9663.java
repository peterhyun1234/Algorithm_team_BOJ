package JW._7_27;

import java.util.Scanner;

public class _9663 {

	
	static int N;
	static int count = 0;
	static int[] col;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		
		for(int i =1;i<=N;i++) {
			col = new int[N+1];
			col[1] = i;
			BT(2);
		}
		
		System.out.println(count);

	}
	
	public static void BT(int row) {
		if(row > N)
			++count;
		else {
			for(int i =1;i<=N;i++) {
				col[row] = i;
				
				if(checking(row)) {
					BT(row+1);
				}
				else {
					col[row] = 0;
				}
			}
		}
		
	}
	
	public static boolean checking(int row) {
		for(int i =1; i<row;i++) {
			if(col[i] == col[row])
				return false;
			if(Math.abs(col[row] - col[i]) == Math.abs(i-row))
				return false;
		}
		
		return true;
	}

}
