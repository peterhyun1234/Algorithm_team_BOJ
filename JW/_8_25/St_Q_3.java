package JW._8_25;

import java.util.LinkedList;
import java.util.Queue;

public class St_Q_3 {

	static int bridge_length = 100;
	static int weight = 100;
	static int[] truck_weights = {10,10,10,10,10,10,10,10,10,10};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(solution(bridge_length, weight, truck_weights));

	}

	public static int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int ALLSUM = 0;
        int sum = 0;
        int seconds = 1;
        int Cur_weight = 0;
        int idx = 0;
        
        for(int i=0;i<truck_weights.length;i++) {
        	ALLSUM += truck_weights[i];
        }
        
        Queue<Pair> q = new LinkedList<Pair>();
        
        while(sum < ALLSUM) {
        	
        	if(!q.isEmpty()) {
        		if(seconds - q.peek().seconds == bridge_length) {
        			Pair p = q.poll();
        			sum += p.weight;
        			if(sum >= ALLSUM) {
        				answer = seconds;
        				break;
        			}
        			Cur_weight -= p.weight;
        		}
        	}
        	if(weight >= Cur_weight + truck_weights[idx] && q.size() < bridge_length) {
        		Cur_weight += truck_weights[idx];
        		q.add(new Pair(truck_weights[idx], seconds));
        		idx = Math.min(idx+1, truck_weights.length-1);
        	}
        	
        	seconds++;
        }
        
        return answer;
    }
	
	public static class Pair{
		int weight, seconds;
		Pair(int weight, int seconds){
			this.weight = weight;
			this.seconds = seconds;
		}
	}
}
