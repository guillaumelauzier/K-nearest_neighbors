#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

// Define a data point with two features (x and y) and a label
struct DataPoint {
    float x;
    float y;
    int label;
};

// Calculate the Euclidean distance between two data points
float euclideanDistance(DataPoint a, DataPoint b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    // Create a vector of training data points
    std::vector<DataPoint> trainingData = {{1, 2, 0}, {3, 4, 0}, {5, 6, 1}, {7, 8, 1}};

    // Set the number of nearest neighbors (K)
    int k = 3;

    // Define the input data point
    DataPoint input = {2, 3};

    // Calculate the distances between the input point and the training data points
    std::vector<std::pair<float, int>> distances(trainingData.size());
    for (int i = 0; i < trainingData.size(); i++) {
        float distance = euclideanDistance(input, trainingData[i]);
        distances[i] = std::make_pair(distance, trainingData[i].label);
    }

    // Sort the distances in ascending order
    std::sort(distances.begin(), distances.end());

    // Count the number of occurrences of each label among the K nearest neighbors
    std::vector<int> counts(2, 0);
    for (int i = 0; i < k; i++) {
        counts[distances[i].second]++;
    }

    // Predict the label for the input point as the label with the most occurrences among the K nearest neighbors
    int predictedLabel = (counts[0] > counts[1]) ? 0 : 1;

    std::cout << "Predicted label for input point: " << predictedLabel << std::endl;

    return 0;
}
