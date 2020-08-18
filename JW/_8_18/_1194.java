package JW._8_18;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//�� �� : ������ �̵��� �� �ִ�. ('.���� ǥ�õ�)
//�� : ���� �̵��� �� ����. (��#��)
//���� : ������ �̵��� �� �ִ�. �� ���� ó�� ���� ���踦 ���´�. (a - f)
//�� : �����ϴ� ���谡 ���� ���� �̵��� �� �ִ�. (A - F)
//�ν����� ���� ��ġ : �� ���̰�, �ν��̰� ���� �� �ִ� ���̴�. (���� 0)
//�ⱸ : ���� �������� ������, �ν��̰� �����ϴ� ���̴�. �� ���� ���� �̷θ� Ż���Ѵ�. (���� 1)

public class _1194 {

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub'
		
		int N, M;
		int ans = 0;
		int startx = 0, starty = 0;
		
		String[][] map;
		
		Queue<Pair> q = new LinkedList<Pair>();
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		s.nextLine();
		
		boolean[][][] visited = new boolean[N][M][64];
		map = new String[N][M];
		
		for(int i=0;i<N;i++) {
			String[] tmp = s.nextLine().split("");
			for(int j=0;j<M;j++) {
				map[i][j] = tmp[j];
				if(map[i][j].equals("0")) {
					startx = i;
					starty = j;
				}
			}
		}
		
		
		q.add(new Pair(startx, starty, 0, 0));
		visited[startx][starty][0] = true;
		while(!q.isEmpty()) {
			
			Pair p = q.poll();
			
			int x = p.x;
			int y = p.y;
			int key = p.key;
			int count = p.count;
			
			for(int i =0;i<4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int ckey = key;
				if(nx >=0 && ny >=0 && nx<N && ny <M) {
					
					char c = map[nx][ny].charAt(0);
					
					// . �ƽ�Ű �ڵ� 46 �Ǵ� 0 �ƽ�Ű �ڵ� 48 ��
					if(c == 46 || c == 48) {
						
					}
					
					// # �ƽ�Ű �ڵ� 35 ��
					else if(c == 35)
						continue;
					
					// a ~ f Ű
					else if(c >= 97 && c <= 102) {
						ckey = ckey | (1 << c - 'a');
					}
					// A ~ F ��
					else if(c >= 65 && c <= 70) {
						if((ckey & (1 << c - 'A')) == 0)
							continue;
					}
					// 1 �ƽ�Ű �ڵ� 49 �ⱸ
					else if(c == 49) {
						System.out.println(count + 1);
						return;
					}
					
					if(visited[nx][ny][ckey])
						continue;
					
					visited[nx][ny][ckey] = true;
					
					q.add(new Pair(nx, ny, ckey, count + 1));
				}
			}
			
		}
		
		System.out.println(-1);
	}
	
	public static class Pair{
		int x, y, key, count;
		
		Pair(int x, int y, int key, int count){
			this.x = x;
			this.y = y;
			this.key = key;
			this.count = count;
		}
	}

}

/*
static int[] dx = {1, 0, -1, 0};
static int[] dy = {0, -1, 0, 1};

public static void main(String[] args) {
	// TODO Auto-generated method stub'
	
	int N, M;
	int ans = 0;
	int startx = 0, starty = 0;
	
	String[][] map;
	boolean[] key = new boolean[6];
	Queue<Pair> q = new LinkedList<Pair>();
	
	Scanner s = new Scanner(System.in);
	
	N = s.nextInt();
	M = s.nextInt();
	s.nextLine();
	
	map = new String[N][M];
	
	for(int i=0;i<N;i++) {
		String[] tmp = s.nextLine().split("");
		for(int j=0;j<M;j++) {
			map[i][j] = tmp[j];
			if(map[i][j].equals("0")) {
				startx = i;
				starty = j;
			}
		}
	}
	
	while(true) {
		
		q.clear();
		if(map[startx][starty].equals("1"))
			break;
		boolean[][] visited = new boolean[N][M];
		q.add(new Pair(startx, starty, 0));
		visited[startx][starty] = true;
		
		boolean flag = false;
		
		while(!q.isEmpty()) {
			
			if(flag)
				break;
			Pair p = q.poll();
			
			int x = p.x;
			int y = p.y;
			int count = p.count;
			
			for(int i =0;i<4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx >=0 && ny >=0 && nx<N && ny <M) {
					if(visited[nx][ny])
						continue;
					visited[nx][ny] = true;
					
					char c = map[nx][ny].charAt(0);
					// . �ƽ�Ű �ڵ� 46 �Ǵ� 0 �ƽ�Ű �ڵ� 48 ��
					if(c == 46 || c == 48) {
						q.add(new Pair(nx, ny, count + 1));
					}
					// # �ƽ�Ű �ڵ� 35 ��
					else if(c == 35)
						continue;
					// a ~ f Ű
					else if(c >= 97 && c<= 102) {
						int idx = c - 'a';
						if(key[idx])
							continue;
						else {
							key[idx] = true;
							ans += count + 1;
							startx = nx;
							starty = ny;
							flag = true;
							break;
						}
					}
					// A ~ F ��
					else if(c >= 65 && c <= 70) {
						int idx = c - 'A';
						if(key[idx]) {
							q.add(new Pair(nx, ny, count + 1));
						}
						else
							continue;
					}
					// 1 �ƽ�Ű �ڵ� 49 �ⱸ
					else if(c == 49) {
						ans += count + 1;
						System.out.println(ans);
						return;
					}
				}
			}
		}
		if(!flag) {
			ans = -1;
			System.out.println(ans);
			return;
		}
		
	}
	
}

public static class Pair{
	int x, y, count;
	
	Pair(int x, int y, int count){
		this.x = x;
		this.y = y;
		this.count = count;
	}
}
*/