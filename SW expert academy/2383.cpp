#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX_SIZE 10

using namespace std;

int N, result;
int map[MAX_SIZE][MAX_SIZE];
bool choose_stair[MAX_SIZE];

int dist[2][MAX_SIZE];

vector< pair<int, int> > people;
vector< pair<int, int> > stairs;

int num_people;


int max(vector<int>& v) {
	int size = v.size();
	if (size == 0) return -1;
	int ret = v[0];
	for (int i = 1; i < size; i++) {
		if (v[i] > ret) ret = v[i];
	}
	return ret;
}

int calc_time() {
	vector<int> dist_to_stair0;
	vector<int> dist_to_stair1;

	 // calculate time to move
	for (int i = 0; i < num_people; i++) {
		if (choose_stair[i]) {
			dist_to_stair1.push_back(dist[1][i]);
		}
		else {
			dist_to_stair0.push_back(dist[0][i]);
		}
	}
	sort(dist_to_stair0.begin(), dist_to_stair0.end());
	sort(dist_to_stair1.begin(), dist_to_stair1.end());

	int start = 0, end = 0, n = dist_to_stair0.size();
	int i;
	while (start < n) {
		if (end >= n) {
			dist_to_stair0[start] = dist_to_stair0[start] + 1 + map[stairs[0].first][stairs[0].second];
			start++;
		}
		else if (end - start >= 3) {
			dist_to_stair0[start] = dist_to_stair0[start] + 1 + map[stairs[0].first][stairs[0].second];
			if (dist_to_stair0[end] < dist_to_stair0[start]) {
				dist_to_stair0[end] = dist_to_stair0[start] - 1;
				start++;
				end++;
			}
			else {
				start++;
			}
		}
		else {
			end++;
		}
	}
	start = 0, end = 0, n = dist_to_stair1.size();
	while (start < n) {
		if (end >= n) {
			dist_to_stair1[start] = dist_to_stair1[start] + 1 + map[stairs[1].first][stairs[1].second];
			start++;
		}
		else if (end - start >= 3) {
			dist_to_stair1[start] = dist_to_stair1[start] + 1 + map[stairs[1].first][stairs[1].second];
			if (dist_to_stair1[end] < dist_to_stair1[start]) {
				dist_to_stair1[end] = dist_to_stair1[start] - 1;
				start++;
				end++;
			}
			else {
				start++;
			}
		}
		else {
			end++;
		}
	}
	
	return max(max(dist_to_stair0), max(dist_to_stair1));
}
int comb;
void min_time(int n) {
	if (n == num_people) {
		comb++;
		int ret = calc_time();
		result = min(result, ret);
		return;
	}
	choose_stair[n] = false;
	min_time(n + 1);
	choose_stair[n] = true;
	min_time(n + 1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		people.clear();
		stairs.clear();
		stairs.reserve(2);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					people.push_back({ i, j });
				}
				else if (map[i][j] >= 2) {
					stairs.push_back({ i, j });
				}
			}
		}

		num_people = people.size();
		// calculate time to move
		for (int i = 0; i < num_people; i++) {
			dist[0][i] = abs(people[i].first - stairs[0].first) + abs(people[i].second - stairs[0].second);
			dist[1][i] = abs(people[i].first - stairs[1].first) + abs(people[i].second - stairs[1].second);
		}
		comb = 0;
		result = INT_MAX;
		min_time(0);
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;
}