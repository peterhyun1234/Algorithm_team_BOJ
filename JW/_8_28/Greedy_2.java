package JW._8_28;

public class Greedy_2 {

	static String number = "4177252841";
	static int k = 4;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(number, k));

	}

	public static String solution(String number, int k) {
        String answer = "";
        
        StringBuilder sb = new StringBuilder();
        int idx = 0;
        int K = number.length() - k;
        for(int i=1;i<=K;i++) {
        	
        	int large = -1;
        	
        	for(int j=idx;j<number.length()-K+i;j++) {
        		if(number.charAt(j) -'0' > large) {
        			large = number.charAt(j) - '0';
        			idx = j;
        		}
        	}
        	sb.append(large);
        	idx++;
        }
        answer = sb.toString();
        return answer;
    }
}
