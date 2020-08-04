package JW._8_04;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//3차원 문제 x, y, 방향 토마토 3차원과 비슷하지만 조금 다름 생각하기가 어려움
public class _1726 {

	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};
	
	static Pair start, end;
	static boolean[][][] visited;
	static int N, M;
	static int[][] map;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);

		N = s.nextInt();
		M = s.nextInt();
		
		map = new int[N][M];
		
		visited = new boolean[N][M][5];
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<M;j++) {
				map[i][j] = s.nextInt();
			}
		}
		
		int x = s.nextInt();
		int y = s.nextInt();
		int d = s.nextInt();
		start = new Pair(x-1, y-1, d, 0);
		
		x = s.nextInt();
		y = s.nextInt();
		d = s.nextInt();
		end = new Pair(x-1, y-1, d, 0);
		
		BFS();
		
	}
	
	public static void BFS() {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(start);
		visited[start.x][start.y][start.dir] = true;
		
		while(!q.isEmpty()) {
			Pair pair = q.poll();
			int x = pair.x;
			int y = pair.y;
			int dir = pair.dir;
			int cnt = pair.cnt;
			
			if(x == end.x && y == end.y && dir == end.dir) {
				System.out.println(cnt);
				return;
			}
			//3칸까지 갈수 있음
			for(int i =1;i<=3;i++) {
				int nx = x + dx[dir-1] * i;
				int ny = y + dy[dir-1] * i;
				if(nx >= 0 && ny >= 0 && nx < N & ny < M) {
					if(map[nx][ny] == 0) {
						if(visited[nx][ny][dir] == false)
							q.add(new Pair(nx,ny,dir,cnt+1));
					}
					//못지나가면 바로 break 1칸이 안되면 2칸, 3칸도 안됨
					else
						break;
				}
			}
			
			for(int i =1;i<=4;i++) {
				int cdir = (dir + i) % 4 + 1;
				if(visited[x][y][cdir] == false) {
					visited[x][y][cdir] = true;
					// 180도 회전은 명령을 두번 내려야함 
					if((cdir == 1 && dir == 2) || (cdir == 2 && dir == 1) || (cdir == 3 && dir == 4) || (cdir == 4 && dir == 3)) {
						q.add(new Pair(x, y, cdir, cnt+2));
					}
					else
						q.add(new Pair(x, y, cdir, cnt+1));
				}
			}
		}
		
		return;
	}

	public static class Pair{
		int x, y, dir, cnt;
		Pair(int x, int y, int dir, int cnt){
			this.x = x;
			this.y = y;
			this.dir = dir;
			this.cnt = cnt;
		}
	}
	
}
