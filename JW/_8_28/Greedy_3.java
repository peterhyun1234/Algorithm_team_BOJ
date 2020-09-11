package JW._8_28;

public class Greedy_3 {

	static String name = "JAACAZ";
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		solution(name);

	}
	
	public static int solution(String name) {
        int answer = 0;
        String alpha = "";
        
        StringBuilder sb = new StringBuilder();
        
        for(int i=0;i<name.length();i++) {
        	sb.append("A");
        }
        alpha = String.valueOf(sb);
        
        if(name.charAt(0) != 'A') {
        	answer += chagealpha(name.charAt(0));
        	name = "A" + name.substring(1, name.length());
        }
        int curidx = 0;
        while(!name.equals(alpha)) {
        	int leftcount = 0;
        	int rightcount = 0;
        	
        	if(name.equals(alpha))
        		break;
        	
        	int leftidx = curidx;
        	while(true) {
        		if(name.charAt(leftidx) != 'A')
        			break;
        		if(leftidx == 0)
        			leftidx = name.length();
        		leftidx--;
        		leftcount++;
        	}
        	int rightidx = curidx;
        	while(true) {
        		if(name.charAt(rightidx) != 'A')
        			break;
        		if(rightidx == name.length() -1)
        			rightidx = -1;
        		rightidx++;
        		rightcount++;
        	}
        	
        	if(rightcount <= leftcount) {
        		curidx = rightidx;
        		answer += rightcount;
        	}
        	else {
        		curidx = leftidx;
        		answer += leftcount;
        	}
        	
        	answer += chagealpha(name.charAt(curidx));
        	name = name.substring(0, curidx) + "A" + name.substring(curidx+1, name.length());
        }
        return answer;
    }
	
	public static int chagealpha(char c) {
		int up = 0;
		int down = 0;
		
		up = 'Z' - c + 1;
		down = c - 'A';
		
		return Math.min(up, down);
	}

}
