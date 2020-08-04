package JW._8_04;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _7569 {

	static int[] dx = {0, 1, 0, 0, -1, 0}; //H
	static int[] dy = {0, 0, 1, 0, 0, -1}; //N
	static int[] dz = {1, 0, 0, -1, 0, 0}; //M
	static int day = -1;
	static Queue<Pair> q = new LinkedList<Pair>();
	
	static int[][][] box;
	static int M, N, H;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Scanner s = new Scanner(System.in);
		
		M = s.nextInt();
		N = s.nextInt();
		H = s.nextInt();
		
		box = new int[H][N][M];
		
		for(int i=0;i<H;i++) {
			for(int j=0;j<N;j++) {
				for(int k=0;k<M;k++) {
					box[i][j][k] = s.nextInt();
					if(box[i][j][k] == 1)
						q.add(new Pair(i, j, k));
				}
			}
		}
		
		BFS();

		System.out.println(day);
	}
	
	public static void BFS() {
		
		while(!q.isEmpty()) {
			int qsize = q.size();
			for(int i = 0;i<qsize;i++){
				Pair pair = q.poll();
				
				int a = pair.x;
				int b = pair.y;
				int c = pair.z;
				
				for(int j=0;j<6;j++) {
					int nx = a + dx[j];
					int ny = b + dy[j];
					int nz = c + dz[j];
					
					if(nx >=0 && ny >=0 && nz >=0 && nx < H && ny < N && nz < M) {
						if(box[nx][ny][nz] == 0) {
							box[nx][ny][nz] = 1;
							q.add(new Pair(nx, ny, nz));
						}
					}
				}
			}
			
			day++;
		}
		
		for(int i = 0;i<H;i++) {
			for(int j=0;j<N;j++) {
				for(int k=0;k<M;k++) {
					if(box[i][j][k] == 0) {
						day = -1;
						break;
					}
				}
				if(day == -1)
					break;
			}
			if(day == -1)
				break;
		}
	}

	public static class Pair{
		int x, y, z;
		
		Pair(int x, int y, int z){
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}
}
