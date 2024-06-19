#include <bits/stdc++.h>

using namespace std;

struct Player {
    string name;
    string time;

    bool operator<(const Player& other) const {
        if (time != other.time)
            return time > other.time; 
        return name > other.name;
    }
};

int main() {
    int J;
    cin >> J;

    vector<Player> players(J);

    for (int i = 0; i < J; ++i) {
        cin >> players[i].name >> players[i].time;
    }

    sort(players.begin(), players.end());

    for (int i = 0; i < J; ++i) {
        cout << i + 1 << ". " << players[i].time << " - " << players[i].name << endl;
    }

    return 0;
}
