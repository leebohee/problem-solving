package Day03.P2243;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static int[] candies; // candy[i]: 맛이 i인 사탕 개수

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day03\\P2243\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		candies = new int[1000001];

		IndexedTree it = new IndexedTree(candies);
		it.makeTree(1, 1, it.leafSize);

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());

			if (A == 1) { // 순위가 B인 사탕 꺼내기
				// 순위가 B인 사탕 구하기 == indexed tree에서 B를 쿼리하는데, 노드의 값(개수누적합)과 B를 비교해서
				// 마지막 레벨까지 찾아감
				/*
				 * 자신의 왼쪽 자식의 값과 쿼리의 값을 비교해서, 왼쪽 자식 값이 크거 같으면 왼쪽으로 (순위)로 쿼리 왼쪽 자식 값이 더 작으면 오른쪽으로
				 * (순위-왼쪽 자식값)으로 쿼리 
				 *   4
				 *  / \ 
				 * 1   3
				 * 
				 * 에서 2위를 찾고 싶으면 오른쪽 자식노드에게 (2-1)위를 쿼리를 날림 만약 1위를 찾고 싶었으면 왼쪽 자식
				 */
				int flavor = it.query(1, 1, it.leafSize, B);
				it.update(1, 1, it.leafSize, flavor, -1);
				System.out.println(flavor);
			} else { // 맛이 B인 사탕 C개 추가하기
				int C = Integer.parseInt(st.nextToken());
				it.update(1, 1, it.leafSize, B, C);
			}
		}

	}

}

class IndexedTree {
	int[] tree; // indexed tree
	int[] nums; // 실제 값
	int leafSize, depth;

	public IndexedTree(int[] nums) {
		this.nums = nums;
		this.depth = 0;
		// nums[0]: dummy value
		while (Math.pow(2, this.depth) < nums.length - 1) {
			this.depth++;
		}
		this.leafSize = (int) Math.pow(2, depth);
		this.tree = new int[(int) Math.pow(2, depth + 1)];
	}

	// 내부 노드의 값을 채워준다.
	// node: tree[]에서의 인덱스
	// left: 구간의 시작 값, right: 구간의 끝 값
	public int makeTree(int node, int left, int right) {
		// leaf에 도달하면 데이터를 채워준다.
		if (left == right) {
			if (left < nums.length) {
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

	public int query(int node, int left, int right, int rank) {
		if (left == right) return left;
		int mid = left + (right - left) / 2;
		if (tree[node * 2] >= rank) {
			return query(node * 2, left, mid, rank);
		} else {
			return query(node * 2 + 1, mid + 1, right, rank - tree[node * 2]);

		}
	}

	// 특정 값을 갱신한다.
	public void update(int node, int left, int right, int index, int diff) {
		if (index < left || right < index) {
			return;
		} else {
			tree[node] += diff;
			if (left != right) { // 내부 노드 (leaf에 도달할 때까지 재귀적으로 업데이트)
				int mid = left + (right - left) / 2;
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