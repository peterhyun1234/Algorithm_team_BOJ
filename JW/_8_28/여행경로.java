package JW._8_28;

import java.util.Arrays;
import java.util.Comparator;

public class 여행경로 {

	static String[][] tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
	//static String[][] tickets = {{"ICN", "A"}, {"A", "C"}, {"A", "D"}, {"D", "B"}, {"B", "A"}};
	static boolean[] visited;
	static int count = 0;
	static String[] answer;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(String ans : solution(tickets)) {
			System.out.println(ans);
		}

	}
	
	public static String[] solution(String[][] tickets) {
		visited = new boolean[tickets.length];
		answer = new String[tickets.length+1];
        Arrays.sort(tickets, new Comparator<String[]>() {
        	
			@Override
			public int compare(String[] s1, String[] s2) {
				// TODO Auto-generated method stub
				if(s1[1].equals(s2[1])) {
					return s1[0].compareTo(s2[0]);
				}
				else {
					return s1[1].compareTo(s2[1]);
				}
			}
		});
        
        DFS("ICN", tickets, 0);
        
        return answer;
    }
	
	public static void DFS(String cur, String[][] tickets, int idx) {
		if(count == tickets.length)
			return;
		
		for(int i=0;i<tickets.length;i++) {
			if(visited[i] == false && tickets[i][0].equals(cur)) {
				visited[i] = true;
				answer[idx] = cur;
				answer[idx+1] = tickets[i][1];
				count++;
				DFS(tickets[i][1], tickets, idx + 1);
				if(count == tickets.length)
					break;
				count--;
				visited[i] = false;
			}
		}
	}
}
