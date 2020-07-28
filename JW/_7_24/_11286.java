package JW._7_24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class _11286 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		int N;
		int x;
		
		//ArrayList<Integer> list = new ArrayList<Integer>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Queue<Integer> positive = new PriorityQueue<>(Comparator.naturalOrder());
    	Queue<Integer> negative = new PriorityQueue<>(Comparator.reverseOrder());

		N = Integer.parseInt(br.readLine());
		
		
		for(int i =0;i<N;i++) {
			x = Integer.parseInt(br.readLine());
			
			if(x == 0) {
				if(negative.isEmpty() && positive.isEmpty()) {
					System.out.println(0);
				}
				else if(negative.isEmpty())
					System.out.println(positive.poll());
				
				else if(positive.isEmpty())
					System.out.println(negative.poll());
				else {
					if(Math.abs(negative.peek()) <= Math.abs(positive.peek()))
						System.out.println(negative.poll());
					else
						System.out.println(positive.poll());
				}
			}
			
			else {
				if(x < 0) {
					negative.add(x);
				}
				else {
					positive.add(x);
				}
			}
		}
	}

}
