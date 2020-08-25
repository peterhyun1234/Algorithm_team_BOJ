package JW._8_21;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/*
 * 스택 입문용으로 쓰기엔 너무 어려운 문제라고 생각하는데 왜 이렇게 인기가 많은지...

내장함수의 시간복잡도를 숙지합시다. 여기 올라오는 대부분의 시간 초과 질문은 내장함수를 잘못 사용하여 O(N^2)의 시간복잡도를 가지는 질문입니다. 예를 들면 (이외에도 수많은 경우가 있습니다)

C의 strlen
C++의 string.erase
Java의 String.replaceAll
Python의 str.replace, str.find, list.pop(i), list.index, ''.join, [:i], [i:]
굳이 내장함수가 아니더라도 단순히 문자열의 중간을 한 번 지울 때마다 거의 무조건 O(N)이 걸립니다. 직접 구현한 코드의 시간복잡도를 계산해 보세요.
런타임 에러의 경우 인덱스 참조에 유의합시다.
 */

//메모리초과?? -> String에 + 연산은 시간과 메모리가 많이 쓰임
//String 버퍼를 사용
//String + 연산과 String 빌더 비교 -> https://novemberde.github.io/2017/04/15/String_0.html


// result 배열에 넣어주면서 idx를 조절해가며 bomb을 발견했을시 bomb만큼 길이를 idx를 조절하여 덮어씌운다.

public class _9935 {

	static String text;
	static String bomb;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		text = br.readLine();
		bomb = br.readLine();
		
		char[] result = new char[text.length()];
		int idx = 0;
		
		for(int i =0;i<text.length();i++) {
			result[idx] = text.charAt(i);
			if(isbomb(result, idx)) {
				idx -= bomb.length();
			}
			
			idx++;
		}
		
		String ans = String.valueOf(result, 0, idx);
		
		if(ans.length() == 0)
			System.out.println("FRULA");
		else
			System.out.println(ans);
		
	}
	
	public static boolean isbomb(char[] result, int idx) {
		
		if(idx < bomb.length() - 1)
			return false;
		
		for(int i =0;i<bomb.length();i++) {
			if(bomb.charAt(i) != result[idx - bomb.length() + 1 + i])
				return false;
		}
		
		return true;
	}
	

}

/*
 * public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		Stack<String> st = new Stack();
		String text = br.readLine();
		String bomb = br.readLine();
		String revbomb = revtext(bomb);
		String end = "" + bomb.charAt(bomb.length()-1);
		String ans = "";
		
		for(int i =0;i<text.length();i++) {
			String a = "" + text.charAt(i);
			if(bomb.contains(a)) {
				st.push(a);
				if(a.equals(end)) {
					String tmp = "";
					while(true) {
						tmp += st.pop();
						if(tmp.equals(revbomb))
							break;
						if(st.isEmpty()) {
							ans += revtext(tmp);
							break;
						}
					}
				}
			}
			else {
				if(st.isEmpty())
					ans += a;
				else {
					String tmp = "";
					while(!st.isEmpty()) {
						tmp += st.pop();
					}
					ans += revtext(tmp) + a;
				}
			}
		}
		
		if(ans.length() == 0)
			System.out.println("FRULA");
		else
			System.out.println(ans);

	}
	
	public static String revtext(String s) {
		
		String rev = "";
		for(int i =s.length()-1;i>=0;i--) {
			rev += s.charAt(i);
		}
		
		return rev;
	}
 */