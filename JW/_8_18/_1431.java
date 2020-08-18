package JW._8_18;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

//�ݷ� A 1 ?? ���� �� ����??
//A�� ������ 0�̴� A�� ����? �ƴϸ� ���ڰ� ���ĺ����� ������ ���������� 1�� ����??
public class _1431 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N;
		String[] Serial;
		
		Scanner s = new Scanner(System.in);
		
		N = s.nextInt();
		s.nextLine();
		
		Serial = new String[N];
		
		for(int i =0;i<N;i++) {
			Serial[i] = s.nextLine();
		}
		
		Arrays.sort(Serial, new Comparator<String>() {

			@Override
			public int compare(String s1, String s2) {
				// TODO Auto-generated method stub
				
				if(s1.length() == s2.length()) {
					int sum1 =0;
					int sum2 =0;
					
					for(int i =0;i<s1.length();i++) {
						if(s1.charAt(i) >= '0' && s1.charAt(i) <= '9')
							sum1 += s1.charAt(i) - '0';
						if(s2.charAt(i) >= '0' && s2.charAt(i) <= '9')
							sum2 += s2.charAt(i) - '0';
					}
					if(sum1 == sum2) {
						return s1.compareTo(s2); 
					}
					else
						return Integer.compare(sum1, sum2);
				}
				
				return Integer.compare(s1.length(), s2.length());
				
			}
		});

		for(int i =0;i<Serial.length;i++) {
			System.out.println(Serial[i]);
		}
	}

}
