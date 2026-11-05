#include <iostream>
#include "../headers/dataPoint.h"
#include <vector>
#include "../headers/knn.h"

std::vector<DataPoint> randomiseDataPoints(int numberOfPoints) {
    std::vector<DataPoint> randomDataPoints;
    srand(time(0));

    std::string labels[] = {"red","blue"};

    for (int i = 0; i < numberOfPoints; i++) {
        std::string label = labels[rand() % 2];
        double x = rand() % 101;
        double y = rand() % 101;
        DataPoint dataPoint(label, x, y);

        randomDataPoints.push_back(dataPoint);
    }

    return randomDataPoints;
}


int main() {
    std::vector<DataPoint> dataPoints = randomiseDataPoints(100);

    KNN k;
    k.train(dataPoints);
    
}