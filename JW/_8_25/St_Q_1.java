package JW._8_25;

import java.util.Stack;

public class St_Q_1 {

	
	static int[] prices = {2, 6, 3, 4, 2, 3, 7, 8, 9, 10, 1};
	//static int[] prices = {1, 2, 3, 2, 3};
	//5, 1, 1, 1, 5, 4, 3, 1, 1, 0
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		solution(prices);
	}

	 public static int[] solution(int[] prices) {
		 
	        int[] answer = new int[prices.length];
	        int idx = 0;
	        Stack<Pair> p = new Stack<Pair>();
	        
	        for(int price : prices) {
	        	
	        	while(!p.isEmpty() && price < p.peek().price) {
	        		Pair tmp = p.pop();
	        		answer[tmp.idx] = idx - tmp.idx;
	        		
	        	}
	        	
	        	p.push(new Pair(price, idx));
	        	idx++;
	        }
	        idx--;
	        while(!p.isEmpty()) {
	        	Pair tmp = p.pop();
	        	answer[tmp.idx] = idx - tmp.idx;
	        }
	        return answer;
	    }
	 
	 public static class Pair{
		 int price, idx;
		 Pair(int price, int idx){
			 this.price = price;
			 this.idx = idx;
		 }
	 }
}
