package JW._8_28;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class 디스크컨트롤러 {

	static int[][] jobs = {{0, 3}, {1, 9}, {2, 6}};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(solution(jobs));

	}
	
	public static int solution(int[][] jobs) {
        int answer = 0;
        
        int complete = 0;
        int seconds = 0;
        int sum =0;
        PriorityQueue<start> work = new PriorityQueue<start>();
        PriorityQueue<time> time = new PriorityQueue<time>();
        
        Queue<Q> q = new LinkedList();
        
        for(int i=0;i<jobs.length;i++) {
        	work.add(new start(jobs[i][0], jobs[i][1]));
        }
        
        while(complete != jobs.length) {
        	
        	while(!work.isEmpty()) {
        		if(seconds != work.peek().s)
        			break;
        		start st = work.poll();
        		time.add(new time(st.s, st.time));
        	}
        	
        	if(!q.isEmpty()) {
        		if(seconds == q.peek().in +q.peek().time) {
        			sum += seconds - q.peek().s;
        			q.poll();
        			complete++;
        		}
        	}
        	
        	if(q.isEmpty()) {
        		if(!time.isEmpty()) {
        			time t = time.poll();
        			q.add(new Q(t.s, t.time, seconds));
        		}
        	}
        	
        	
        	
        	seconds++;
        }
        
        answer = (int) Math.floor(sum / jobs.length);
        return answer;
    }

	public static class start implements Comparable<start> {
		int s, time;
		start(int s, int time){
			this.s = s;
			this.time = time;
		}
		@Override
		public int compareTo(start o) {
			// TODO Auto-generated method stub
			return this.s - o.s;
		}
	}
	
	public static class time implements Comparable<time> {
		int s, time;
		time(int s, int time){
			this.s = s;
			this.time = time;
		}
		@Override
		public int compareTo(time o) {
			// TODO Auto-generated method stub
			return this.time - o.time;
		}
	}
	
	public static class Q{
		int s, time, in;
		Q(int s, int time, int in){
			this.s = s;
			this.time = time;
			this.in = in;
		}
	}
}
