package Day05.P11653;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int i = 2;
		while(N > 1) {
			while(N % i == 0) {
				N /= i;
				System.out.println(i);
			}
			i++;
		}	
	}
}
