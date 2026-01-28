#include <iostream>
#include <iomanip> // For fixed and setprecision

using namespace std;

// 1. Pass by Reference (Array): Arrays are passed by reference/address by default in C++
int calculateSum(const int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum;
}

// 2. Pass by Value: sum and size are copies; changes here won't affect main()
double calculateAverage(int sum, int size) {
    return static_cast<double>(sum) / size;
}

// 3. Pass by Reference (Array): Modifies the original array scores
void addBonus(int scores[], int size, int bonus) {
    for (int i = 0; i < size; i++) {
        scores[i] += bonus;
    }
}

// 4. Pass by Pointer: Uses a pointer to access the array
int findMinimum(const int* scores, int size) {
    int min = *scores; // Start with the first element
    for (int i = 1; i < size; i++) {
        if (*(scores + i) < min) {
            min = *(scores + i);
        }
    }
    return min;
}

// 5. Pass by Reference : const ensures we don't accidentally change scores
int countHighPerformers(const int scores[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] >= 80) {
            count++;
        }
    }
    return count;
}

int main() {
    // Requirements: Hard-coded array
    const int SIZE = 10;
    int ary[SIZE] = {75, 88, 62, 95, 50, 82, 70, 91, 45, 78};

    
    cout << "Original scores: ";
    for (int i = 0; i < SIZE; i++) {
        cout << ary[i] << " ";
    }
    cout << endl;

    
    int totalSum = calculateSum(ary, SIZE);
    double avg = calculateAverage(totalSum, SIZE);
    
    cout << "Sum: " << totalSum << endl;
    cout << "Average: " << fixed << setprecision(2) << avg << endl;

    
    int bonusAmount = 10;
    addBonus(ary, SIZE, bonusAmount);
    cout << "Scores after +" << bonusAmount << " bonus: ";
    for (int i = 0; i < SIZE; i++) {
        cout << ary[i] << " ";
    }
    cout << endl;

    
    cout << "Minimum score: " << findMinimum(ary, SIZE) << endl;

    
    cout << "High performers (>=80): " << countHighPerformers(ary, SIZE) << endl;

    return 0;
}