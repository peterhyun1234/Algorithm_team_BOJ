package JW._8_14;

//왜 long으로??
//left 와 right 끝날 시점을 정확히 모르겠음
import java.util.Arrays;
import java.util.Scanner;

public class _3079 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, M;
		long [] time;

		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		time = new long[N];
		
		for(int i =0;i<N;i++) {
			time[i] = s.nextLong();
		}
		
		Arrays.sort(time);
		
		long left = 1;
		long right = time[0] * M;
		long result = right;
		
		while(left <= right) {
			long mid = (left+right)/2;
			long cnt = 0;
			
			for(int i=0;i<time.length;i++) {
				if(mid < time[i])
					break;
				
				cnt += mid/time[i];
			}
			if(cnt < M) 
				left = mid + 1;
			
			else {
				result = Math.min(result, mid);
				right = mid - 1;
			}
			
		}
		
		System.out.println(result);
	}

}
