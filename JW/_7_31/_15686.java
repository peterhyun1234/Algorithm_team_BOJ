package JW._7_31;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class _15686 {

	
	static ArrayList<Pair> chicken;
    static ArrayList<Pair> person;
    static Stack<Pair> selectChicken;
    static int mind = Integer.MAX_VALUE;
    
    static int[][] A;
    
    static int M;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		A = new int[N][N];
		
		chicken = new ArrayList<Pair>();
		person = new ArrayList<Pair>();
		selectChicken = new Stack<Pair>();
		
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				A[i][j] = s.nextInt();
				
				if(A[i][j] == 1)
					person.add(new Pair(i,j));
				else if(A[i][j] == 2)
					chicken.add(new Pair(i,j));
			}
		}

		select(0,0);
		
		System.out.println(mind);
	}
	
	static void select(int start, int count) {
		if(count == M) {
			calD();
			return;
		}
		
		for(int i=start; i < chicken.size();i++) {
			selectChicken.push(chicken.get(i));
			select(i+1, count+1);
			selectChicken.pop();
		}
	}
	
	public static void calD() {
		int sum = 0;
		for(Pair person : person) {
			int min = Integer.MAX_VALUE;
			for(Pair chicken : selectChicken) {
				int d = Math.abs(person.x - chicken.x)
						+ Math.abs(person.y - chicken.y);
				min = Math.min(min, d);
			}
			sum += min;
			
			if(sum > mind)
				return;
		}
		mind = Math.min(sum, mind);
	}
	public static class Pair{
		int x, y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}

}
