package JW._8_28;

//예전 계단오르기와 비슷 흥미로운 문제였음!
public class 도둑질 {

	static int[] money = {1, 2, 3};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(money));
	}
	
	public static int solution(int[] money) {
        int answer = 0;
        int[][] DP = new int[2][money.length];
        
        DP[0][0] = money[0];
        DP[0][1] = money[0];
        DP[1][1] = money[1];
        
        for(int i=2;i<money.length-1;i++) {
        	DP[0][i] = Math.max(DP[0][i-2] + money[i], DP[0][i-1]);
        }
        
        for(int i=2; i<money.length;i++) {
        	DP[1][i] = Math.max(DP[1][i-2] + money[i], DP[1][i-1]);
        }
        
        answer = Math.max(DP[0][money.length-2], DP[1][money.length-1]);
        
        return answer;
    }

}
