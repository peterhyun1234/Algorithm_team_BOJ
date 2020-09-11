package JW._8_28;

import java.util.HashSet;

public class 소수찾기 {

	static String numbers = "011";
	static HashSet<Integer> number = new HashSet<Integer>();
	static boolean[] visited;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(numbers));
	}
	
	public static int solution(String numbers) {
        int answer = 0;
        visited = new boolean[numbers.length()];
        
        for(int i=1;i<numbers.length()+1;i++) {
        	DFS(numbers, i, 0, "");
        }
        
        number.remove(0);
        number.remove(1);
        
        for(int num : number) {
        	boolean isPrime = true;
        	for(int i=2;i<num;i++) {
        		if(num % i == 0) {
        			isPrime = false;
        			break;
        		}
        	}
        	if(isPrime)
        		answer++;
        }
        return answer;
    }
	
	public static void DFS(String numbers, int len, int count, String result) {
		if(count == len) {
			if(result.length() == len) {
				number.add(Integer.parseInt(result));
			}
			return;
		}
		
		for(int i=0;i<numbers.length();i++) {
			if(visited[i] == false) {
				visited[i] = true;
				DFS(numbers, len, count + 1, result + numbers.charAt(i));
				visited[i] = false;
				DFS(numbers, len, count + 1, result);
			}
		}
		
	}

}
