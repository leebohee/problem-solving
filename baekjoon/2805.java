package Day02.P2805;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day02\\P2805\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int max = 0;
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] height = new int [N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			height[i] = Integer.parseInt(st.nextToken());
			max = Math.max(max, height[i]);
		}
		
		int left = 0, right = max, mid = -1;
		int result = 0;
		// parametric search
		while(left <= right) {
			mid = left + (right - left) / 2;
			
			// compute trees
			long sum = 0;
			for (int i = 0; i < N; i++) {
				if(height[i] > mid) sum += (height[i]-mid);
			}

			// 잘린 나무의 양이 적으면, 높이를 낮추어야 함 (-> 그래야 잘린 나무의 양이 커짐)
			if(sum < M) right = mid - 1;
			// 잘린 나무의 양이 M과 같으면 정답!
			else if(sum == M) {
				result = mid;
				break;
			}
			// 잘린 나무의 양이 많으면, 높이를 높여야 함
			else{
				result = mid;
				left = mid + 1;
			}
		}
		
		mid = left + (right - left) / 2;
		System.out.println(result);
		
	}

}
