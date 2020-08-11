package Day02.P2517;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Runner{
	int index;
	int inv_count;
	int ability;
	public Runner(int index, int inv_count, int ability) {
		super();
		this.index = index;
		this.inv_count = inv_count;
		this.ability = ability;
	}
	@Override
	public String toString() {
		return "Runner [index=" + index + ", inv_count=" + inv_count + ", ability=" + ability + "]";
	}
}

public class Main {
	static int N;
	static Runner[] runners;
	static Runner[] temp;
	static int[] rank;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("src\\Day02\\P2517\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		runners = new Runner [N];
		temp = new Runner [N];
		rank = new int [N];
		for (int i = 0; i < N; i++) {
			rank[i] = i+1;
			st = new StringTokenizer(br.readLine());
			runners[i] = new Runner(i, 0,  Integer.parseInt(st.nextToken()));
		}
		
		mergeSort(0, runners.length-1);
		
		for (Runner r: runners) {
			rank[r.index] -= r.inv_count;
		}
		for (int i = 0; i < N; i++) {
			System.out.println(rank[i]);
		}
	}

	public static void mergeSort(int s, int e) {
		if(s >= e) return;
		int mid = s + (e - s) / 2;
		mergeSort(s, mid);
		mergeSort(mid+1, e);
		merge(s, mid, e);
	}

	public static void merge(int s, int m, int e) {
		int p1 = s, p2 = m+1;
		int k = s;
		while(p1 <= m && p2 <= e) {
			if(runners[p1].ability < runners[p2].ability) {
				temp[k++] = runners[p1++];
			}
			else {
				runners[p2].inv_count += (p1-s);
				temp[k++] = runners[p2++];
			}
		}
		while(p1 <= m) {
			temp[k++] = runners[p1++];
		}
		while(p2 <= e) {
			runners[p2].inv_count += (p1-s);
			temp[k++] = runners[p2++];
		}
		for (int i = s; i <= e; i++) {
			runners[i] = temp[i];
		}
	}

}


