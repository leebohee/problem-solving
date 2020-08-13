package Day03.P2042;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 참고링크: https://www.geeksforgeeks.org/segment-tree-efficient-implementation/

public class Main {
	static int N, M, K;
	static long[] nums;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day03\\P2042\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		int depth = 0;
		while(Math.pow(2, depth) < N) depth++;
		nums = new long [(int) ((long) Math.pow(2, depth) + 1)];
		
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			nums[i] = Integer.parseInt(st.nextToken());
		}
		
		IndexedTree it = new IndexedTree(nums);
		//System.out.println(it);
		it.makeTree(1, 1, it.leafSize);
		//System.out.println(it);
		
		
		for (int i = 0; i < M + K; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			long c = Integer.parseInt(st.nextToken());
		
			if(a == 1) { // update
				long diff = c - it.nums[b];
				it.update(1, 1, it.leafSize, b, diff);
				it.nums[b] = c;
				//System.out.println(it);
			}
			else { // query sum
				System.out.println(it.query(1, 1, it.leafSize, b, (int)c));
			}
		}
	}

}

class IndexedTree {
	long[] tree; // indexed tree
	long[] nums; // 실제 값
	int leafSize, depth;

	public IndexedTree(long[] nums) {
		this.nums = nums;
		this.depth = 0;
		// nums[0]: dummy value
		while (Math.pow(2, this.depth) < nums.length - 1) {
			this.depth++;
		}
		this.leafSize = (int) Math.pow(2, depth);
		this.tree = new long[(int) Math.pow(2, depth + 1)];
	}

	// 내부 노드의 값을 채워준다.
	// node: tree[]에서의 인덱스
	// left: 구간의 시작 값, right: 구간의 끝 값
	public long makeTree(int node, int left, int right) {
		// leaf에 도달하면 데이터를 채워준다.
		if (left == right) {
			if (left <= nums.length) {
				return tree[node] = nums[left];
			} else { // 여유 공간 => 합에 영향을 미치지 않게 0으로 초기화
				return tree[node] = 0;
			}
		}
		// internal 노드일 때, left와 right의 값을 합하여 저장한다.
		int mid = left + (right - left) / 2;
		// 좌우를 호출하지만 같은 레벨에 있으므로 시간복잡도에선 상수 취급 => O(logN)
		// 호출되는 횟수를 기준으로 시간복잡도를 계산한다면 O(N)
		tree[node] = makeTree(node * 2, left, mid);
		tree[node] += makeTree(node * 2 + 1, mid + 1, right);
		return tree[node];
	}

	// 원하는 구간의 합 or 문제의 답을 구한다.
	// left: 노드의 구간 시작 값, right: 노드의 구간 끝 값
	// qLeft: 쿼리의 구간 시작 값, qRight: 쿼리의 구간 끝 값
	public long query(int node, int left, int right, int qLeft, int qRight) {
		if (qRight < left || right < qLeft) { // 관련 없는 경우
			/*
			 * <---query---> <-node-> <-node->
			 */
			return 0; // 바로 리턴하니까 시간복잡도 계산에 고려하지 않아도 됨
		} else if (qLeft <= left && right <= qRight) { // 쿼리에 완전 속하는 경우
			/*
			 * <----query----> <--node-->
			 */
			return tree[node];
		} else { // 그 외 (애매하게 걸쳐있는 경우)
			/*
			 * <---query---> <--node--> <----node---->
			 */
			int mid = left + (right - left) / 2;
			return query(node * 2, left, mid, qLeft, qRight) + query(node * 2 + 1, mid + 1, right, qLeft, qRight);
		}
	}

	// 특정 값을 갱신한다.
	public void update(int node, int left, int right, int index, long diff) {
		if (index < left || right < index) {
			return;
		} else {
			tree[node] += diff;
			if (left != right) { // 내부 노드 (leaf에 도달할 때까지 재귀적으로 업데이트)
				int mid = (left + right) / 2;
				update(node * 2, left, mid, index, diff);
				update(node * 2 + 1, mid + 1, right, index, diff);
			}
		}
	}

	@Override
	public String toString() {
		return "IndexedTree [tree=" + Arrays.toString(tree) + ", nums=" + Arrays.toString(nums) + ", leafSize="
				+ leafSize + ", depth=" + depth + "]";
	}

}