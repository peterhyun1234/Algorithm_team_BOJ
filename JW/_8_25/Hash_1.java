package JW._8_25;

import java.util.Arrays;
import java.util.HashMap;

public class Hash_1 {

	static String[] participant= {"marina", "josipa", "nikola", "vinko", "filipa"};
	static String[] completion= {"marina", "josipa", "nikola", "filipa"};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(solution(participant, completion));
	}
	
	public static String solution(String[] participant, String[] completion) {
        String answer = "";
        int key = 0;
        
        Arrays.sort(participant);
        Arrays.sort(completion);
        
        HashMap<String, Integer> map1 = new HashMap<>(participant.length);
        
        for(String name : participant) {
        	map1.put(name, map1.getOrDefault(name, 0) + 1);
        }
        for(String name : completion) {
        	map1.put(name, map1.get(name) -1);
        }
        for(String name : map1.keySet()) {
        	if(map1.get(name) != 0) {
        		answer = name;
        		break;
        	}
        }
        
        return answer;
    }

}
