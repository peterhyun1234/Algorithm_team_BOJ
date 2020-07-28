package JW._7_24;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _1021 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, M;
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		Queue q = new LinkedList();
		
		int count = 0;
		int[] A;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();

		A = new int[M];
		int tmp;
		for(int i =0;i<M;i++) {
			A[i] = s.nextInt();
		}
		
		for(int i =1;i<=N;i++) {
			list.add(i);
		}
		
		for(int i =0;i<M;i++) {
			for(int j =0;j<N;j++){
				if(A[i] == list.get(0)) {
					list.remove(0);
					break;
				}
				else {
					//왼쪽으로 이동
					if(list.size()/2 >= list.indexOf(A[i])) {
						tmp = list.get(0);
						list.remove(0);
						list.add(tmp);
						count = count + 1;
						
					}
					//오른쪽으로 이동
					else {
						tmp = list.get(list.size()-1);
						list.remove(list.size()-1);
						list.add(0, tmp);
						count = count + 1;
					}
				}
			}
		}
		
		System.out.println(count);
	}

}
