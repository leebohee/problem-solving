package Day02.P2143;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static int T, N, M;
	static int[] A;
	static int[] B;
	
	static List<Integer> subA;
	static List<Integer> subB;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day02\\P2143\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		A = new int [N];
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		B = new int [M];
		for (int i = 0; i < M; i++) {
			B[i] = Integer.parseInt(st.nextToken());
		}
		
		subA = new ArrayList<>();
		subB = new ArrayList<>();
		compute_subsum(A, subA, N);
		compute_subsum(B, subB, M);
		
//		Collections.sort(subA);
		Collections.sort(subB);
		System.out.println(subA.toString());
		System.out.println(subB.toString());
		
		long count = 0; // answer can be out of INT range (10^6 * 10^6)
		for (int num: subA) {
			// find lower bound and upper bound for (T-num) at subB
			int lb = lower_bound(subB, T-num);
			int ub = upper_bound(subB, T-num);;
			
			count += (ub - lb);
		}
		System.out.println(count);
	}
	
	static void compute_subsum(int[] arr, List<Integer> subarr, int n) {
		for (int i = 0; i < n; i++) {
			int subsum = 0;
			for (int j = i; j < n; j++) {
				subsum += arr[j];
				subarr.add(subsum);
			}
		}
	}
	
	static int lower_bound(List<Integer> subarr, int target) {
		int low = 0, high = subarr.size()-1;
		int index = subarr.size();
		
		while(low <= high) {
			int mid = low + (high-low) / 2;
			if(subarr.get(mid) == target) {
				index = mid;
				high = mid - 1;
			}
			else if(subarr.get(mid) > target) {
				index = Math.min(index, mid);
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		
		return index;
	}
	static int upper_bound(List<Integer> subarr, int target) {
		int low = 0, high = subarr.size()-1;
		int index = subarr.size();
		
		while(low <= high) {
			int mid = low + (high-low) / 2;
			if(subarr.get(mid) == target) {
				low = mid + 1;
			}
			else if(subarr.get(mid) > target) {
				index = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		
		return index;
	}
//	lower_bound(arr, 0, arr.size()-1, 3);
//	static int lower_bound(List<Integer> subarr, int left, int right, int target) {
//		int mid = 0;
//		
//		while(left < right) {
//			mid = left + (right-left) / 2;
//			if(subarr.get(mid) < target) {
//				left = mid + 1;
//			}
//			else{
//				right = mid;
//			}
//		}
//		
//		return right;
//	}
//	upper_bound(arr, 0, arr.size()-1, 3);
//	static int upper_bound(List<Integer> subarr, int left, int right, int target) {
//		int mid = 0;
//		
//		while(left < right) {
//			mid = left + (right-left) / 2;
//			if(subarr.get(mid) <= target) {
//				left = mid + 1;
//			}
//			else{
//				right = mid;
//			}
//		}
//		
//		return right;
//	}
}
