package JW._9_11;

import java.util.Arrays;

public class 외벽점검 {

	static int n = 12;
	static int[] weak = {1, 3, 4, 9, 10};
	static int[] dist = {3, 5, 7};
	static int[][] rotateweak;
	static int answer;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(n, weak, dist));

	}

	public static int solution(int n, int[] weak, int[] dist) {
        answer = -1;
        
        Arrays.sort(dist);
        
        rotateweak = new int[weak.length][weak.length];
        
        for(int i=0;i<weak.length;i++) {
        	for(int j=0;j<weak.length;j++) {
        		rotateweak[i][j] = weak[j];
        	}
        	
        	int tmp = weak[0] + n;
			for(int j=1;j<weak.length;j++) {
				weak[j-1] = weak[j];
			}
			weak[weak.length-1] = tmp;
        }
        
        //i 는 사람 수
        for(int i=1;i<=dist.length;i++) {
        	int[] people = new int[i];
        	selectwall(people, 0, 0, new boolean[dist.length], dist);
        	if(answer != -1)
        		break;
        }
        return answer;
    }
	
	public static void selectwall(int[] people, int count, int idx, boolean[] visited, int[] dist) {
		
		if(count == dist.length || idx == people.length) {
			if(idx == people.length) {
				if(check(people)) 
					answer = idx;
			}
			return;
		}
		
		for(int i=0;i<dist.length;i++) {
			if(!visited[i]) {
				visited[i] = true;
				people[idx] = dist[i];
				selectwall(people, count+1, idx+1, visited, dist);
				visited[i] = false;
			}
		}
		
	}
	
	public static boolean check(int[] people) {
		//???
		for(int[] tmpweak : rotateweak) {
			int idx = 0, start = 0;
			boolean[] visited = new boolean[tmpweak.length];
			
			while(idx != people.length) {
				int i = start;
				int value = people[idx++];
				
				for(int j = start; j< tmpweak.length;j++) {
					if(!(tmpweak[i] <= tmpweak[j] && tmpweak[j] <= tmpweak[i] + value))
						break;
					visited[j] = true;
					start++;
				}
			}
			
			boolean flag = true;
			for(int i=0;i<tmpweak.length;i++) {
				if(!visited[i])
					flag = false;
			}
			
			if(flag)
				return true;
		}
		
		
		return false;
	}
}
