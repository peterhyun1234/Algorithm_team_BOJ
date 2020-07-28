package JW._7_27;

import java.util.ArrayList;
import java.util.Scanner;

//다시 풀기
public class _2580 {

	static int[][] SDQ = new int[9][9];
	static ArrayList<int[]> list = new ArrayList<>();
	static boolean check;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		
		Scanner s = new Scanner(System.in);
		
		for(int i =0;i<9;i++) {
			for(int j=0;j<9;j++) {
				SDQ[i][j] = s.nextInt();
				if(SDQ[i][j] == 0)
					list.add(new int[] {i, j});
			}
		}
		
		BT(0,0);

	}
	
	public static void BT(int index, int count) {
		if(count == list.size()) {
			print();
			check = true;
			return;
		}
		if(check)
			return;
		if(index >= list.size())
			return;
		
		int x = list.get(index)[0];
		int y = list.get(index)[1];
		
		for (int i = 1; i <= 9; i++) {
			if (check(x, y, i)) {
				SDQ[x][y] = i;
				BT(index + 1, count + 1);
				SDQ[x][y] = 0;
			}

		}
	}
	
	public static boolean check(int x, int y, int n) {
		for (int i = 0; i < 9; i++) {
			if (SDQ[x][i] == n)
				return false;

			if (SDQ[i][y] == n)
				return false;
		}

		int nx = x / 3 * 3;
		int ny = y / 3 * 3;
		for (int i = nx; i < nx + 3; i++) {
			for (int j = ny; j < ny + 3; j++) {
				if (SDQ[i][j] == n)
					return false;
			}
		}

		return true;
	}

	public static void print() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sb.append(SDQ[i][j] + " ");
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}
