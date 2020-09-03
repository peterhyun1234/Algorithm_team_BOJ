package JW._8_25;

import java.util.PriorityQueue;

public class Heap_1 {

	static int[] scoville = {0,0,0,0};
	static int K = 7;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(scoville, K));

	}

	public static int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> q = new PriorityQueue<Integer>();
        
        for(int i=0;i<scoville.length;i++) {
        	q.add(scoville[i]);
        }
        while(q.peek() < K) {
        	if(q.size() == 1) {
        		answer = -1;
        		break;
        	}
        	int s1 = q.poll();
        	int s2 = q.poll();
        	
        	q.add(s1+s2*2);
        	answer++;
        }
        
        return answer;
    }
}
