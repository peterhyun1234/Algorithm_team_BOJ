package JW._8_04;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class _14502 {

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int N, M;
	static int[][] map;
	static int[][] wallmap;
	
	static Queue<Pair> virus = new LinkedList<Pair>();
	static int max;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		LinkedList<Pair> list = new LinkedList<Pair>();
		Scanner s = new Scanner(System.in);
		

		
		N = s.nextInt();
		M = s.nextInt();
		
		map = new int[N][M];
		wallmap = new int[N][M];
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<M;j++) {
				map[i][j] = s.nextInt();
				if(map[i][j] == 0)
					list.add(new Pair(i, j));
			}
		}
		
		for(int a =0;a<list.size()-2;a++) {
			for(int b=a+1;b<list.size()-1;b++) {
				for(int c=b+1;c<list.size();c++) {
					int wallx1 = list.get(a).x;
					int wally1 = list.get(a).y;
					int wallx2 = list.get(b).x;
					int wally2 = list.get(b).y;
					int wallx3 = list.get(c).x;
					int wally3 = list.get(c).y;
					
					for(int i =0;i<N;i++) {
						for(int j=0;j<M;j++) {
							wallmap[i][j] = map[i][j];
							if(wallmap[i][j] == 2)
								virus.add(new Pair(i,j));
						}
					}
					
					wallmap[wallx1][wally1] = 1;
					wallmap[wallx2][wally2] = 1;
					wallmap[wallx3][wally3] = 1;
					
					BFS();
					
				}
			}
		}
		
		System.out.println(max);
		
	}
	
	public static void BFS() {
		
		while(!virus.isEmpty()) {
			Pair pair = virus.poll();
			int x = pair.x;
			int y = pair.y;
			
			for(int i =0;i<4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx >=0 && ny >=0 && nx < N && ny < M) {
					if(wallmap[nx][ny] == 0) {
						wallmap[nx][ny] = 2;
						virus.add(new Pair(nx,ny));
					}
				}
			}
		}
		
		int safe = 0;
		for(int i =0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(wallmap[i][j] == 0)
					safe++;
			}
		}
		max = Math.max(max, safe);
	}
	
	public static class Pair {
		int x, y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}

}
