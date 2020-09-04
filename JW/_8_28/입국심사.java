package JW._8_28;

import java.util.Arrays;

public class 입국심사 {

	static int n = 2;
	static int[] times = {1,2,2,2,100};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(n, times));

	}
	
	public static long solution(int n, int[] times) {
        long answer = 0;
        
        Arrays.sort(times);
        long left = 0;
        //int * int 할경우 long으로 변환해주어야함!!!!
        long right = (long)n*(long)times[times.length-1];
        
        answer = right;
        
        while(left <= right) {
        	long mid = (left + right) / 2;
        	
        	if(check(mid, times, n)) {
        		left = mid+1;
        	}
        	else {
        		answer = Math.min(answer, mid);
        		right = mid-1;
        	}
        }
        
        return answer;
    }

	public static boolean check(long mid, int[] times, int n) {
		long num = 0;
		
		for(int i=0;i<times.length;i++) {
			num += mid/times[i];
			if(num >= n)
				return false;
		}
		return true;
	}
}
