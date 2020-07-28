package JW._7_24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class _1927 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		int N;
		int x;
		
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		

		N = Integer.parseInt(br.readLine());
		
		
		for(int i =0;i<N;i++) {
			x = Integer.parseInt(br.readLine());
			
			if(x == 0) {
				if(priorityQueue.isEmpty()) {
					System.out.println(0);
				}
				else {
					System.out.println(priorityQueue.poll());
				}
			}
			else {
				priorityQueue.add(x);
			}
			
		}
	}

}
