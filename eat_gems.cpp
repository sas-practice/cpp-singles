#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

// There is an infinite grid of squares.  -> coods are ints, may be -ve
// Two players are at locations P1(xp1, yp1) and P2(xp2, yp2). -> initial
// Gems will appear at locations G1(xg1, yg1), G2(xg2, yg2)...Gn(xgn, ygn) in the same order.
// A new gem will appear only after the previous one is collected.
// A gem can be collected by either player by moving onto the square on which the gem is located.
// Players can move onto any of the surrounding 8 squares in unit time and only one player can move at a time.
// Find the minimum time required to collect all the gems by both the players combined.

using namespace std;

struct Cood {
    int x;
    int y;
};

int moves_count(Cood player, Cood gem) {
    return max(abs(player.x - gem.x), abs(player.y - gem.y));
}

int best_time_rec(Cood gems[], int total_gems, int current_gem, Cood p1, Cood p2) {
    if (current_gem == total_gems) return 0;

    int count_p1 =
            moves_count(p1, gems[current_gem]) +
            best_time_rec(gems, total_gems, current_gem + 1, gems[current_gem], p2);
    int count_p2 =
            moves_count(p2, gems[current_gem]) +
            best_time_rec(gems, total_gems, current_gem + 1, p1, gems[current_gem]);

    return min(count_p1, count_p2);
}

struct State {
    Cood p1;
    Cood p2;
    int gems_taken;
    int cost_so_far;

    bool operator<(const State &rhs) const {
        return cost_so_far > rhs.cost_so_far;
    }
};

int best_time_dijk(Cood gems[], int total_gems, Cood p1, Cood p2) {
    if (total_gems < 1) return 0;
    priority_queue<State> q;

    q.push({p1, gems[0], 1, moves_count(p2, gems[0])});
    q.push({gems[0], p2, 1, moves_count(p1, gems[0])});
    while (!q.empty()) {
        State current = q.top();
        q.pop();

        int gems_taken = current.gems_taken;
        int cost_so_far = current.cost_so_far;
        if (gems_taken == total_gems)
            return cost_so_far;

        Cood next_gem = gems[gems_taken];

        q.push({current.p1, next_gem, gems_taken + 1, cost_so_far + moves_count(current.p2, next_gem)});
        q.push({next_gem, current.p2, gems_taken + 1, cost_so_far + moves_count(current.p1, next_gem)});
    }
    return 0;
}

int main() {
    Cood p1{1, 1};
    Cood p2{3, 4};

    Cood gems[] = {
            {2, 2},
            {3, 2},
            {4, 2},
            {1, 1}
    };
    int total_gems = (sizeof(gems) / sizeof(*gems));
    int min_cost_dijk = best_time_dijk(gems, total_gems, p1, p2);
    cout << "MIN COST DIJK = " << min_cost_dijk << "\n";

    int min_cost_rec = best_time_rec(gems, total_gems, 0, p1, p2);
    cout << "MIN COST REC = " << min_cost_rec << "\n";
    return 0;
}