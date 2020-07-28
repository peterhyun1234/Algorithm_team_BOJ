package JW._7_24;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class _2696 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		/*int T;
		int M;
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		Scanner s = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//T = Integer.parseInt(br.readLine());
		
		T = s.nextInt();
		for(int i = 0;i<T;i++){
			M = s.nextInt();
			//M = Integer.parseInt(br.readLine());
			
			
			System.out.println((M+1)/2);
			
			for(int j =0;j<M;j++) {
				//list.add(Integer.parseInt(tmp[j]));
				list.add(s.nextInt());
				Collections.sort(list);
				
				if(j % 2 == 0) {
					if((j+2) % 20 == 0)
						System.out.println(list.get(j/2));
					else
						System.out.print(list.get(j/2) + " ");
				}
			}
			System.out.println();
			list.clear();
		}*/
		
		
		int T;
		int M;
		
		int num;
		int tmp;
		//중앙값보다 작은 수 큐 중앙값 포함(최대 힙)
		PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Collections.reverseOrder());
		//중앙값보다 큰 수 큐 (최소 힙)
		PriorityQueue<Integer> minQueue = new PriorityQueue<>();
		
		Scanner s = new Scanner(System.in);
		
		T = s.nextInt();
		for(int i = 0;i<T;i++){
			M = s.nextInt();
			
			System.out.println((M+1)/2);
			
			maxQueue.add(s.nextInt());
			System.out.print(maxQueue.peek() + " ");
			for(int j =1;j<M;j++) {
				num = s.nextInt();
				if(minQueue.isEmpty())
					maxQueue.add(num);
				else if(minQueue.peek() > num)
					maxQueue.add(num);
				else
					minQueue.add(num);
				
				if(maxQueue.size() >= minQueue.size() + 2) {
					tmp = maxQueue.poll();
					minQueue.add(tmp);
				}
				else if(maxQueue.size() < minQueue.size()){
					tmp = minQueue.poll();
					maxQueue.add(tmp);
				}
				
				if(j % 2 == 0) {
					if((j+2) % 20 == 0)
						System.out.println(maxQueue.peek());
					else
						System.out.print(maxQueue.peek() + " ");
				}
			}
			maxQueue.clear();
			minQueue.clear();
		}
	}
}
