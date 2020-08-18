package Day05.P1010;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[][] dp;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day05\\P1010\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		dp = new int [30][30];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		for (int i = 0; i < T; i++) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			System.out.println(combination(M, N));
		}
	}
	
	static int combination(int n, int k) {
		if(k > n / 2) k = n - k;
		if(k == 0) return 1;
		if(dp[n][k] == 0) {
			dp[n][k] = combination(n-1, k-1) + combination(n-1, k);
		}
		return dp[n][k];
	}

}
