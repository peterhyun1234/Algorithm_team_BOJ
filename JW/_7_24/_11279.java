package JW._7_24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

public class _11279 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		
		int N;
		int x;
		
		//ArrayList<Integer> list = new ArrayList<Integer>();
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		

		N = Integer.parseInt(br.readLine());
		
		//list.add(0);
		
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
				
				/*list.add(x);
				int idx = list.size() - 1;
				while(true) {
					if(idx == 1 || list.get(idx/2) >= list.get(idx))
						break;
					else {
						int swap = list.get(idx);
						list.remove(idx);
						list.add(idx, list.get(idx/2));
						list.remove(idx/2);
						list.add(idx/2, swap);
						idx = idx/2;
					}
				}*/
			}
			
		}
	}

}
