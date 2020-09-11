package JW._8_28;

import java.util.Arrays;

//�̰� ������ ��� õ��?? �˰��� ¯�̴� O(N^2)�� �� ���ϼ� �־���
public class ����Ʈ {

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
