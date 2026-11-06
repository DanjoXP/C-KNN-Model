#include <iostream>
#include "../headers/dataPoint.h"

#include <format>
#include <math.h>


DataPoint::DataPoint(std::string label,std::vector<DataPoint> features)
{
    this->label=label;
    this->x=x;
    this->y=y;
}
DataPoint::DataPoint(std::vector<DataPoint> features)
{
    this->label= "unknown";
    this->x=x;
    this->y=y;
}


std::string DataPoint::getLabel() { return this->label; }
double DataPoint::getX() { return this->x; }
double DataPoint::getY() { return this->y; }

// calculates Euclidean distance between two points
double DataPoint::euclindeanDistance(DataPoint other) {
   double sum = 0.0;
    std::vector<double> otherFeatures = other.getFeatures();
    for (size_t i = 0; i < this->features.size(); i++) {
        sum += std::pow(this->features[i] - otherFeatures[i], 2);
    }
    return std::sqrt(sum);
}

std::string DataPoint::displayData() {
    return  std::format("label: {} coords:[{},{}]", this->label, this->x, this->y);
}

void DataPoint::addNeighbour(DataPoint dp) {
    this->neighbours.push_back(dp);
}
void DataPoint::addNeighbours(std::vector<DataPoint> dataPoints) {
    for (DataPoint dp : dataPoints) {
        this->neighbours.push_back(dp);
    }
}
std::vector<DataPoint> DataPoint::getNeighbours() {
    return this->neighbours;
}

void DataPoint::setLabel(std::string label) {this->label=label;}

double DataPoint::getFeatures() {

}
