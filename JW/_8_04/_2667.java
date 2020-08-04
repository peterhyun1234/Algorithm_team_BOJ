package JW._8_04;

import java.util.Scanner;

public class _2667 {

	
	static int[] nx = {1, 0, -1, 0};
	static int[] ny = {0, -1, 0, 1};
	static int N;
	static boolean[][] visited;
	static int[][] map;
	static int num = 1;
	static int[] apart;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		s.nextLine();
		map = new int[N][N];
		
		apart = new int[N*N];
		visited = new boolean[N][N];
		
		for(int i =0;i<N;i++) {
			String[] tmp = s.nextLine().split("");
			for(int j=0;j<tmp.length;j++) {
				map[i][j] = Integer.parseInt(tmp[j]);
			}
		}
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(map[i][j] == 1 && visited[i][j] == false) {
					num++;
					visited[i][j] = true;
					map[i][j] = num;
					apart[num]++;
					DFS(i,j);
				}
			}
		}
		
		System.out.println(num-1);
		
		Sort(apart);
		for(int i =0;i<apart.length;i++) {
			if(apart[i] != 0)
				System.out.println(apart[i]);
		}
	}
	
	public static void DFS(int x, int y) {
		int lx, ly;
		for(int i =0;i<4;i++) {
			lx = x + nx[i];
			ly = y + ny[i];
			
			if(lx >=0 && ly >=0 && lx < N && ly < N) {
				
				if(visited[lx][ly] == false) {
					visited[lx][ly] = true;
					if(map[lx][ly] == 1) {
						map[lx][ly] = num;
						apart[num]++;
						DFS(lx, ly);
					}
				}
			}
		}
	}

	public static void Sort(int[] array) {
		for(int i =0;i<array.length;i++) {
			for(int j=i;j<array.length;j++) {
				if(array[i] == 0)
					break;
				if(array[i] > array[j]) {
					int tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
				}
					
			}
		}
	}
}
