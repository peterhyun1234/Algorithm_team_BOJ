package JW._8_25;

import java.util.ArrayList;

public class St_Q_2 {

	static int[] progresses = {93,30,66,96,97,98,92,94};
	static int[] speeds = {1,30,5,1,1,1,1,1};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(int ans : solution(progresses, speeds)) {
			System.out.println(ans);
		}

	}
	public static int[] solution(int[] progresses, int[] speeds) {
		int[] answer;
        int[] remain = new int[progresses.length];
        
        for(int i=0;i<progresses.length;i++) {
        	remain[i] = (int) Math.ceil((100 - (double)progresses[i]) / (double)speeds[i]);
        }
        int cur = remain[0];
        int count = 0;
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        
        for(int i=0;i<remain.length;i++) {
        	if(cur < remain[i]) {
        		result.add(count);
        		cur = remain[i];
        		count = 0;
        	}
        	count++;
        }
        result.add(count);
        
        answer = new int[result.size()];
        for(int i=0;i<result.size();i++) {
        	answer[i] = result.get(i);
        }
        return answer;
    }
}
