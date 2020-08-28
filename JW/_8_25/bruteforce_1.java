package JW._8_25;

public class bruteforce_1 {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] answers = {1, 3, 2, 4, 2};
		System.out.println(solution(answers));

	}
	
	public static int[] solution(int[] answers) {
		int max = 0;
		
		int[] one = {1, 2, 3, 4, 5};
		int[] two = {2, 1, 2, 3, 2, 4, 2, 5};
		int[] three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
		
        int[] answer = {};
        
        int[] count = new int[3];
        
        for(int i=0;i<answers.length;i++) {
        	//1
        	if(answers[i] == one[i%5])
        		count[0]++;
        	if(answers[i] == two[i%8])
        		count[1]++;
        	if(answers[i] == three[i%10])
        		count[2]++;
        }
        
        for(int i=0;i<3;i++) {
        	max = Math.max(max, count[i]);
        }
        int idx=0;
        for(int i=0;i<3;i++) {
        	if(max == count[i]) {
        		idx++;
        	}
        }
        answer = new int[idx];
        idx = 0;
        for(int i=0;i<3;i++) {
        	if(max == count[i]) {
        		answer[idx] = i+1;
        		idx++;
        	}
        }
        return answer;
    }

}
