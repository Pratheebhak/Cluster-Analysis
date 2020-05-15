/*
    File Name   : clusters.h
    Purpose     : Define/Initialize the parameters pertaining to each cluster
*/

#ifndef CLUSTERS_H_
#define CLUSTERS_H_

#include <vector>

using namespace std;


class Clusters {
public:
    Clusters(vector<vector<double>>, int);
    int getClusters() const { return noOfClusters; }
    void setClusters(int c) { noOfClusters = c; }
    vector<vector<double>> getCentroids() const { return centroids; }  
    void setCentroids(vector<vector<double>> z) { centroids = z; }
    int getClusterIndex(int );
    int minIndex(vector<double>, int);


private:
    int noOfClusters;    
    vector<vector<double>> data;
    vector<vector<double>> centroids;
    vector<double> distances;
};

#endif
