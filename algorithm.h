/*
    File Name   : algorithm.h
    Purpose     : Perform the steps in the K Means Clustering algorithm
*/

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "clusters.h"

class Algorithm : public Clusters {
public:
    Algorithm(vector<vector<double>>, int);
    vector<vector<double>> getData() const { return data; }
    vector<vector<double>> getNewCentroids() const { return newCentroid; }
    void assignCluster();
    void moveCentroid();
    void computeSum();
    

private:
    vector<vector<double>> data;
    vector<vector<double>> newCentroid;
    vector<vector<double>> sumCentroids;
    vector<int> pointsCentroid;
};

#endif
