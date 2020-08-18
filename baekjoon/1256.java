package Day05.P1256;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N, M, K;
	static int[][] dp;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day05\\P1256\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		StringBuilder sb = new StringBuilder();
		
		int len = N + M;
		dp = new int [len+1][len+1];
		
		
		if(combination(len, N) < K) {
			System.out.println(-1);
			return;
		}
		
		int selectedA = 0, selectedZ = 0;
		for (int i = 1; i <= len; i++) {
			int num_startA = combination(len-i, N-(selectedA+1));
			if(num_startA >= K) {
				selectedA++;
				sb.append('a');
				if(selectedA == N) break;
			}
			else {
				selectedZ++;
				sb.append('z');
				K = K - num_startA;
			}
		}
		while(selectedZ < M) {
			sb.append('z');
			selectedZ++;
		}
		System.out.println(sb);
		
	}
	static int combination(int n, int k) {
		if(k == 0 || k == n) return 1;
		if(dp[n][k] == 0) {
			dp[n][k] = Math.min(1000000001, combination(n-1, k-1));
			dp[n][k] = Math.min(1000000001, dp[n][k] + combination(n-1, k));
		}
		return dp[n][k];
	}
}
