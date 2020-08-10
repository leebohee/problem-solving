// BOJ에서 패키지 이름을 제거하지 않고 제출하면 런타임 에러 발생
package Day01.P1062;

import java.io.FileInputStream;
import java.util.Scanner;

// BOJ에서 클래스 이름은 무조건 'Main'으로 지정해야 한다. 그렇지 않으면 컴파일 에러 발생
public class Main {
	static int N, K;
	static String[] words;
	static boolean[] visited;
	static int selectedCount = 0;
	static int max = 0;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day01\\P1062\\input.txt"));

//		 입출력은 scanner보다 BufferReader를 사용하는 것이 빠르다 
//		(BufferReader에서 사용하는 버퍼 사이즈가 더 커서)
		Scanner sc = new Scanner(System.in);
		
		N = Integer.parseInt(sc.next());
		K = Integer.parseInt(sc.next());
//		System.out.println(N + ", " + K);
		
		words = new String[N];
		visited = new boolean[26];
		visited['a'-'a'] = true;
		visited['n'-'a'] = true;
		visited['t'-'a'] = true;
		visited['i'-'a'] = true;
		visited['c'-'a'] = true;
		
		for (int i = 0; i < N; i++) {
//			words[i] = sc.next();
			words[i] = sc.next().replaceAll("[antic]", "");
		}
//		System.out.println(Arrays.toString(words));
		selectedCount = 5;
		if(selectedCount > K) {
			System.out.println(0);
			return;
		}
		max = countWords();
		for (int i = 0; i < visited.length; i++) {
			if(!visited[i]) dfs(i);
		}
		System.out.println(max);
	}
	
	/*
	 * index: 지금 방문하는(선택한) 알파벳 종류
	 */
	static void dfs(int index) {
//		1. 체크인
		visited[index] = true;
		selectedCount++;
//		2. 목적지인가?
		if(selectedCount == K) {
			max = Math.max(max, countWords());
		}
		else {
//			3. 갈 수 있는 곳을 순회
			for (int i = index+1; i < visited.length; i++) {
//				4. 갈 수 있는가?
				if(!visited[i]) {
//					5. 간다 dfs(next)
					dfs(i);
				}
			}
		}
//		6. 체크아웃
		visited[index] = false;
		selectedCount--;
	}
	
	static int countWords() {
		int count = 0;
		for (int i = 0; i < N; i++) {
			boolean isPossible = true;
			String word = words[i];
			for (int j = 0; j < word.length(); j++) {
				if(!visited[word.charAt(j)-'a']) {
					isPossible = false;
					break;
				}
			}
			if(isPossible) {
				count++;
			}
		}
		return count;
	}

}
