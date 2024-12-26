#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit of the job
};

// Comparator function to sort jobs based on profit
bool compare(Job a, Job b) {
    return a.profit > b.profit; // Sort in descending order of profit
}

// Function to perform job sequencing with deadlines
void jobSequencing(std::vector<Job>& jobs, int n) {
    // Sort jobs based on profit
    std::sort(jobs.begin(), jobs.end(), compare);

    // Result array to keep track of free time slots
    std::vector<int> result(n, -1);
    std::vector<bool> slot(n, false); // Track occupied slots


    // Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (from min(deadline, n) to 1)
        for (int j = std::min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            // If the slot is free, assign the job
            if (!slot[j]) {
                slot[j] = true; // Mark this slot as occupied
                result[j] = i;  // Store job index
                break;
            }
        }
    }

    std::cout << "Jobs selected: ";
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            std::cout << "(" << jobs[result[i]].id << ", " << jobs[result[i]].profit << ") ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    int n = jobs.size();
    jobSequencing(jobs, n);

    return 0;
}
