#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[19][50][2][2];  // dp[pos][k][under][started]
string num;

/** Reset the dp array to its initial values. */
void reset() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) { dp[i][j][k][l] = -1; }
			}
		}
	}
}

/**
 * Calculate the number of sequences whose digits consist of at least half targ.
 * If targ2 is not -1, then calculate the number of sequences whose digits are
 * exactly half targ and half targ2.
 * @param pos the starting position
 * @param k counter for the number of the target digit targ
 * @param under if the current sequence is smaller than the given upperbound
 * @param started if the sequence has any digit other than leading zeros
 */
ll solve_dp(int pos, int k, bool under, bool started, int targ, int targ2) {
	// base case: the sequence has reached the maximal length
	if (pos == num.size()) {
		// edge case: the sequence only contains zeros, i.e. did not start
		if (!started) { return 0; }

		/*
		 * If we are interested in finding out whether the sequence contains
		 * exactly half digits of targ and half digits of targ2.
		 */
		if (targ2 != -1) {
			if (k == 20) {
				return 1;
			} else {
				return 0;
			}
		}
		/*
		 * Otherwise, the sequence is interesting if at least half of the digits
		 * are our target number targ.
		 */
		if (k >= 20) {
			return 1;
		} else {
			return 0;
		}
	}

	if (dp[pos][k][under][started] != -1) { return dp[pos][k][under][started]; }

	ll ans = 0;
	for (int i = 0; i <= 9; i++) {
		int digit_diff = num[pos] - '0';
		/*
		 * If the sequence will be larger than the upperbound, then we can
		 * terminate
		 */
		if (!under && i > digit_diff) { break; }

		/*
		 * If the new digit is smaller than the one in the upperbound, then any
		 * child sequence can't be larger than than upperbound as this digit is
		 * more significant than any following one
		 */
		bool is_under = under;
		if (i < digit_diff) { is_under = true; }

		// the sequence has started if any digits until pos is other than 0
		bool is_started = started || i != 0;

		/*
		 * If we want to count how many sequences have exactly half digits of
		 * targ and half of targ2, then any other number than targ or targ2
		 * doesn't matter
		 */
		if (is_started && targ2 != -1 && i != targ && i != targ2) { continue; }

		/*
		 * The count for target digit targ is increased by one if i is targ, or
		 * decreased by one otherwise.
		 */
		int new_k = k;
		if (is_started) {
			if (targ == i) {
				new_k = k + 1;
			} else {
				new_k = k - 1;
			}
		}
		ans += solve_dp(pos + 1, new_k, is_under, is_started, targ, targ2);
	}
	return dp[pos][k][under][started] = ans;
}

/** Count interesting sequences that are less or equal ubound */
ll count_interesting_to(ll ubound) {
	num = to_string(ubound);
	ll ans = 0;
	for (int i = 0; i <= 9; i++) {
		reset();
		ans += solve_dp(0, 20, false, false, i, -1);
	}

	/*
	 * If a sequence's digits consist of exactly half i and half j, then it will
	 * be counted twice. We have to subtract duplicates to avoid overcount.
	 */
	ll duplicates = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			reset();
			duplicates += solve_dp(0, 20, false, false, i, j);
		}
	}
	return ans - (duplicates / 2);
}

int main() {
	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);

	ll X, Y;
	cin >> X >> Y;
	cout << count_interesting_to(Y) - count_interesting_to(X - 1) << endl;
}
