package JW._8_25;

import java.util.Arrays;

public class Sort_3 {

	static int[] citations = {5, 5, 5, 5};
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(solution(citations));

	}
	
	public static int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        int H;
        
        for(int i=1;i<citations.length+1;i++) {
        		H = 0;
        	for(int j=0;j<citations.length;j++) {
        		if(i <= citations[j])
        			break;
        		H++;
        	}
        	H = citations.length - H;
        	if(H < i) {
        		answer = i - 1;
        		break;
        	}
        	//�� �ڵ带 ���� ������ �׽�Ʈ ���̽� 9���� ������� ���Ѵ�!!
        	//��?? �ݷ� {5, 5, 5, 5} ==> output : 4�� �ذ�
        	if(i == citations.length)
        		answer = i;
        }
        return answer;
    }

}
