//
// Created by Danny on 05/11/2026.
//

#ifndef KNN_DATAPOINT_H
#define KNN_DATAPOINT_H

#include <iostream>
#include <vector>

class DataPoint {
public:
    DataPoint(std::vector<DataPoint> features);
    DataPoint(std::string label,std::vector<DataPoint> features);
    std::string displayData();
    double euclindeanDistance(DataPoint other);
    double getX();
    double getY();
    std::string getLabel();
    void setLabel(std::string label);
    void addNeighbour(DataPoint dp);
    void addNeighbours(std::vector<DataPoint> dataPoints);
    std::vector<DataPoint> getNeighbours();
    std::vector<double> getFeatures();


private:
    double x;
    double y;
    std::string label;
    std::vector<DataPoint> neighbours;
    std::vector<double> features;
};

#endif //KNN_DATAPOINT_H
