#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <vector>

using namespace std;

auto execut(const vector<int>& arr) {
    double sum = 0;
    int n = 0;
    vector<double> result(arr.size());

    auto start = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        n += 1;
        result[i] = sum / n;
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    return duration.count();
}

void Generate(int num) {
    ofstream outFile("pair.csv", ios::out); // Open file once, in append mode
    if (!outFile.is_open()) {
        cerr << "Failed to open file for writing" << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 10000);

    int b = 100000;
    for (int i = 0; i < num; ++i) {
        vector<int> arr(b);
        for (int j = 0; j < b; ++j) {
            arr[j] = dis(gen);
        }

        long long int time = execut(arr);
        outFile << time << "," << b << endl;
        b += 1000;
        cout<<"time:"<<time<<" "<<"size:"<<b<<endl;
    }

    outFile.close();
}

int main() {
    // Generate and store results
    Generate(800); // Create 5 different arrays with increasing sizes

    return 0;
}
