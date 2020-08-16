package JW._8_14;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class _11657 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		final int INF = 1000000;
		int N, M;
		Scanner s = new Scanner(System.in);
		ArrayList<Pair> busArray = new ArrayList<>();
		
		N = s.nextInt();
		M = s.nextInt();
		
		
		for(int i =0;i<M;i++) {
			int start = s.nextInt();
			int end = s.nextInt();
			int time = s.nextInt();
			
			busArray.add(new Pair(start, end, time));
		}
		
		long[] dist = new long[N+1];
		for(int i =0;i<dist.length;i++) {
			dist[i] = INF;
		}
		
		dist[1] = 0;
		boolean iscycle = false;
		
		//N-1번 돌린다
		for(int i =0; i<N-1;i++) {
			for(int j=0;j<M;j++) {
				if(dist[busArray.get(j).start] == INF)
					continue;
				if(dist[busArray.get(j).end] > dist[busArray.get(j).start] + busArray.get(j).time) {
					dist[busArray.get(j).end] = dist[busArray.get(j).start] + busArray.get(j).time;
				}
			}
		}
		
		//한번 더 돌려서 dist값이 바뀌는 경우 음수 가중치 사이클
		for(int i =0;i<M;i++) {
			if(dist[busArray.get(i).start] != INF && dist[busArray.get(i).end] > dist[busArray.get(i).start] + busArray.get(i).time) {
				iscycle = true;
				break;
			}
		}
		
		if(iscycle)
			System.out.println(-1);
		else {
			for(int i =2;i<=N;i++) {
				if(dist[i] == INF)
					System.out.println("-1");
				else
					System.out.println(dist[i]);
			}
		}

	}
	
	public static class Pair{
		int start, end, time;
		Pair(int start, int end, int time){
			this.start = start;
			this.end = end;
			this.time = time;
		}
	}

}
