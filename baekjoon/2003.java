package Day02.P2003;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day02\\P2003\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] arr = new int [N + 1]; // 원소를 하나 더 만들어주는 트릭!
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		System.out.println(Arrays.toString(arr));
		
		int lo = 0, hi = 0, ret = 0;
		int sum = arr[0]; // arr[lo~hi]의 합
		while(hi < N) {
			if(sum < M) {
				sum += arr[++hi];
			}
			else if(sum == M) {
				ret++;
				sum -= arr[lo++];
			}
			else {
				sum -= arr[lo++];
			}
		}
		System.out.println(ret);
	}

}
