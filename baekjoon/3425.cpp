#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define MAX 1000000000

using namespace std;

int abs(int x) {
	return x > 0 ? x : -1 * x;
}

class GoStack {
public:
	void push(int x) {
		st.push(x);
	}

	bool pop() {
		if (st.empty()) return false;
		st.pop();
		return true;
	}

	bool inv() {
		if (st.empty()) return false;
		int x = st.top();
		st.pop();
		st.push(-1 * x);
		return true;
	}

	bool dup() {
		if (st.empty()) return false;
		int x = st.top();
		st.push(x);
		return true;
	}

	bool swp() {
		if (st.size() < 2) return false;
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();

		st.push(x);
		st.push(y);
		return true;
	}

	bool add() {
		if (st.size() < 2) return false;
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();

		if ((x > 0 && y > 0) || (x < 0 && y < 0)) {
			if (abs(x) > MAX - abs(y)) {
				//cout << "here\n";
				return false;
			}
		}
		st.push(x + y);
		return true;
	}

	bool sub() {
		if (st.size() < 2) return false;
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();

		if ((x > 0 && y < 0) || (x < 0 && y > 0)) {
			if (abs(x) > MAX - abs(y)) {
				return false;
			}
		}
		st.push(y - x);
		return true;
	}
	
	bool mul() {
		if (st.size() < 2) return false;
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();
		
		if (y != 0 && abs(x) > MAX / abs(y)) {
			return false;
		}
		st.push(x * y);
		return true;
	}

	bool div() {
		if (st.size() < 2) return false;
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();

		if (x == 0) return false;
		int ret = abs(y) / abs(x);
		if ((x > 0 && y > 0) || x < 0 && y < 0) st.push(ret);
		else st.push(-1 * ret);
		return true;
	}

	bool mod() {
		if (st.size() < 2) return false;
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();

		if (x == 0) return false;
		int ret = abs(y) % abs(x);
		if (y > 0) st.push(ret);
		else st.push(-1 * ret);
		return true;
	}

	void init() {
		program.clear();
		while (!st.empty()) st.pop();
	}

	int exec(int v) {
		int x;

		while (!st.empty()) st.pop();
		st.push(v);
		for (string& cmd : program) {
			//cout << cmd << endl;
			if (cmd == "POP") {
				if(!pop()) return MAX + 1;
			}
			else if (cmd == "INV") {
				if (!inv()) return MAX + 1;
			}
			else if (cmd == "DUP") {
				if (!dup()) return MAX + 1;

			}
			else if (cmd == "SWP") {
				if (!swp()) return MAX + 1;

			}
			else if (cmd == "ADD") {
				if (!add()) return MAX + 1;
			}
			else if (cmd == "SUB") {
				if (!sub()) return MAX + 1;
			}
			else if (cmd == "MUL") {
				if (!mul()) return MAX + 1;

			}
			else if (cmd == "DIV") {
				if (!div()) return MAX + 1;

			}
			else if (cmd == "MOD") {
				if (!mod()) return MAX + 1;

			}
			else { // NUM x
				x = stoi(cmd.substr(4));
				push(x);
			}
		}

		if (st.size() == 1) return st.top();
		else return MAX + 1;
	}
	void add_cmd(string str) {
		program.emplace_back(str);
	}
private:
	vector<string> program;
	stack<int> st;
};

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string cmd;
	int n, x;
	GoStack gs;

	while (true) {
		getline(cin, cmd);
		//continue;
		if (cmd == "END") {
			//cout << "here\n";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> x;
				int ret = gs.exec(x);
				if (ret > MAX) cout << "ERROR\n";
				else cout << ret << '\n';
			}
			gs.init();
			cout << '\n';
			//cin >> cmd;
		}
		else if (cmd == "QUIT") break;
		else if (cmd == "") continue;
		else {
			//cout << "add_cmd(" << cmd << ")\n";
			gs.add_cmd(cmd);
		}
	}


	return 0;
}