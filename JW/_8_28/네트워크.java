package JW._8_28;

import java.util.LinkedList;
import java.util.Queue;

public class 네트워크 {

	static int[][] computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	static int n = 3;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(n, computers));
		
	}
	
	public static int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visited = new boolean[n+1];
        
        Queue<Integer> q = new LinkedList<Integer>();
        
        
        for(int i=1;i<=n;i++) {
        	if(visited[i])
        		continue;
        	
        	q.add(i);
        	visited[i] = true;
        	
        	while(!q.isEmpty()) {
        		int computer = q.poll();
        		
        		for(int j=1;j<=n;j++) {
        			
        			if(computer == j)
        				continue;
        			
        			if(computers[computer-1][j-1] == 1 && visited[j] != true) {
        				q.add(j);
        			}
        		}
        		
        		visited[computer] = true;
        	}
        	answer++;
        }
        
        return answer;
    }

}
