package JW._8_28;

import java.util.Arrays;

public class Greedy_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        int[] student = new int[n];
        
        Arrays.fill(student, 1);
        
        for(int i=0;i<lost.length;i++) {
        	student[lost[i]-1]--;
        }
        for(int i=0;i<reserve.length;i++) {
        	student[reserve[i]-1]++;
        }
        for(int i=0;i<n;i++) {
        	if(student[i] == 0) {
        		if(i-1 >= 0) {
        			if(student[i-1] >= 2) {
        				student[i-1]--;
        				student[i]++;
        			}
        		}
        	}
        	
        	if(student[i] == 0) {
        		if(i+1 < n) {
        			if(student[i+1] >= 2) {
        				student[i+1]--;
        				student[i]++;
        			}
        		}
        	}
        }
        
        for(int i=0;i<n;i++) {
        	if(student[i] >= 1)
        		answer++;
        }
        return answer;
    }

}
