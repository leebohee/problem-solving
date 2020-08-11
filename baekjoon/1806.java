package Day02.P1806;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day02\\P1806\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		int N = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());
		
		int[] nums = new int [N+1];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			nums[i] = Integer.parseInt(st.nextToken());
		}
		
		int low = 0, high = 0, result = N+1;
		int sum = nums[0]; // sum = nums[low~high]의 합
		while(high < N) {
			// sum >= S면 길이 저장하고, low++
			if(sum >= S) {
				result = Math.min(result, high - low + 1);
				sum -= nums[low++];
			}
			// sum < S면 high++
			else {
				sum += nums[++high];
			}
		}
		
		if(result > N) System.out.println(0);
		else System.out.println(result);
		
	}

}
