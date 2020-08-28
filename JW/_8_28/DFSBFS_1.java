package JW._8_28;

public class DFSBFS_1 {

	static int[] numbers = {1, 1, 1, 1, 1};
	static int target = 3;
	
	static int ans = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(numbers, target));
	}
	
	public static int solution(int[] numbers, int target) {
        int answer = 0;
        
        DFS(numbers, target, 0, 0);
        
        answer = ans;
        return answer;
    }
	
	public static void DFS(int[] numbers, int target, int result, int idx) {
		if(idx == numbers.length) {
			if(result == target) {
				ans++;
			}
			return;
		}
		
		DFS(numbers, target, result + numbers[idx], idx+1);
		DFS(numbers, target, result - numbers[idx], idx+1);
		
		
	}

}
