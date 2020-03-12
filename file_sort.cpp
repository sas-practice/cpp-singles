#include <iostream>
#include <fstream>

using namespace std;

const int N = 256;

void count_chars(ifstream &fin, int *counts) {
    int ch;
    while ((ch = fin.get()) > 0) {
        ++counts[ch];
    }
}

void write_chars(ofstream &fout, const int *counts) {
    for (int i = 0; i < N; ++i) {
        int count = counts[i];

        while (count > 0) {
            fout.put(i);
            --count;
        }
    }
}

int main() {
    ifstream fin("/Users/sasdutta/code/mine/cpp-singles/in.txt");
    if (fin.is_open()) {
        int counts[N] = {0};
        count_chars(fin, counts);
        fin.close();

        ofstream fout("/Users/sasdutta/code/mine/cpp-singles/out.txt");
        if (fout.is_open()) {
            write_chars(fout, counts);
            fout.close();
        } else cerr << "Unable to open output file";
    } else cerr << "Unable to open input file";
}
