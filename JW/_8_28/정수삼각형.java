package JW._8_28;

public class Á¤¼ö»ï°¢Çü {

	static int triangle[][] = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		solution(triangle);

	}
	
	public static int solution(int[][] triangle) {
        int answer = 0;
        
        for(int i=1;i<triangle.length;i++) {
        	triangle[i][0] = triangle[i][0] + triangle[i-1][0];
        	triangle[i][i] = triangle[i][i] + triangle[i-1][i-1];
        }
        
        for(int i=2;i<triangle.length;i++) {
        	for(int j=1;j<triangle[i].length-1;j++) {
        		triangle[i][j] = triangle[i][j] + Math.max(triangle[i-1][j-1], triangle[i-1][j]);
        	}
        }
        
        for(int i=0;i<triangle[triangle.length-1].length;i++) {
        	answer = Math.max(answer, triangle[triangle.length-1][i]);
        }
        return answer;
    }

}
