package JW._7_24;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class _2252 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int N, M;
		
		int[] A;
		ArrayList<Integer>[] list;
		int v1, v2;
		
		Queue<Integer> q = new LinkedList<Integer>();
	    
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		A = new int[N+1];
		list = new ArrayList[N+1];
		
		for(int i=1;i<=N;i++) {
			list[i] = new ArrayList<Integer>();
		}
		for(int i = 0;i<M;i++) {
			v1 = s.nextInt();
			v2 = s.nextInt();
			
			A[v2] = A[v2] + 1;
			list[v1].add(v2);
		}
		
		for(int i=1; i<=N; i++) {
            if(A[i] == 0)
                q.offer(i);
        }
		
		while(!q.isEmpty()) {
            int node = q.poll();

            System.out.print(node + " ");
            
            for(int i = 0;i<list[node].size();i++) {
            	A[list[node].get(i)]--;
            	if(A[list[node].get(i)] == 0)
            		q.offer(list[node].get(i));
            }
        }
	}

}
