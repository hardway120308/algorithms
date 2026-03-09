#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int winners[n];
    long long p_scores[m];

    memset(winners, 0, sizeof(winners));

    for (int i = 0; i < m; i++) {
        cin >> p_scores[i];
    }

    for (int i = 0; i < n; i++) {
        int ki;
        long long best_score = -1;
        cin >> ki;
        for (int j = 0; j < ki; j++) {
            int applicant;
            cin >> applicant;
            // index = applicant -1
            if (p_scores[applicant - 1] > best_score or
                (p_scores[applicant - 1] == best_score and applicant < winners[i])) {
                best_score = p_scores[applicant - 1];
                winners[i] = applicant;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << winners[i] << endl;
    }
}
