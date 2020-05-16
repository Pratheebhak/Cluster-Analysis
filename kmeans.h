/*
    File Name   : kmeans.h
    Purpose     : Perform the steps in the K Means Clustering algorithm
*/

#ifndef KMEANS_H_
#define KMEANS_H_

#include "clusters.h"

class KMeans : public Clusters {
public:
    KMeans(vector<vector<double>>, int);
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
