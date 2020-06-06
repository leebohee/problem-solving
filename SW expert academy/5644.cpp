#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 10
#define MAX_M 100
#define NUM_PEOPLE 2
#define MAX_BC 8

enum {X, UP, RIGHT, DOWN, LEFT};

using namespace std;

int M, num_bc;
vector<int> available_bc[NUM_PEOPLE]; // index in bc
vector<int> choose;
int max_charge_sum;

struct person {
	int r;
	int c;
	int charge;
	int path[MAX_M];
	person(int r_, int c_) : r(r_), c(c_), charge(0) {
		for (int i = 0; i < M; i++) {
			cin >> path[i];
		}
	};
};

struct charger {
	int r;
	int c;
	int range;
	int power;
	charger(int r_, int c_, int range_, int power_)
		: r(r_), c(c_), range(range_), power(power_) {};
};

vector<person> people;
vector<charger> bc;

int charge() {
	int charge_sum = 0;

	if (choose.size() == 0) return 0;
	if (choose.size() == 1 || choose[0] == choose[1]) {
		return bc[choose[0]].power;
	}
	else {
		charge_sum += bc[choose[0]].power;
		charge_sum += bc[choose[1]].power;
	}
	return charge_sum;
}

void choose_bc(int n) {
	if (n == NUM_PEOPLE) {
		max_charge_sum = max(max_charge_sum, charge());
		return;
	}
	int size = available_bc[n].size();
	if (size == 0) choose_bc(n + 1);
	else {
		for (int i = 0; i < size; i++) {
			choose.push_back(available_bc[n][i]);
			choose_bc(n + 1);
			choose.pop_back();
		}
	}
	
}

int max_sum() {
	int d, max_sum = 0;
	static const int dr[5] = { 0, -1, 0, 1, 0 };
	static const int dc[5] = { 0, 0, 1, 0, -1 };

	for (int itr = 0; itr <= M; itr++) {
		// charge
		for (int i = 0; i < NUM_PEOPLE; i++) available_bc[i].clear();
		choose.clear();
		max_charge_sum = 0;

		for (int i = 0; i < NUM_PEOPLE; i++) {
			for (int j = 0; j < num_bc; j++) {
				d = abs(people[i].r - bc[j].r) + abs(people[i].c - bc[j].c);
				if (d <= bc[j].range) {
					available_bc[i].push_back(j);
				}
			}
		}

		choose_bc(0);
		max_sum += max_charge_sum;

		// move
		if (itr == M) break;
		for (int i = 0; i < NUM_PEOPLE; i++) {
			people[i].r = people[i].r + dr[people[i].path[itr]];
			people[i].c = people[i].c + dc[people[i].path[itr]];
		}
	}
	return max_sum;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, r, c, range, power;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> M >> num_bc;
		people.clear();
		people.push_back(person(0, 0));
		people.push_back(person(SIZE-1, SIZE-1));
		bc.clear();
		for (int i = 0; i < num_bc; i++) {
			cin >> c >> r >> range >> power;
			bc.push_back(charger(r-1, c-1, range, power));
		}
		cout << '#' << test_case << ' ' << max_sum() << '\n';
	}
	return 0;
}