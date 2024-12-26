#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int id;     // Activity ID (or number)
    int start;  // Start time of the activity
    int end;    // End time of the activity

    int duration() const {
        return end - start;
    }
};

bool compareByStart(Activity a, Activity b) {
    return a.start < b.start;
}

bool compareByDuration(Activity a, Activity b) {
    return a.duration() < b.duration();
}

vector<Activity> activitySelection(vector<Activity>& activities) {

    sort(activities.begin(), activities.end(), compareByStart);

    vector<Activity> selectedActivities;

    int lastEndTime = activities[0].start;

    for (int i = 0; i < activities.size(); ++i) {

        if (activities[i].start >= lastEndTime) {
            selectedActivities.push_back(activities[i]);
            lastEndTime = activities[i].end; // Update the end time
        }
    }

    // Sort the selected activities by their duration
    sort(selectedActivities.begin(), selectedActivities.end(), compareByDuration);

    return selectedActivities;
}

int main() {

    vector<Activity> activities = {
        {1, 5, 7},
        {2, 3, 4},
        {3, 0, 6},
        {4, 1, 2},
        {5, 5, 9},
        {6, 8, 10},
        {7, 9, 11},
        {8, 11, 12},
        {9, 13, 15},
        {10, 12, 13}
    };

    vector<Activity> selectedActivities = activitySelection(activities);

    cout << "Selected Activities (sorted by duration):\n";
    for (int i = 0; i < selectedActivities.size(); ++i) {
        const Activity& activity = selectedActivities[i];
        cout << "Activity " << activity.id << ": Start " << activity.start << ", End " << activity.end << ", Duration " << activity.duration() << endl;
    }

    return 0;
}
