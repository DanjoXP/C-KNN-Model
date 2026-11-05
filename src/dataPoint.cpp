#include <iostream>
#include "../headers/dataPoint.h"

#include <format>
#include <math.h>


DataPoint::DataPoint(std::string label,double x,double y)
{
    this->label=label;
    this->x=x;
    this->y=y;
}

std::string DataPoint::getLabel() { return this->label; }
double DataPoint::getX() { return this->x; }
double DataPoint::getY() { return this->y; }

// calculates Euclidean distance between two points
double DataPoint::euclindeanDistance(DataPoint other) {
    double xRes = std::pow(this->x - other.getX(),2);
    double yRes = std::pow(this->y - other.getY(),2);
    return std::sqrt(xRes + yRes);
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
