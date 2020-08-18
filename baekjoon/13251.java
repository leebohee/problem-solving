package Day05.P13251;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N, M, K;
	static int nums[];

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day05\\P13251\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		M = Integer.parseInt(br.readLine());
		nums = new int[M];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			nums[i] = Integer.parseInt(st.nextToken());
			N += nums[i];
		}
		K = Integer.parseInt(br.readLine());

		double result = 0.0;
		for (int i = 0; i < M; i++) {
			if(nums[i] - K < 0) continue;
			double pos = 1.0;
			for (int j = 0; j < K; j++) {
				pos *= ((double)(nums[i] - j) / (double)(N - j));
			}
			result += pos;
		}
		System.out.println(result);
	}
}
