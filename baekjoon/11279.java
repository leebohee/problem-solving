package Day03.P11279;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static int N, n;
	static int[] heap;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day03\\P11279\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		heap = new int [N+1];
		n = 0;
		for (int i = 0; i < N; i++) {
			int command = Integer.parseInt(br.readLine());
			if(command == 0) { // 가장 큰 값 출력
				System.out.println(pop());
			}
			else { // 힙에 원소 추가
				insert(command);
			}
		}
	}
	static void insert(int x) {
		heap[++n] = x;
		
		int cur = n, parent = cur / 2;
		while(parent >= 1) {
			if(heap[parent] < heap[cur]) { 
				// swap
				int tmp = heap[parent];
				heap[parent] = heap[cur];
				heap[cur] = tmp;
				
				cur = parent;
				parent /= 2;
			}
			else break;
		}
		
	}
	static int pop() {
		if(n == 0) return 0;
		
		int ret = heap[1];
		heap[1] = heap[n--];
		
		int cur = 1, left = cur * 2, right = cur * 2 + 1;
		while(true) {
			if(left > n) break;
			if(right > n) {
				if(heap[left] > heap[cur]) {
					// swap with left child
					int tmp = heap[left];
					heap[left] = heap[cur];
					heap[cur] = tmp;
				}
				break;
			}
			
			if(Math.max(heap[left], heap[right]) > heap[cur]) {
				if(heap[left] > heap[right]) {
					// swap with left child
					int tmp = heap[left];
					heap[left] = heap[cur];
					heap[cur] = tmp;
					
					cur = left;
				}
				else {
					// swap with right child
					int tmp = heap[right];
					heap[right] = heap[cur];
					heap[cur] = tmp;
					
					cur = right;
				}
				left = cur * 2;
				right = cur * 2 + 1;
			}
			else break;
		}
		
		return ret;
	}

}
