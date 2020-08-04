package JW._8_04;

import java.awt.List;
import java.util.LinkedList;
import java.util.Scanner;

public class _2644 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		LinkedList<Integer> list1 = new LinkedList<Integer>();
		LinkedList<Integer> list2 = new LinkedList<Integer>();

		int n, m;
		int[] FM;
		int p1, p2;
		
		Scanner s = new Scanner(System.in);
		
		n = s.nextInt();
		
		FM = new int[n+1];
		p1 = s.nextInt();
		p2 = s.nextInt();
		
		m = s.nextInt();
		
		
		for(int i=0;i<m;i++) {
			int parent = s.nextInt();
			int child = s.nextInt();
			
			FM[child] = parent;
		}
		
		
		list1.add(p1);
		list2.add(p2);
		
		while(true) {
			p1 = FM[p1];
			p2 = FM[p2];
			
			
			if(p1 == 0 && p2 == 0)
				break;
			if(p1 != 0)
				list1.add(p1);
			if(p2 != 0)
				list2.add(p2);
			
		}
		
		int anc = -1;
		
		for(int i =0;i<list1.size();i++) {
			for(int j =0;j<list2.size();j++) {
				if(list1.get(i) == list2.get(j)) {
					anc = list1.get(i);
					break;
				}
			}
			if(anc != -1)
				break;
		}
		
		if(anc == -1)
			System.out.println(-1);
		else {
			System.out.println(list1.indexOf(anc) + list2.indexOf(anc));
		}

	}

}
