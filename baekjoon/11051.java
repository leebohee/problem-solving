package Day05.P11051;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int[][] dp;
	static int MOD = 10007;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		if(K > N / 2) K = N - K;
		dp = new int [N+1][N+1];
		
		for (int i = 1; i <= N; i++) {
			dp[i][0] = dp[i][i] = 1;
			for (int j = 1; j < i; j++) {
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
			}
		}
		System.out.println(dp[N][K]);
//		System.out.println(combination(N, K));		
	}
	
	static int combination(int N, int K) {
		if(K > N / 2) K = N - K;
		if(K == 0) return 1;
		if(dp[N][K] == 0) dp[N][K] = (combination(N-1, K-1) + combination(N-1, K)) % MOD;
		return dp[N][K];
	}

}
