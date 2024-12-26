#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Item {
    int value;
    int weight;
    int index; // To keep track of the original index of the item
};

bool comparisonMax(Item a, Item b) {
    return (a.value > b.value);
}


bool comparisonMin(Item a, Item b) {
    return (a.value < b.value);
}

// Function to print the status of the knapsack after adding items
void printStatus(const vector<Item>& items, int capacity, double totalValue, int itemIndex, double weightTaken) {
    if (itemIndex >= 0) {
        double itemValue = items[itemIndex].value;
        double itemWeight = items[itemIndex].weight;

        cout << "Item selected: Item " << itemIndex + 1 << endl
             << " (Weight taken = " << weightTaken
             << " out of " << itemWeight
             << ", Value Added = " << weightTaken
             << " out of " << itemValue << ")" << endl;
    }
    cout << "Current capacity: " << capacity << endl;
    cout << "Total value: " << totalValue << endl;
    cout << endl;
}

// Function to calculate the knapsack profit based on the given sorting function
double fractionalKnapsack(int capacity, vector<Item>& items, bool (*compareFunc)(Item, Item), const string& method) {
    int n = items.size();
    double totalValue = 0.0;

    // Sort items based on the given comparison function
    sort(items.begin(), items.end(), compareFunc);

    cout << method << " Order:" << endl;

    // Iterate over the sorted items and add them to the knapsack
    for (int i = 0; i < n; ++i) {
        if (capacity == 0) {
            break;
        }

        // Determine the amount of the current item to take
        int weightToTake = min(items[i].weight, capacity);

        // Add the value to the total value
        totalValue += weightToTake * (double)items[i].value / items[i].weight;

        // Decrease the remaining capacity
        capacity -= weightToTake;

        // Print the status after processing the item
        printStatus(items, capacity, totalValue, items[i].index, weightToTake);
    }

    return totalValue;
}

int main() {
    srand(time(0)); // Seed for random number generation


    int n = 5;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        items[i].value = rand() % 100 + 1; // Random value between 1 and 100
        items[i].weight = rand() % 50 + 1; // Random weight between 1 and 50
        items[i].index = i; // Keep track of the original index
    }

    int capacity = 50;

    cout << "Given knapsack capacity: " << capacity << endl << endl;

    cout << "Initial Status of Items:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ": Value = " << items[i].value
             << ", Weight = " << items[i].weight << endl;
    }
    cout << endl;

    vector<Item> itemsForMax = items;
    double maxProfit = fractionalKnapsack(capacity, itemsForMax, comparisonMax, "Maximum Profit");

    cout << "Maximum profit = " << maxProfit << endl << endl;

    vector<Item> itemsForMin = items;
    double minProfit = fractionalKnapsack(capacity, itemsForMin, comparisonMin, "Minimum Profit");

    cout << "Minimum profit = " << minProfit << endl;

    return 0;
}

