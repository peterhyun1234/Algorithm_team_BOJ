package _7_17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

//���ڿ� 0 �� ���� ó��? trim �յ� ����
public class _1152 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		String input;
		int result;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringBuilder sb = new StringBuilder();
		
		input = br.readLine();
		
		input = input.trim();
		result = input.split(" ").length;

		if(input.isEmpty())
			System.out.println(0);
		else
			System.out.println(result);
	}

}
