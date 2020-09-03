package JW._8_25;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Hash_4 {

	static String[] genres = {"classic", "pop", "classic", "classic", "pop"};
	static int[] plays = {500, 600, 501, 800, 900};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(int ans : solution(genres, plays)) {
			System.out.println(ans);
		}

	}

	public static int[] solution(String[] genres, int[] plays) {
        int[] answer;
        
        HashMap<String, Integer> play = new HashMap<>(genres.length);
        ArrayList<Pair> list = new ArrayList<Pair>();
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        for(int i=0;i<genres.length;i++) {
        	String song = genres[i];
        	play.put(song, play.getOrDefault(song, 0) + plays[i]);
        }
        
        for(String song : play.keySet()) {
        	list.add(new Pair(song, play.get(song)));
        }
        
        Collections.sort(list);
        
        for(int i=0;i<list.size();i++) {
        	String song = list.get(i).song;
        	
        	int chart1 = 0;
        	int chart2 = 0;
        	int idx1 = -1;
        	int idx2 = -1;
        	
        	
        	for(int j=0;j<genres.length;j++) {
        		if(genres[j].equals(song)) {
        			if(chart1 < plays[j]) {
        				chart2 = chart1;
        				idx2 = idx1;
        				chart1 = plays[j];
        				idx1 = j;
        			}
        			else if(chart2 < plays[j]) {
        				chart2 = plays[j];
        				idx2 = j;
        			}
        		}
        	}
        	
        	result.add(idx1);
        	if(idx2 != -1)
        		result.add(idx2);
        }
        
        answer = new int[result.size()];
        for(int i=0;i<result.size();i++) {
        	answer[i] = result.get(i);
        }
        return answer;
    }
	
	public static class Pair implements Comparable<Pair>{
		String song;
		int play;
		Pair(String song, int play){
			this.song = song;
			this.play = play;
		}
		
		public int compareTo(Pair p) {
            return p.play - this.play;
        }

	}
}
