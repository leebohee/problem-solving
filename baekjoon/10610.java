package Day05.P10610;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String N = br.readLine();
		
		
		char[] digits = new char [N.length()];
		// 30의 배수인지 아닌지 확인
		int digit_sum = 0;
		boolean contain_zero = false;
		for (int i = 0; i < N.length(); i++) {
			if(N.charAt(i) == '0') contain_zero = true;
			digit_sum += (N.charAt(i) - '0');
			digits[i] = N.charAt(i);
		}
		if(digit_sum % 3 == 0 && contain_zero) {
			Arrays.sort(digits);
			for(int i = digits.length - 1; i >= 0; i--) {
				System.out.print(digits[i]);
			}
		}
		else System.out.println(-1);
	}

}
