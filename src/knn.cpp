#include "../headers/knn.h"
#include <algorithm>
#include <map>

KNN::KNN() {
    this->neighbours = 5;
}
KNN::KNN(int neighbours) {
    this->neighbours = neighbours;
}

void KNN::setNeighbours(int neighbours) {
    this->neighbours = neighbours;
}

void KNN::train(std::vector<DataPoint>& dataPoints) {
    this->trainingData = dataPoints;
}

std::string KNN::predict(DataPoint &queryPoint) {
    std::vector<DataPoint> nearest = getKNeighbours(queryPoint,this->trainingData);
    queryPoint.addNeighbours(nearest);
    classifyDataPoint(&queryPoint);
    return queryPoint.getLabel();
}

std::vector<DataPoint> KNN::getKNeighbours(DataPoint current,std::vector<DataPoint> dataPoints) {
        std::sort(
            dataPoints.begin(),
            dataPoints.end(),
            [&current](DataPoint a, DataPoint b) {
                return current.euclindeanDistance(a) < current.euclindeanDistance(b);
            }
        );
        int k = std::min(this->neighbours, (int)dataPoints.size());
        return std::vector<DataPoint>(dataPoints.begin(),dataPoints.begin() + k);
}

void KNN::propagateNeighbours(std::vector<DataPoint>& dataPoints) {
    int size = dataPoints.size();
    for (int i = 0; i < size; i++) {
        DataPoint* currentPtr = &dataPoints.at(i);
        std::vector<DataPoint> nearestNeighbours;
        for (int j = 0; j < size; j++) {
            if (i == j) {continue;}
            nearestNeighbours.push_back(dataPoints.at(j));
        }
        nearestNeighbours = getKNeighbours(*currentPtr,nearestNeighbours);
        currentPtr->addNeighbours(nearestNeighbours);
    }
}

void KNN::classifyDataPoint(DataPoint *dp) {

    std::map<std::string, int> counts;

    for (DataPoint d : dp->getNeighbours()) {
        counts[d.getLabel()]++;
    }

    std::string mostCommonLabel = dp->getLabel();
    int highestCount = 0;

    for (const auto& [label, count] : counts) {
        std::cout << "Label: " << label
                  << " | Count: " << count << std::endl;

        if (count > highestCount) {
            highestCount = count;
            mostCommonLabel = label;
        }
    }

    dp->setLabel(mostCommonLabel);
}