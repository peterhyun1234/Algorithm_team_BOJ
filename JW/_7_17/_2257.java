package JW._7_17;

import java.util.Scanner;
import java.util.Stack;

public class _2257 {

	static int result = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String input;
		Scanner s = new Scanner(System.in);
		int tmp = 0;
		int result = 0;
		input = s.nextLine();
		
		Stack<String> stack = new Stack<>();
		String[] inputList = new String[input.length()];
		inputList = input.split("");
		
		for(int i =0;i<input.length();i++) {
			String a = inputList[i];
			String p;
			
			if(a.equals("H") || a.equals("C") || a.equals("O") || a.equals("(")) {
				stack.push(a);
			}
			else if(a.equals(")")) {
				while(true) {
					p = stack.pop();
					
					if(p.equals("("))
						break;
					
					if(p.equals("H"))
						tmp = tmp + 1;
					else if(p.equals("C"))
						tmp = tmp + 12;
					else if(p.equals("O"))
						tmp = tmp + 16;
					else
						tmp = tmp + Integer.parseInt(p);
				}
				
				stack.push(Integer.toString(tmp));
				tmp = 0;
			}
			else {
				p = stack.pop();
				
				if(p.equals("H") || p.equals("C") || p.equals("O")) {
					if(p.equals("H"))
						tmp = tmp + 1;
					else if(p.equals("C"))
						tmp = tmp + 12;
					else if(p.equals("O"))
						tmp = tmp + 16;
					
					tmp = tmp * Integer.parseInt(a);
					stack.push(Integer.toString(tmp));
					tmp = 0;
				}
				else {
					
					tmp = tmp + Integer.parseInt(p) * Integer.parseInt(a);
					stack.push(Integer.toString(tmp));
					tmp = 0;
				}
				
				
			}
		}
		
		while(!stack.isEmpty()) {
			String p = stack.pop();
			
			if(p.equals("H"))
				result = result + 1;
			else if(p.equals("C"))
				result = result + 12;
			else if(p.equals("O"))
				result = result + 16;
			else
				result = result + Integer.parseInt(p);
		}
		System.out.println(result);
	}

}
