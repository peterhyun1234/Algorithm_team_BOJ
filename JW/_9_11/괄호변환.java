package JW._9_11;

import java.util.Stack;

public class °ýÈ£º¯È¯ {

	static String p = ")(";
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(p));

	}

	public static String solution(String p) {
        String answer = "";
        
        if(check(p))
        	return p;
        
        return recursive(p);
    }
	
	public static String recursive(String s) {
		
		if(s.equals(""))
			return s;
		String u = "";
		String v = "";
		
		int Lcount = 0;
		int Rcount = 0;
		
		int idx = 0;
		do {
			char c = s.charAt(idx++);
			if(c == '(') {
				Lcount++;
			}
			else if(c == ')') {
				Rcount++;
			}
			
			u += c;
		}while(Lcount != Rcount);
		
		v = s.substring(Lcount+Rcount, s.length());
		if(check(u)) {
			u += recursive(v);
			return u;
		}
		else {
			String tmp = "(" + recursive(v) + ")";
			String utmp = "";
			for(int i=1;i<u.length()-1;i++) {
				if(u.charAt(i) == '(')
					utmp += ")";
				else if(u.charAt(i) == ')')
					utmp += "(";
			}
			
			return tmp + utmp;
		}
	}
	
	public static boolean check(String s) {
		Stack<String> st = new Stack();
		
		for(int i=0;i<s.length();i++) {
			char c = s.charAt(i);
			if(c == '(')
				st.push(String.valueOf(c));
			
			else if(c == ')') {
				if(st.isEmpty())
					return false;
				st.pop();
			}
		}
		
		if(!st.isEmpty())
			return false;
		
		return true;
	}
}
