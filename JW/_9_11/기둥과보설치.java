package JW._9_11;

public class 기둥과보설치 {

	static int n = 5;
	//static int[][] build_frame = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};
	static int[][] build_frame = {{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}};
	static boolean[][][] install;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		solution(n, build_frame);

	}

	public static int[][] solution(int n, int[][] build_frame) {
        int[][] answer;
        
        install = new boolean[2][n+3][n+3];
        int installcount = 0;
        for(int[] frame : build_frame) {
        	int x = frame[0] + 1;
        	int y = frame[1] + 1;
        	int kind = frame[2];
        	int work = frame[3];
        	
        	//설치
        	if(work == 1) {
        		//기둥 설치
        		if(kind == 0) {
        			if(checkcol(x, y)) {
        				install[0][x][y] = true;
        				installcount++;
        			}
        		}
        		
        		//보 설치
        		else if(kind == 1) {
        			if(checkrow(x, y)) {
        				install[1][x][y] = true;
        				installcount++;
        			}
        		}
        	}
        	//제거
        	else if(work == 0) {
        		//기둥 제거
        		if(kind == 0) {
        			install[0][x][y] = false;
        			installcount--;
        			if(check(n)) {
        				install[0][x][y] = true;
        				installcount++;
        			}
        			
        		}
        		//보 제거
        		else if(kind == 1) {
        			install[1][x][y] = false;
        			installcount--;
        			if(check(n)) {
        				install[1][x][y] = true;
        				installcount++;
        			}
        			
        		}
        	}
        }
        
        int idx = 0;
        answer = new int[installcount][3];
        
        for(int i=1;i<=n+1;++i) {
        	for(int j=1;j<=n+1;++j) {
        		if(install[0][i][j]) {
        			answer[idx++] = new int[] {i-1, j-1, 0};
        		}
        		if(install[1][i][j]) {
        			answer[idx++] = new int[] {i-1, j-1, 1};
        		}
        	}
        }
        return answer;
    }
	
	public static boolean checkcol(int x, int y) {
		return y == 1 || install[0][x][y-1] || install[1][x-1][y] || install[1][x][y];
	}
	
	public static boolean checkrow(int x, int y) {
		return install[0][x][y-1] || install[0][x+1][y-1] || (install[1][x-1][y] && install[1][x+1][y]);
	}
	public static boolean check(int n) {
		
		for(int i=1;i<=n+1;++i) {
			for(int j=1;j<=n+1;++j) {
				
				//1층 기둥을 제외한 나머지 기둥
				if(install[0][i][j] && !checkcol(i, j)) {
					return true;
				}
				
				if(install[1][i][j] && !checkrow(i, j)) {
					return true;
					
				}
			}
		}
		
		return false;
	}
}
