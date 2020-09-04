package JW._8_28;


//모르겠음 다시풀기!
public class N으로표현 {

	static int N = 4;
	static int number = 17;

	static int answer = -1;
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(solution(N, number));
	}

    public static int solution(int N, int number) {
    	
        dfs(N, 0, 0, number, "");
        return answer;
    }

    public static void dfs(int n, int pos, int num, int number, String s) {
        if (pos > 8)
            return;
        if (num == number) {
            if (pos < answer || answer == -1) {
                System.out.println(s);
                answer = pos;
            }
            return;
        }
        int nn=0;
        for (int i = 0; i < 8; i++) {
            nn=nn*10+n;
            dfs(n, pos + 1+i, num + nn, number, s + "+");
            dfs(n, pos + 1+i, num - nn, number, s + "-");
            dfs(n, pos + 1+i, num * nn, number, s + "*");
            dfs(n, pos + 1+i, num / nn, number, s + "/");
        }
        // dfs(n,pos+1,num*10+n,number,s+"5");
    }
}


/*
public int solution(int N, int number) {
int answer = -1;
HashSet<Integer>[] set = new HashSet[9];

for(int i =0;i<9;i++) {
	set[i] = new HashSet<Integer>();
}
set[1].add(N);
if(number == N)
	answer = 1;

for(int i =2;i<8;i++) {
	Iterator iter = set[i-1].iterator();
	
	while(iter.hasNext()) {
		int tmp = (int)iter.next();
		
		if(tmp + N == number) {
			answer = i;
			return answer;
		}
		set[i].add(tmp + N);
		
		if(tmp - N == number) {
			answer = i;
			return answer;
		}
		set[i].add(tmp - N);
		
		if(N - tmp == number) {
			answer = i;
			return answer;
		}
		set[i].add(N - tmp);
		
		if(tmp * N == number) {
			answer = i;
			return answer;
		}
		set[i].add(tmp * N);
		
		if(tmp / N == number) {
			answer = i;
			return answer;
		}
		set[i].add(tmp /N);
		
		if(tmp != 0) {
			if(N / tmp == number) {
				answer = i;
				return answer;
			}
			set[i].add(N/tmp);
		}
		
		if(tmp * 10 + N == number) {
			answer = i;
			return answer;
		}
		set[i].add(tmp *10 + N);
	}
}

return answer;
}*/