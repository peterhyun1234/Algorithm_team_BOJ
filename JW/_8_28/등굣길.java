package JW._8_28;

import java.util.LinkedList;
import java.util.Queue;

//m , n Çò°¥¸®Áö ¾Ê°Ô!!
public class µî±·±æ {

	static int m = 4;
	static int n = 4;
	static int[][] puddles = {{3,2}, {2,4}};
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(m, n, puddles));

	}
	public static int solution(int m, int n, int[][] puddles) {
		int answer = 0;
        Queue<Pair> q = new LinkedList<Pair>();
        boolean[][] visited = new boolean[n][m];
        int[][] DP = new int[n][m];
        
        
        for(int i=0;i<puddles.length;i++) {
        	int waterx = puddles[i][0];
        	int watery = puddles[i][1];
        	
        	DP[watery-1][waterx-1] = -1;
        	visited[watery-1][waterx-1] = true;
        }
        
        q.add(new Pair(0,0));
        DP[0][0] = 1;
        
        while(!q.isEmpty()) {
        	Pair p = q.poll();
        	int x = p.x;
        	int y = p.y;
        	
        	if(visited[x][y])
        		continue;
        	
        	for(int i=0;i<4;i++) {
        		int nx = x + dx[i];
        		int ny = y + dy[i];
        		
        		if(nx >=0 && ny >= 0 && nx < n && ny < m) {
        			if(visited[nx][ny] == false) {
        				DP[nx][ny] = DP[nx][ny] + DP[x][y] % 1000000007;
        				q.add(new Pair(nx, ny));
        			}
        		}
        	}
        	visited[x][y] = true;
        }
        
        answer = DP[n-1][m-1] % 1000000007;
        return answer;
    }
	
	
	public static class Pair{
		int x, y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	

}
	
	/*
	 * int answer = 0;
       
        int[][] DP = new int[n+1][m+1];
        
        for(int i=0;i<puddles.length;i++) {
        	DP[puddles[i][1]][puddles[i][0]] = -1;
        }
        
        DP[1][1] = 1;
        
        for(int i=1;i<=n;i++) {
        	for(int j=1;j<=m;j++) {
        		if(DP[i][j] == -1)
        			continue;
        		
        		if(i-1 > 0 && DP[i-1][j] != -1)
        			DP[i][j] += DP[i-1][j] % 1000000007;
        		if(j-1 > 0 && DP[i][j-1] != -1)
        			DP[i][j] += DP[i][j-1] % 1000000007;
        	}
        }
        
        answer = DP[n][m] % 1000000007;
        return answer;
    }*/