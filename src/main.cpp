#include <iostream>
#include "../headers/dataPoint.h"
#include <vector>
#include "../headers/knn.h"

std::vector<DataPoint> generateClusteredData(int numberOfPoints) {
    std::vector<DataPoint> dataPoints;
    srand(time(0));

    for (int i = 0; i< numberOfPoints; i++) {
        if (i % 2 == 0 ) {
            double x = rand() % 41;
            double y = rand() % 41;
            dataPoints.push_back(DataPoint("red", x, y));
        } else {
            double x = 60 + (rand() % 41);
            double y = 60 + (rand() % 41);
            dataPoints.push_back(DataPoint("blue", x, y));
        }
    }

    return dataPoints;
}

int main() {
    std::vector<DataPoint> trainingPoints = generateClusteredData(100);
    KNN k(5);
    k.train(trainingPoints);

    DataPoint test1(20,25);
    DataPoint test2(80,75);
    DataPoint test3(50,50);

    k.predict(test1);
    std::cout << "Test 1 -> " << test1.displayData() << std::endl;
    k.predict(test2);
    std::cout << "Test 2 -> " << test2.displayData() << std::endl;
    k.predict(test3);
    std::cout << "Test 3 -> " << test2.displayData() << std::endl;
    
}