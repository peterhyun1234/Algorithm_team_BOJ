package JW._8_25;

import java.util.Arrays;
import java.util.Comparator;

public class Sort_2 {

	static int[] numbers = {0, 7, 0, 0};
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(numbers));
	}
	
	public static String solution(int[] numbers) {
        String answer = "";
        String[] nums = new String[numbers.length];
        
        for(int i=0;i<numbers.length;i++) {
        	nums[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(nums, new Comparator<String>() {

			@Override
			public int compare(String s1, String s2) {
				// TODO Auto-generated method stub
				return Integer.parseInt(s2 + s1) - Integer.parseInt(s1 + s2);
				
				//두개의 차이???
				/*if(Integer.parseInt(s1 + s2) >= Integer.parseInt(s2 + s1))
					return -1;
				else
					return 1;*/
			}
		});
        
        if(nums[0].startsWith("0"))
        	answer = "0";
        else{
        	for(int i=0;i<nums.length;i++) {
        	answer += nums[i];
        	}
        }
        
        return answer;
    }

}
