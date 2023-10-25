#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

vector<vector<char>> bd(5, vector<char>(5));
set<string> ret;

const auto di = vi{ -1,1,0,0 };
const auto dj = vi{ 0,0,-1,1 };

auto ans = ""s;
void solve(int i, int j) {
	if (6 == ans.length()) {
		ret.insert(ans);

		return;
	}

	for (auto d = 0; d < 4; ++d) {
		const auto ni = i + di[d];
		const auto nj = j + dj[d];

		if (ni < 0 || 5 <= ni ||
			nj < 0 || 5 <= nj) {
			continue;
		}

		ans.push_back(bd[i][j]);
		solve(ni, nj);
		ans.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (auto&& r : bd) {
		for (auto&& x : r) {
			cin >> x;
		}
	}

	for (auto i = 0; i < 5; ++i) {
		for (auto j = 0; j < 5; ++j) {
			solve(i, j);
		}
	}

	cout << ret.size();

	return 0;
}