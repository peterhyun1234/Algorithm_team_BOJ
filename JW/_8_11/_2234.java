package JW._8_11;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;


public class _2234 {

	// 0 : 서, 1 :북, 2 : 동, 3 : 남
	static int[] dx = {0, -1, 0, 1};
	static int[] dy = {-1, 0, 1, 0};
	
	static int[] breaknum = {1, 2, 4, 8};
	
	static int[][] castle;
	static boolean[][] visited;
	static int maxsize = 0;
	static int n, m;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int roomcnt = 0;
		Scanner s = new Scanner(System.in);
		
		n = s.nextInt();
		m = s.nextInt();
		castle = new int[m][n];
		visited = new boolean[m][n];
		
		for(int i =0;i<m;i++) {
			for(int j=0;j<n;j++) {
				castle[i][j] = s.nextInt();
			}
		}
		
		for(int i =0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(!visited[i][j]) {
					BFS(i, j);
					roomcnt++;
				}
			}
		}
		
		System.out.println(roomcnt);
		System.out.println(maxsize);
		
		for(int i =0;i<m;i++) {
			for(int j =0;j<n;j++) {
				int wall = castle[i][j];
				
				for(int k =0;k<4;k++) {
					if((wall & (1 << k)) < 0) 
						continue;
						
					for (int l = 0; l < visited.length; l++)
	                    Arrays.fill(visited[l], false);
					castle[i][j] -= breaknum[k];
					BFS(i,j);
					castle[i][j] += breaknum[k];
				
				}

			}
		}
		
		System.out.println(maxsize);

	}
	
	public static void BFS(int x, int y) {
		int count = 0;
		Queue<room> q = new LinkedList<room>();
		visited[x][y] = true;
		q.add(new room(x, y, castle[x][y]));
		
		while(!q.isEmpty()) {
			room r = q.poll();
			int cx = r.x;
			int cy = r.y;
			int cwall = castle[r.x][r.y];
			
			//비트 연산??
			for(int i =0;i<4;i++) {
				if ((cwall & (1 << i)) > 0)
                    continue;
				
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				
				if(nx >= 0 && ny >= 0 && nx < m && ny < n && visited[nx][ny] == false) {
					visited[nx][ny] = true;
					q.add(new room(nx, ny, castle[nx][ny]));
				}
			
			}
			count++;
		}
		maxsize = Math.max(count, maxsize);
	}
	
	
	public static class room{
		int x, y;
		room(int x, int y, int wall){
			this.x = x;
			this.y = y;
		}
	}

}

/*import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;


public class Main {

	// 0 : 남, 1 :동, 2 : 북, 3 : 서
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	
	static int[][] castle;
	static boolean[][] visited;
	static int maxsize = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n, m;
		
		int roomcnt = 0;
		Scanner s = new Scanner(System.in);
		
		n = s.nextInt();
		m = s.nextInt();
		castle = new int[m][n];
		visited = new boolean[m][n];
		
		for(int i =0;i<m;i++) {
			for(int j=0;j<n;j++) {
				castle[i][j] = s.nextInt();
			}
		}
		
		for(int i =0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(!visited[i][j]) {
					BFS(i, j);
					roomcnt++;
				}
			}
		}
		
		System.out.println(roomcnt);
		System.out.println(maxsize);
		
		for(int i =0;i<m;i++) {
			for(int j =0;j<n;j++) {
				
				ArrayList<Integer> removewall = new ArrayList();
				removewall = haveD(castle[i][j]);
				//동 서 남 북 wall 삭제
				for(int k=0;k<removewall.size();k++) {
					int breakwall = removewall.get(k);

					// 0 : 남, 1 :동, 2 : 북, 3 : 서
					// 0 : 남쪽
					if(breakwall == 0) {
						//방이 남쪽 끝에 있을 경우
						if(i == m-1)
							continue;
						else {
							castle[i][j] -= 8;
							for (int l = 0; l < visited.length; l++)
			                    Arrays.fill(visited[l], false);
							BFS(i,j);
						}
						castle[i][j] += 8;
					}
					// 1 : 동쪽
					else if(breakwall == 1) {
						// 방이 동쪽 끝에 있을 경우
						if(j == n-1)
							continue;
						else {
							castle[i][j] -= 4;
							for (int l = 0; l < visited.length; l++)
			                    Arrays.fill(visited[l], false);
							BFS(i,j);
						}
						castle[i][j] += 4;
					}
					// 2: 북쪽
					else if(breakwall == 2) {
						// 방이 북쪽 끝에 있을 경우
						if(i == 0)
							continue;
						else {
							castle[i][j] -= 2;
							for (int l = 0; l < visited.length; l++)
			                    Arrays.fill(visited[l], false);
							BFS(i,j);
						}
						castle[i][j] += 2;
					}
					// 3: 서쪽
					else if(breakwall == 3) {
						// 방이 서쪽 끝에 있을 경우
						if(j == 0)
							continue;
						else {
							castle[i][j] -= 1;
							for (int l = 0; l < visited.length; l++)
			                    Arrays.fill(visited[l], false);
							BFS(i,j);
						}
						castle[i][j] += 1;
					}
				}

			}
		}
		
		System.out.println(maxsize);

	}
	
	public static void BFS(int x, int y) {
		int count = 0;
		Queue<room> q = new LinkedList<room>();
		visited[x][y] = true;
		q.add(new room(x, y, castle[x][y]));
		
		while(!q.isEmpty()) {
			room r = q.poll();
			int cx = r.x;
			int cy = r.y;
			int cwall = r.wall;
			ArrayList<Integer> direction = new ArrayList();
			
			direction = checkD(cwall);
			
			for(int i =0;i<direction.size();i++) {
				int nx = cx + dx[direction.get(i)];
				int ny = cy + dy[direction.get(i)];
				
				if(visited[nx][ny] == false) {
					visited[nx][ny] = true;
					q.add(new room(nx, ny, castle[nx][ny]));
				}
			}
			count++;
		}
		maxsize = Math.max(count, maxsize);
	}
	
	public static ArrayList<Integer> checkD(int wall) {
		ArrayList<Integer> direction = new ArrayList();

		for(int i =0;i<4;i++) {
			direction.add(i);
		}
		// 0 : 남, 1 :동, 2 : 북, 3 : 서
		if(wall >= 8) {
			wall = wall - 8;
			direction.remove((Integer)0);
		}
		if(wall >= 4) {
			wall = wall - 4;
			direction.remove((Integer)1);
		}
		if(wall >= 2) {
			wall = wall - 2;
			direction.remove((Integer)2);
		}
		if(wall >= 1) {
			wall = wall - 1;
			direction.remove((Integer)3);
		}
		
		return direction;
	}
	
	public static ArrayList<Integer> haveD(int wall) {
		ArrayList<Integer> direction = new ArrayList();

		// 0 : 남, 1 :동, 2 : 북, 3 : 서
		if(wall >= 8) {
			wall = wall - 8;
			direction.add(0);
		}
		if(wall >= 4) {
			wall = wall - 4;
			direction.add(1);
		}
		if(wall >= 2) {
			wall = wall - 2;
			direction.add(2);
		}
		if(wall >= 1) {
			wall = wall - 1;
			direction.add(3);
		}
		
		return direction;
	}
	
	public static class room{
		int x, y, wall;
		room(int x, int y, int wall){
			this.x = x;
			this.y = y;
			this.wall = wall;
		}
	}

}

}*/