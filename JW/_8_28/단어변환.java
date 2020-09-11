package JW._8_28;

public class 단어변환 {

	static String begin = "hit";
	static String target = "cog";
	static String[] words = {"hot", "dot", "dog", "lot", "log", "cog"};
	
	static int ans = Integer.MAX_VALUE;
	static boolean[] visited;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(begin, target, words));
	}

	public static int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        visited = new boolean[words.length];
        DFS(begin, target, words, 0);
        
        if(ans == Integer.MAX_VALUE)
        	answer = 0;
        else
        	answer = ans;
        
        return answer;
    }
	
	public static void DFS(String cur, String target, String[] words, int count) {
		
		if(cur.equals(target)) {
			ans = Math.min(ans, count);
			return;
		}
		
		for(int i=0;i<words.length;i++) {
			if(visited[i])
				continue;
			
			int diff = 0;
			for(int j=0;j<cur.length();j++) {
				if(cur.charAt(j) != words[i].charAt(j))
					diff++;
				
				if(diff >= 2)
					break;
			}
			
			if(diff == 1) {
				visited[i] = true;
				DFS(words[i], target, words, count+1);
				visited[i] = false;
			}
		}
	}
}
