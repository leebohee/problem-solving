package Day02.P2748;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		if(n <= 1) {
			System.out.println(n);
		}
		else {
			long fib = 0, prev1 = 1, prev2 = 0;
			for (int i = 2; i <= n; i++) {
				fib = prev1 + prev2;
				prev2 = prev1;
				prev1 = fib;
			}	
			System.out.println(fib);
		}
	}

}
