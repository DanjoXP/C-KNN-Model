//
// Created by Danny on 05/11/2026.
//

#ifndef KNN_KNN_H
#define KNN_KNN_H
#include <vector>

#include "dataPoint.h"

class KNN {
public:
    KNN();
    KNN(int neighbors);
    void setNeighbours(int neighbors);
    void train(std::vector<DataPoint> &dataPoints);
    std::string predict(DataPoint &queryPoint);

private:
    int neighbours;
    std::vector<DataPoint> trainingData;
    void propagateNeighbours(std::vector<DataPoint>& dataPoints);
    std::vector<DataPoint> getKNeighbours(DataPoint point, std::vector<DataPoint> dataPoints);
    void classifyDataPoint(DataPoint *dp);
};

#endif //KNN_KNN_H
