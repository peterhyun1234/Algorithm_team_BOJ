package JW._9_11;


public class ÀÚ¹°¼è¿Í¿­¼è {

	
	static int[][] key = {{0, 1, 0}, {1, 0, 0}, {1, 0, 0}};
	static int[][] lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(key, lock));

	}

	public static boolean solution(int[][] key, int[][] lock) {
        boolean answer = false;
        int keylen = key.length;
        int locklen = lock.length;
        int[][] map = new int[keylen*2 + locklen -2][keylen*2 + locklen -2];
        
        for(int rot=0;rot<4;rot++) {
        	
        	
        	for(int a=0;a<keylen+locklen-1;a++) {
        		for(int b=0;b<keylen+locklen-1;b++) {
        			
        			init(map, lock, keylen);
        			
        			for(int i=0;i<keylen;i++) {
        				for(int j=0;j<keylen;j++) {
        					map[a+i][b+j] += key[i][j];
        				}
        			}
        			
        			if(check(map, locklen, keylen)) {
        				answer = true;
        				return answer;
        			}
        			
        		}
        	}
        	
        	key = rotate(key);
        	
        }
        return answer;
    }
	
	public static int[][] init(int[][] map, int[][] lock, int keylen){
		
		for(int i=0;i<map.length;i++) {
			for(int j=0;j<map.length;j++) {
				map[i][j] = 0;
			}
		}
		for(int i=0;i<lock.length;i++) {
			for(int j=0;j<lock.length;j++) {
				map[i+keylen-1][j+keylen-1] = lock[i][j];
			}
		}
		
		return map;
	}
	
	public static boolean check(int[][] map, int locklen, int keylen) {
		
		boolean check = true;
		
		for(int i=0;i<locklen;i++) {
			for(int j=0;j<locklen;j++) {
				
				int value = map[i+keylen-1][j+keylen-1];
				
				if(value != 1) {
					check = false;
					return check;
				}
			}
		}
		
		return check;
	}
	
	public static int[][] rotate(int[][] key){
		
		int[][] result = new int[key.length][key.length];
		
		for(int i=0;i<key.length;i++) {
			for(int j=0;j<key.length;j++) {
				result[j][key.length-1-i] = key[i][j];
			}
		}
		return result;
	}
	
}
