package JW._8_04;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 시간초과 L R 명령어 변경???
// 메모리 초과 시간 초과
/*public class Main {
	
	static Queue<Pair> q = new LinkedList<Pair>();

	static int index = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int T;
		int[] A, B;
		
		
		Scanner s = new Scanner(System.in);

		T = s.nextInt();
		A = new int[T];
		B = new int[T];
		for(int i =0;i<T;i++) {
			A[i] = s.nextInt();
			B[i] = s.nextInt();
		}
		
		for(int i =0;i<T;i++) {
			int nodeidx = BFS(A[i], B[i]);
			LinkedList<String> print = new LinkedList<String>();
			while(true) {
				if(nodeidx == 0)
					break;
				if(nodeidx % 4 == 1) {
					print.add("D");
				}
				else if(nodeidx % 4 == 2) {
					print.add("S");
				}
				else if(nodeidx % 4 == 3) {
					print.add("L");
				}
				else if(nodeidx % 4 == 0) {
					print.add("R");
				}
				nodeidx = nodeidx / 4;
			}
			for(int j =print.size()-1;j >= 0; j--) {
				System.out.printf(print.get(j));
			}
			System.out.println();
			q.clear();
			index = 0;
		}
	}

	public static int BFS(int A, int B) {
		q.add(new Pair(A, index++));
		while(!q.isEmpty()) {
			Pair pair = q.poll();
			int num = pair.num;
			
			if(num == B) {
				return pair.idx;
			}
			
			
			q.add(new Pair(D(num), index++));
			q.add(new Pair(S(num), index++));
			q.add(new Pair(L(num), index++));
			q.add(new Pair(R(num), index++));
			
		}
		return 0;
	}
	
	public static class Pair{
		int num;
		int idx;
		Pair(int num, int idx) {
			this.num = num;
			this.idx = idx;
		}
	}
	public static int D(int A) {
		
		A = (A * 2) % 10000;
		
		
		return A;
	}
	
	public static int S(int A) {
		
		if(A == 0)
			A = 9999;
		else
			A = A -1;
		
		
		return A;
	}
	
	public static int L(int A) {
		
		
		if(A == 0) {
			return 0;
		}
		
		int result = 0;
		int digit = 0;
		int[] num = new int[4];
		while(true) {
			if(A == 0)
				break;
			num[digit] = A % 10;
			A = A / 10;
			digit++;
			
		}
		
		result = result + num[digit-1];
		for(int i =0;i<digit-1;i++) {
			result = result + num[i] * (int)Math.pow(10, i+1);
		}
		
		return result;
	}
	
	public static int R(int A) {
		
		if(A == 0) {
			return 0;
		}
		int result = 0;
		int digit = 0;
		int[] num = new int[4];
		while(true) {
			if(A == 0)
				break;
			num[digit] = A % 10;
			A = A / 10;
			digit++;
			
		}
		
		result = result + 1000 * num[0];
		for(int i =digit-1;i>0;i--) {
			result = result + num[i] * (int)Math.pow(10, i-1);
		}
		
		
		return result;
	}*/

public class _9019 {
	
	static Queue<Integer> q = new LinkedList<Integer>();

	static String[] command;
	static boolean[] visited;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int T;
		int[] A, B;
		
		
		Scanner s = new Scanner(System.in);

		T = s.nextInt();
		A = new int[T];
		B = new int[T];
		for(int i =0;i<T;i++) {
			A[i] = s.nextInt();
			B[i] = s.nextInt();
		}
		
		
		
		
		
		for(int i =0;i<T;i++) {
			command = new String[10000];
			visited = new boolean[10000];
			Arrays.fill(command, "");
			BFS(A[i], B[i]);
			System.out.println(command[B[i]]);
			q.clear();
		}
	}

	public static void BFS(int A, int B) {
		q.add(A);
		while(!q.isEmpty()) {
			
			int num = q.poll();
			if(num == B)
				break;
			int D = D(num);
			int S = S(num);
			int L = L(num);
			int R = R(num);
			
			//0 1000 인 경우 반례
			// 정답은 SDDLDSLDRDDD 추가 안해주면 DSDDLDSLDRDDD
			// D가 추가해서 나옴
			if(visited[D] == false && num != 0) {
				visited[D] = true;
				command[D] = command[num] + "D";
				q.add(D);
			}
			if(visited[S] == false) {
				visited[S] = true;
				command[S] = command[num] + "S";
				q.add(S);
			}
			if(visited[L] == false) {
				visited[L] = true;
				command[L] = command[num] + "L";
				q.add(L);
			}
			if(visited[R] == false) {
				visited[R] = true;
				command[R] = command[num] + "R";
				q.add(R);
			}
			
		}
	}
	public static int D(int A) {
		
		A = (A * 2) % 10000;
		
		
		return A;
	}
	
	public static int S(int A) {
		
		if(A == 0)
			A = 9999;
		else
			A = A -1;
		
		
		return A;
	}
	
	public static int L(int A) {
		
		int result = (A % 1000) * 10;
		result = result + A / 1000;
		
		return result;
	}
	
	public static int R(int A) {
		
		int result = (A % 10) * 1000;
		result = result + A / 10;
		
		
		return result;
	}
}
