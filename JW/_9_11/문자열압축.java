package JW._9_11;


public class 문자열압축 {

	static String s = "aabbaccc";
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(s));

	}

	public static int solution(String s) {
        int answer = s.length();
        
        for(int i=1;i<=s.length()/2;i++) {
        	String result = "";
        	String compare = "";
        	int count = 1;
        	for(int j=0;j<(int)Math.ceil((double)s.length()/(double)i);j++) {
        		String tmp;
        		if((j+1)*i > s.length()-1)
        			tmp = s.substring(j*i, s.length());
        		
        		else
        			tmp = s.substring(j*i, (j+1)*i);
        		
        		if(compare.equals(tmp)) {
        			count++;
        		}
        		else {
        			if(count == 1) {
        				result += compare;
        				compare = "" + tmp;
        			}
        			else {
        				result += count + compare;
        				count = 1;
        				compare = "" + tmp;
        			}
        		}
        		
        	}
        	
        	if(count == 1) {
				result += compare;
			}
			else {
				result += count + compare;
			}
        	answer = Math.min(answer, result.length());
        	
        }
        return answer;
    }
}
