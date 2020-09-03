package JW._8_25;

import java.util.HashMap;

public class Hash_3 {

	static String[][] clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(clothes));
	}

	public static int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String, Integer> cl = new HashMap<>(clothes.length);
        
        for(String[] name : clothes) {
        	cl.put(name[1], cl.getOrDefault(name[1], 0) + 1);
        }
        
        for(String name : cl.keySet()) {
        	answer *= (cl.get(name)+1);
        }
        return answer-1;
    }
}
