package JW._8_25;

import java.util.Arrays;
import java.util.Comparator;

public class Hash_2 {

	//static String[] phone_book = {"119", "97674223", "1195524421"};
	static String[] phone_book = {"123","456","789", "1515", "114556", "87", "1144"};
	//static String[] phone_book = {"12","123","1235","567","88"};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(solution(phone_book));

	}

	 public static boolean solution(String[] phone_book) {
	        boolean answer = true;
	        
	        Arrays.sort(phone_book, new Comparator<String>() {

				@Override
				public int compare(String s1, String s2) {
					// TODO Auto-generated method stub
					if(s1.length() > s2.length())
						return 1;
					else if(s1.length() == s2.length())
						return 0;
					else
						return -1;
				}
	        	
			});
	        
	        for(int i=0;i<phone_book.length-1;i++) {
	        	for(int j=i+1;j<phone_book.length;j++) {
	        		
	        		boolean exist = true;
	        		for(int k=0;k<phone_book[i].length();k++) {
	        			if(phone_book[i].charAt(k) != phone_book[j].charAt(k)) {
	        				exist = false;
	        				break;
	        			}
	        		}
	        		
	        		if(exist) {
	        			answer = false;
	        			return answer;
	        		}
	        	}
	        }
	        return answer;
	    }
}
