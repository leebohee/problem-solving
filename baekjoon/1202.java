package Day03.P1202;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Jewel /*implements Comparable<Jewel>*/ {
	int weight;
	int value;

	public Jewel(int weight, int value) {
		super();
		this.weight = weight;
		this.value = value;
	}

	@Override
	public String toString() {
		return "Jewel [weight=" + weight + ", value=" + value + "]";
	}

	/*@Override
	public int compareTo(Jewel j) {
		// TODO Auto-generated method stub
		if (this.value > j.value)
			return -1;
		else if (this.value == j.value)
			return 0;
		else
			return 1;
	}*/

	public int getWeight() {
		return weight;
	}
	public int getValue() {
		return value;
	}
}

public class Main {
	static int N, K;
	static int[] bags;
	static Jewel[] jewels;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day03\\P1202\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		jewels = new Jewel[N];
		bags = new int[K];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			jewels[i] = new Jewel(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			bags[i] = Integer.parseInt(st.nextToken());
		}

		// sort
		/*Arrays.sort(jewels, new Comparator<Jewel>() {
			@Override
			public int compare(Jewel j1, Jewel j2) {
				// TODO Auto-generated method stub
				if(j1.weight < j2.weight) return -1;
				else if(j1.weight == j2.weight) return 0;
				else return 1;
			}
		});*/
		Arrays.sort(jewels, Comparator.comparing(Jewel::getWeight));
		Arrays.sort(bags);
		
		long sum = 0;
		int j = 0;
		PriorityQueue<Jewel> pq = new PriorityQueue<>(Comparator.comparing(Jewel::getValue).reversed());
		for (int i = 0; i < K; i++) {
			// 가방에 넣을 수 있는 보석들을 PQ에 넣는다.
			for(; j < N; j++) {
				if(jewels[j].weight <= bags[i]) pq.add(jewels[j]);
				else break;
			}
			// 넣을 수 있는 보석들 중 가치가 가장 큰 보석을 선택한다.
			if(!pq.isEmpty()) {
				sum += pq.poll().value;
			}
		}
		System.out.println(sum);
	}

}
