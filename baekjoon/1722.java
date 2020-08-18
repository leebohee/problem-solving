package Day05.P1722;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int nums[];
	static int N;
	static long K;
	static long dp[];
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day05\\P1722\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		nums = new int [N];
		dp = new long [N+1];
		
		st = new StringTokenizer(br.readLine());
		int type = Integer.parseInt(st.nextToken());
		if(type == 1) {
			K = Long.parseLong(st.nextToken());
			System.out.println(kth_perm());
		}
		else {
			for (int i = 0; i < N; i++) {
				nums[i] = Integer.parseInt(st.nextToken());
			}
			System.out.println(find_k());
		}
	}
	
	static String kth_perm() {
		long k = K;
		StringBuilder sb = new StringBuilder();
		boolean[] visit = new boolean [N+1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if(visit[j]) continue;
				long fact = factorial(N-i);
				if(fact >= k) {
					visit[j] = true;
					sb.append(j);
					sb.append(" ");
					break;
				}
				else {
					k -= fact;
				}
			}
		}
		return sb.toString();
	}
	
	static long find_k() {
		long k = 0;
		boolean[] visit = new boolean [N+1];
		for (int i = 0; i < N; i++) {
			int digit = nums[i];
			visit[digit] = true;
			for (int j = 1; j < digit; j++) {
				if(!visit[j]) k += factorial(N-i-1);
			}
		}
		return k+1;
	}
	static long factorial(int n) {
		if(n <= 1) return 1;
		if(dp[n] == 0) {
			dp[n] = n * factorial(n-1);
		}
		return dp[n];
	}
}
