package JW._8_25;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class ST_Q_4 {

	static int[] priorities = {2, 1, 3, 2};
	static int location = 2;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(priorities, location));
	}
	
	public static int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<info> list = new LinkedList<info>();
        ArrayList<info> result = new ArrayList<info>();
        
        for(int i=0;i<priorities.length;i++) {
        	list.add(new info(i, priorities[i]));
        }
        
        while(!list.isEmpty()) {
        	int max = 0;
        	int maxcount = 0;
        	int size = list.size();
        	for(int i=0;i<size;i++) {
        		info a = list.poll();
        		if(max <= a.pr) {
        			if(max < a.pr) {
        				max = a.pr;
        				maxcount = 1;
        			}
        			else if(max == a.pr) {
        				maxcount++;
        			}
        		}
        		list.add(a);
        	}
        	
        	for(int i=0;i<size;i++) {
        		info a = list.poll();
        		if(a.pr == max) {
        			result.add(a);
        			maxcount--;
        			if(maxcount == 0)
        				break;
        			else
        				continue;
        		}
        		list.add(a);
        	}
        	
        }
        
        for(int i=0;i<result.size();i++) {
        	info a = result.get(i);
        	if(a.idx == location) {
        		answer = i+1;
        		break;
        	}
        }
        return answer;
    }
	
	public static class info{
		int idx, pr;
		info(int idx, int pr){
			this.idx = idx;
			this.pr = pr;
		}
	}

}
