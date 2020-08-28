package JW._8_25;

import java.util.Collections;
import java.util.PriorityQueue;

public class Heap_3 {

	static String[] operations = {"I 7","I 5", "I -5","I -5","D -1"};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(int ans : solution(operations)) {
			System.out.println(ans);
		}

	}

	public static int[] solution(String[] operations) {
        int[] answer = new int[2];
        
        PriorityQueue<Integer> max = new PriorityQueue<Integer>(Collections.reverseOrder());
        PriorityQueue<Integer> min = new PriorityQueue<Integer>();
        
        for(int i=0;i<operations.length;i++) {
        	String[] tmp = operations[i].split(" ");
        	String c = tmp[0];
        	int num = Integer.parseInt(tmp[1]);
        	
        	if(c.equals("I")) {
        		max.add(num);
        		min.add(num);
        	}
        	else if(c.equals("D")) {
        		if(num == 1) {
        			if(!max.isEmpty()) {
        				int maxvalue = max.poll();
        				min.remove(maxvalue);
        			}
        		}
        		else if(num == -1) {
        			if(!min.isEmpty()) {
        				int minvalue = min.poll();
        				max.remove(minvalue);
        			}
        		}
            }
        }
        
        if(max.isEmpty()) {
        	answer[0] = 0;
        	answer[1] = 0;
        }
        else {
        	answer[0] = max.peek();
        	answer[1] = min.peek();
        }
        return answer;
    }
}
