package JW._8_21;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.Scanner;


//우선순위 큐 -> 바꾸기 시간 오래 걸림!!
//ArrayList와 LinkedList 차이!
/*예를 들어 배열 정중앙에 있는 원소가 무엇인지 알아보는 건 LinkedList는 O(n), ArrayList는 O(1) 의 시간복잡도를 가지고
	그렇게 찾아낸 위치에 있는 원소를 삭제하는 건 LinkedList는 O(1), ArrayList는 O(n)의 시간복잡도를 가집니다.
*/
public class _16235 {

	static int N, M, K;
	static int[][] land;
	static int[][] grow;
	static Deque<Tree> tree;
	static Deque<Tree> deadtree;
	static int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
	static int[] dy = {0, -1, -1, -1, 0, 1, 1, 1};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		K = s.nextInt();
		
		land = new int[N][N];
		grow = new int[N][N];
		tree = new ArrayDeque<Tree>();
		deadtree = new ArrayDeque<Tree>();
		
		//init
		for(int i =0;i<N;i++) {
			for(int j=0;j<N;j++) {
				grow[i][j] = s.nextInt();
				land[i][j] = 5;
			}
		}
		
		for(int i =0;i<M;i++) {
			int x = s.nextInt();
			int y = s.nextInt();
			int age = s.nextInt();
			tree.add(new Tree(x-1, y-1, age));
		}
		
		//4 seasons
		for(int i =0; i<K;i++) {
			Spring();
			Summer();
			fall();
			winter();
		}
		
		System.out.println(tree.size());

	}

	public static void Spring() {
		
		Deque<Tree> temptree = new ArrayDeque<Tree>();
		while(!tree.isEmpty()) {
			Tree tr = tree.poll();
			int x = tr.x;
			int y = tr.y;
			int age = tr.age;
			
			if(land[x][y] >= age) {
				land[x][y] -= age;
				tr.age++;
				temptree.offer(tr);
			}
			else {
				deadtree.add(tr);
			}
		}
		
		tree = temptree;
	}
	
	public static void Summer() {
		
		while(!deadtree.isEmpty()) {
			Tree tr = deadtree.poll();
			land[tr.x][tr.y] += tr.age/2; 
		}
	}
	
	public static void fall() {
		
		Deque<Tree> temptree = new ArrayDeque<Tree>();
		while(!tree.isEmpty()) {
			Tree tr = tree.poll();
			
			int age = tr.age;
			if(age % 5 == 0) {
				for(int j=0;j<8;j++) {
					int nx = tr.x + dx[j];
					int ny = tr.y + dy[j];
					
					if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
						temptree.addFirst(new Tree(nx, ny, 1));
					}
				}
			}
			temptree.offer(tr);
			
		}
		tree = temptree;
	}
	
	public static void winter() {
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				land[i][j] += grow[i][j];
			}
		}
	}
	
	
	public static class Tree implements Comparable<Tree>{
		int x, y, age;
		Tree(int x, int y, int age){
			this.x = x;
			this.y = y;
			this.age = age;
		}
		
		public int compareTo(Tree t) {
			return this.age - t.age;
		}
	}
}
