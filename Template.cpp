#include <bits/stdc++.h>

using namespace std;

string run() {

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = run();

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
