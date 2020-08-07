package JW._8_07;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//처음부터 다시 풀어보기
public class _19238 {

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int[][] map;
	static boolean[][] visited;
	static int N, M;
	static ArrayList<Pair> customer;
	static ArrayList<Pair> dest;
	static ArrayList<IwantCompare> distance;
	static Queue<Pair> q = new LinkedList<Pair>();
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int fuel;
		
		Pair car;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		fuel = s.nextInt();
		
		map = new int[N][N];
		
		
		customer = new ArrayList<Pair>();
		dest = new ArrayList<Pair>();
		distance = new ArrayList<IwantCompare>();
		
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				map[i][j] = s.nextInt();
			}
		}
		
		int x = s.nextInt();
		int y = s.nextInt();
		
		car = new Pair(x-1, y-1);
		
		for(int i =0;i<M;i++) {
			int cx = s.nextInt();
			int cy = s.nextInt();
			int dx = s.nextInt();
			int dy = s.nextInt();
			customer.add(new Pair(cx-1, cy-1));
			dest.add(new Pair(dx-1, dy-1));
		}
		
		q.add(new Pair(car.x, car.y));
		visited = new boolean[N][N];
		visited[car.x][car.y] = true;
		for(int i=0;i<M;i++) {
			
			BFS();
			q.clear();
			
			//정렬
			Collections.sort(distance, new Comparator<IwantCompare>() {

				int ret = 0;
				@Override
				public int compare(IwantCompare o1, IwantCompare o2) {
					// TODO Auto-generated method stub
					
					if(o1.distance < o2.distance)
						ret = -1;
					else if(o1.distance == o2.distance) {
						if(o1.x < o2.x)
							ret = -1;
						else if(o1.x == o2.y) {
							if(o1.y > o2.y) {
								ret = -1;
							}
							else if(o1.y == o2.y) {
								ret = 0;
							}
							else 
								ret = 1;
						}
						else
							ret = 1;
					}
					else
						ret = 1;
					return ret;
				}
			});
			
			if(distance.isEmpty()) {
				fuel = -1;
				break;
			}
			int a = distance.get(0).x;
			int b = distance.get(0).y;
			int f = distance.get(0).distance;
			int idx = distance.get(0).idx;
			
			int destX = dest.get(idx).x;
			int destY = dest.get(idx).y;
			fuel = fuel - f;
			if(fuel <= 0) {
				fuel = -1;
				break;
			}
			visited = new boolean[N][N];
			visited[a][b] = true;
			int ee = FindDest(a, b, destX, destY, idx);
			fuel = fuel - ee;
			if(fuel < 0) {
				fuel = -1;
				break;
			}
			fuel = fuel + ee*2;
			customer.remove(idx);
			dest.remove(idx);
			q.clear();
			distance.clear();
			
			q.add(new Pair(destX, destY));
			visited = new boolean[N][N];
			visited[destX][destY] = true;
		}
		
		System.out.println(fuel);
	}
	
	public static void BFS() {
		
		//목적지와 출발지가 같을때
		Pair Sameplace = q.peek();
		for(int j =0;j<customer.size();j++) {
			if(customer.get(j).x == Sameplace.x && customer.get(j).y == Sameplace.y) {
				distance.add(new IwantCompare(Sameplace.x, Sameplace.y, 0, j));
			}
		}
		
		int count = 1;
		
		while(!q.isEmpty()) {
			
			int qsize = q.size();
			for(int a =0;a<qsize;a++) {
				Pair car = q.poll();
				for(int i =0;i<4;i++) {
					int x = car.x + dx[i];
					int y = car.y + dy[i];
			
					// 맵 밖으로 안나가게
					if(x >= 0 && y >= 0 && x < N && y < N) {
						//방문 했거나 벽인 경우
						if(visited[x][y] == false && map[x][y] != 1) {
							visited[x][y] = true;
							//손님인 경우
							for(int j =0;j<customer.size();j++) {
								if(customer.get(j).x == x && customer.get(j).y == y) {
									distance.add(new IwantCompare(x, y, count, j));
								}
							}
						
							q.add(new Pair(x, y));
						}
					}
				}
			}
			count += 1;
		}
	}

	public static int FindDest(int x, int y, int desX, int desY, int idx) {
		
		int count = 1;
		q.add(new Pair(x, y));
		while(!q.isEmpty()) {
			
			int qsize = q.size();
			for(int a =0;a<qsize;a++) {
				Pair car = q.poll();
				for(int i =0;i<4;i++) {
					int nx = car.x + dx[i];
					int ny = car.y + dy[i];
			
					// 맵 밖으로 안나가게
					if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
						//방문 했거나 벽인 경우
						if(visited[nx][ny] == false && map[nx][ny] != 1) {
							visited[nx][ny] = true;
							//손님인 경우
							
							if(desX == nx && desY == ny) {
								return count;
							}
							
						
							q.add(new Pair(nx, ny));
						}
					}
				}
			}
			count += 1;
		}
		return count;
	}
	
	
	public static class IwantCompare{
		int x, y, distance, idx;
		IwantCompare(int x, int y, int distance, int idx) {
			this.x = x;
			this.y = y;
			this.distance = distance;
			this.idx = idx;
		}
	}
	
	public static class Pair{
		int x, y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
}
