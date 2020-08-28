package JW._8_25;

public class bruteforce_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(int ans : solution(50, 22)) {
			System.out.println(ans);
		};

	}
	
	public static int[] solution(int brown, int yellow) {
		int B = brown;
		int Y = yellow;
		
		int[] answer = new int[2];
		int result;
		
		int a, b, c;
		a = 1;
		b = -1 * (B+4)/2;
		c = B+Y;
		
		answer[0] = (int) ((-b + Math.sqrt(b*b - 4 * a * c)) / (2*a));
		answer[1] = (int) ((-b - Math.sqrt(b*b - 4 * a * c)) / (2*a));
		
		return answer;
    }
	

}
