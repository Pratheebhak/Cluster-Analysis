/*
    File Name   : clustering.h
    Purpose     : Perform K-Means Clustering 
*/

#ifndef CLUSTERING_H_
#define CLUSTERING_H_

#include "algorithm.h"
#include <cmath>

class Clustering : public Algorithm {
public:
    Clustering(vector<vector<double>>, int, int);
    void implementation();
    void printCentroid(vector<vector<double>> );
    void evaluate();
private:
    int iterations;

};

#endif 
