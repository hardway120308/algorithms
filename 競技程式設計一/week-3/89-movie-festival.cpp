#include <bits/stdc++.h>

using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<pair<int, int>> movies(N);
    for (int i = 0; i < N; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; // 按照結束時間排序
    });

    int count = 0;
    int last_end_time = 0;
    for (auto movie : movies) {
        // 開始時間大於等於上一部電影的結束時間，則可以觀看這部電影
        if (movie.first >= last_end_time) {
            count++;
            last_end_time = movie.second;
        }
    }
    cout << count << endl;
}