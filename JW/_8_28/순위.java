package JW._8_28;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class ¼øÀ§ {
	
	static int n = 5;
	static int[][] results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(n, results));

	}
	
	public static int solution(int n, int[][] results) {
        int answer = 0;
        int count = 0;
        boolean[] visited = new boolean[n+1];
        
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        ArrayList<HashSet<Integer>> win = new ArrayList<HashSet<Integer>>();
        
        Queue<Integer> q = new LinkedList<Integer>();
        
        for(int i=0;i<=n;i++) {
        	list.add(new ArrayList<Integer>());
        	win.add(new HashSet<Integer>());
        }
        
        for(int i=0;i<results.length;i++) {
        	int a = results[i][0];
        	int b = results[i][1];
        	
        	list.get(b).add(a);
        }
        
        while(true) {
        	for(int i=1;i<=n;i++) {
        		if(list.get(i).isEmpty() && visited[i] == false) {
        			q.add(i);
        		}
        	}
        	
        	int size = q.size();
        	if(size == 0)
        		break;
        	count += size;
        	for(int i=0;i<size;i++) {
        		int num = q.poll();
        		visited[num] = true;
        		
        		if(count-1 == win.get(num).size())
        			answer++;
        		
        		for(int j=1;j<=n;j++) {
        			if(list.get(j).contains(num)) {
        				list.get(j).remove((Integer)num);
        				win.get(j).add(num);
        				win.get(j).addAll(win.get(num));
        			}
        		}
        	}
        }
        return answer;
    }

}
