package JW._8_25;

import java.util.ArrayList;
import java.util.Arrays;

public class Sort_1 {

	static int[] array = {1, 5, 2, 6, 3, 7, 4};
	static int[][] com = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		solution(array, com);

	}

	public static int[] solution(int[] array, int[][] commands) {
        int[] answer = {};
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        for(int[] c : commands) {
        	int s = c[0]-1;
        	int e = c[1]-1;
        	int[] arr = new int[e-s+1];
        	for(int i =0;i<e-s+1;i++) {
        		arr[i] = array[s+i];
        	}
        	
        	Arrays.sort(arr);
        	
        	ans.add(arr[c[2]-1]);
        }
        
        answer = new int[ans.size()];
        
        for(int i=0;i<ans.size();i++) {
        	answer[i] = ans.get(i);
        }
        return answer;
    }
}
