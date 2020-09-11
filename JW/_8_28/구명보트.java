package JW._8_28;

import java.util.Arrays;

//이거 생각한 사람 천재?? 알고리즘 짱이다 O(N^2)을 더 줄일수 있었음
public class 구명보트 {

	static int[] people = {70, 50, 80, 50};
	static int limit = 100;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(solution(people, limit));
	}

	public static int solution(int[] people, int limit) {
	        int answer = 0;
	        
	        Arrays.sort(people);
	        
	        int i =0;
	        int j;
	        for(j=people.length-1;j>=i;j--) {
	        	if(people[i] + people[j] > limit) {
	        		answer++;
	        	}
	        	else {
	        		answer++;
	        		i++;
	        	}
	        }
	        
	        if(i==j)
	        	answer++;
	        
	        return answer;
	}
}
