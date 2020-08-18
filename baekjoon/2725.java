package Day05.P2725;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day05\\P2725\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			int N = Integer.parseInt(br.readLine());
			System.out.println(invisible(N));
		}
	}
	
	static int invisible(int N) {
		int count = 0;
		/*
		 * (0, 0)과 (x, y)를 잇는 직선의 기울기 = x / y
		 * 기울기 x / y 가 약분되지 않아야 다른 점을 통과하지 않는다.
		 * 즉, 서로소인 (x, y) 순서쌍 개수를 구한다.
		 * => {euler(2) + euler(3) + ... + euler(N)} * 2 + 3
		 */
		for (int i = 2; i <= N; i++) {
			count += euler(i);
		}
		count = count * 2 + 3;
		return count;
	}
	// 소수 p를 모두 구한 후에 해도 되는데, 그렇게 하나 이렇게 하나 시간 차이는 거의 없다.
	static int euler(int N) {
		int ret = 1;
		for (int p = 2; p * p <= N; p++) {
			int n = 0;
			while(N % p == 0) {
				N /= p;
				n++;
			}
			if(n > 0) ret *= (Math.pow(p, n) - Math.pow(p, n-1));
		}
		if(N > 1) ret *= (N - 1);
		return ret;
	}

	
}
