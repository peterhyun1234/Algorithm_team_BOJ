package JW._8_21;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/*
 * ���� �Թ������� ���⿣ �ʹ� ����� ������� �����ϴµ� �� �̷��� �αⰡ ������...

�����Լ��� �ð����⵵�� �����սô�. ���� �ö���� ��κ��� �ð� �ʰ� ������ �����Լ��� �߸� ����Ͽ� O(N^2)�� �ð����⵵�� ������ �����Դϴ�. ���� ��� (�̿ܿ��� ������ ��찡 �ֽ��ϴ�)

C�� strlen
C++�� string.erase
Java�� String.replaceAll
Python�� str.replace, str.find, list.pop(i), list.index, ''.join, [:i], [i:]
���� �����Լ��� �ƴϴ��� �ܼ��� ���ڿ��� �߰��� �� �� ���� ������ ���� ������ O(N)�� �ɸ��ϴ�. ���� ������ �ڵ��� �ð����⵵�� ����� ������.
��Ÿ�� ������ ��� �ε��� ������ �����սô�.
 */

//�޸��ʰ�?? -> String�� + ������ �ð��� �޸𸮰� ���� ����
//String ���۸� ���
//String + ����� String ���� �� -> https://novemberde.github.io/2017/04/15/String_0.html


// result �迭�� �־��ָ鼭 idx�� �����ذ��� bomb�� �߰������� bomb��ŭ ���̸� idx�� �����Ͽ� ������.

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