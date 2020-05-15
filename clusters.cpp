/*
    File Name   : clusters.cpp
    Purpose     : Define/Initialize the parameters pertaining to each cluster
*/

#include "clusters.h"
#include <cmath>


Clusters::Clusters(vector<vector<double>> indata, int k):data(indata), noOfClusters(k) {
    // Random Initialization of Cluster Centroids
    vector<double> cVal;
    for (int x = 0; x < noOfClusters; x++) {        
        int random = rand() % data.size();
        for (size_t y = 0; y < data.size(); y++) {
            if (y == random) {
                cVal.clear();
                cVal.push_back(data[y][0]);
                cVal.push_back(data[y][1]);
                cVal.push_back(x);
                centroids.push_back(cVal);
            }            
        }
        distances.push_back(0.0);
    }
}

// Compute the Euclidean Distance between each point and teh cluster ecntroids and assign the points
// to the nearest cluster centroid
int Clusters::getClusterIndex(int pos) {
    distances.clear();
    int dVal;
    for (int y = 0; y < noOfClusters; y++) {
              
        distances.push_back(sqrt(pow((data[pos][0] - centroids[y][0]) + (data[pos][1] - centroids[y][1]), 2)));   
    }
    dVal = minIndex(distances, noOfClusters);
    return dVal;
}

// Find the index with minimum element value
int Clusters::minIndex(vector<double> arr, int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < arr[index]) {
            index = i;
        }
    }
    return index;
}


