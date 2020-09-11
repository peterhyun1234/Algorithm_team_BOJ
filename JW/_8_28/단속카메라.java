package JW._8_28;

import java.util.Arrays;
import java.util.Comparator;

public class 단속카메라 {

	static int[][] routes = {{-20,15}, {-14,-5}, {-18,-13}, {-5,-3}};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(routes));

	}
	
	public static int solution(int[][] routes) {
        int answer = 0;
        int camera = -30001;
        
        
        Arrays.sort(routes, new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				// TODO Auto-generated method stub
				return o1[1] - o2[1];
			}
		});
        
        for(int[] car : routes) {
        	if(car[0] > camera) {
        		answer++;
        		camera = car[1];
        	}
        }
        
        return answer;
    }

}

/*
 * public static int solution(int[][] routes) {
        int answer = 0;
        
        ArrayList<Integer> install = new ArrayList<Integer>();
        int left = 30000;
        int right = -30000;
        
        int end;
        
        for(int i=0;i<routes.length;i++) {
        	int s = routes[i][0];
        	int e = routes[i][1];
        	
        	left = Math.min(left, s);
        	right = Math.max(right, e);
        }
        
        for(int i=0;i<routes.length;i++) {
        	routes[i][0] = routes[i][0] - left;
        	routes[i][1] = routes[i][1] - left;
        }
        
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        
        end = right - left + 1;
        
        for(int i=0;i<end;i++) {
        	list.add(new ArrayList<Integer>());
        }
        
        for(int i=0;i<end;i++) {
        	for(int j=0;j<routes.length;j++) {
        		int s = routes[j][0];
        		int e = routes[j][1];
        		
        		if(i >= s && i <= e) {
        			list.get(i).add(j);
        		}
        	}
        }
        
        while(install.size() != routes.length) {
        	
        	ArrayList<Integer> tmp = new ArrayList<Integer>();
        	
        	int size = 0;
        	int len = -1;
        	for(int i=0;i<end;i++) {
        		if(size < list.get(i).size()) {
        			size = list.get(i).size();
        			len = i;
        		}
        	}
        	
        	for(int i=0;i<list.get(len).size();i++) {
        		tmp.add(list.get(len).get(i));
        	}
        	
        	for(int i=0;i<end;i++) {
        		
        		for(int j=0;j<tmp.size();j++) {
        			int tmpidx = tmp.get(j);
        			if(list.get(i).contains(tmpidx))
        				list.get(i).remove((Integer)tmpidx);
        		}
        	}
        	
        	install.addAll(tmp);
        	answer++;
        }
        
        return answer;
    }
    */