#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Task {
    long long duration;
    long long deadline;
};

// 因爲獎勵=總和D-F=總和D-總和F，而總和D是常數
// 因爲f_1=a_1(a_1是某個任務)
// 而f_2=a_1+a_2
// 且f_3=a_1+a_2+a_3
// ...
// 所以f_n=n*a_1+(n-1)*a_2+(n-2)*a_3+...+a_n
// 我們必須minimize F_n，也就是使最小Duration的Task最先執行
int main() {
    int n;
    cin >> n;

    vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].duration >> tasks[i].deadline;
    }

    // Sort 如果回傳True則必須換位子
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) { return a.duration < b.duration; });

    long long current_time = 0;
    long long total_reward = 0;

    for (int i = 0; i < n; i++) {
        current_time += tasks[i].duration;
        total_reward += (tasks[i].deadline - current_time);
    }

    cout << total_reward << "\n";

    return 0;
}