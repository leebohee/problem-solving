import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int N, total_num;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		total_num = sc.nextInt();

		List<Candidate> candidates = new ArrayList<>();

		for (int i = 0; i < total_num; i++) {
			int can = sc.nextInt();
			boolean added = false;
			for (int j = 0; j < candidates.size(); j++) {
				Candidate c = candidates.get(j);
				if (c.val == can) {
					c.inc_num();
					added = true;
					break;
				}
			}
			if (!added) {
				if (candidates.size() == N) {
					Collections.sort(candidates, new Comparator<Candidate>() {
						@Override
						public int compare(Candidate c1, Candidate c2) {
							if (c1.num > c2.num) return -1;
							else if (c1.num == c2.num) {
								if (c1.date > c2.date) return -1;
								else if (c1.date == c2.date) return 0;
								else return 1;
							} else return 1;
						}
					});
					candidates.remove(N - 1);
				}
				candidates.add(new Candidate(can, 1, i, true));
			}

			// }
		}

		Collections.sort(candidates, new Comparator<Candidate>() {
			@Override
			public int compare(Candidate c1, Candidate c2) {
				if (c1.val < c2.val) return -1;
				else if (c1.val == c2.val) return 0;
				else return 1;
			}
		});

		for (Candidate can: candidates) {
			System.out.print(can.val + " ");
		}
	}

}

class Candidate {
	int val;
	int num;
	int date;
	boolean is_in;

	public Candidate(int val, int num, int date, boolean is_in) {
		super();
		this.val = val;
		this.num = num;
		this.date = date;
		this.is_in = is_in;
	}

	@Override
	public String toString() {
		return "Candidate [val=" + val + ", num=" + num + ", date=" + date + "]";
	}

	public void inc_num() {
		this.num++;
	}
}