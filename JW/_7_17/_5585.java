package JW._7_17;
import java.util.Scanner;

public class _5585 {
	// ??? 예외 상황이 있지 않나??
	// 최적의 해를 구하는가?
	public static void main(String[] args) {
		
		int bill;
		int Change;
		
		int result = 0;
		
		Scanner s = new Scanner(System.in);
		
		bill = s.nextInt();
		s.nextLine();
		
		Change = 1000 - bill;
		
		if(Change >= 500) {
			Change = Change - 500;
			result = result + 1;
		}
		while(Change >= 100){
			Change = Change - 100;
			result = result + 1;
		}
		while(Change >= 50){
			Change = Change - 50;
			result = result + 1;
		}
		while(Change >= 10){
			Change = Change - 10;
			result = result + 1;
		}
		while(Change >= 5){
			Change = Change - 5;
			result = result + 1;
		}
		while(Change >= 1){
			Change = Change - 1;
			result = result + 1;
		}
		System.out.println(result);
	}

}
