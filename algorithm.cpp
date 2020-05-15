/*
    File Name   : algorithm.cpp
    Purpose     : Perform the steps in the K Means Clustering algorithm
*/

#include "algorithm.h"

Algorithm::Algorithm(vector<vector<double>> inputData, int clusters) :Clusters(inputData, clusters) {
    data = inputData;
    //fill_n(pointsCentroid.begin(), Cluster::getClusters(), 0.0);
    

}


void Algorithm::assignCluster() {
    // Assign Cluster Id for each sample 
    for (size_t i = 0; i < data.size(); i++) {
        data[i][2] = Clusters::getClusterIndex(i);
    }
}

void Algorithm::moveCentroid() {
    computeSum();
    newCentroid.clear();
    vector<double> n;
    for (int p = 0; p < Clusters::getClusters(); p++) {
        // Calculate the modified new centroids 
        n.clear();
        n.push_back(sumCentroids[p][0] / pointsCentroid[p]);
        n.push_back(sumCentroids[p][1] / pointsCentroid[p]);
        n.push_back(p);
        newCentroid.push_back(n);

    }
}

// Calculate the total no. of points assigned to each cluster and sum of points
void Algorithm::computeSum() {
    vector<double> s{ 0.0,0.0 };
    for (int x = 0; x < Clusters::getClusters(); x++) {
        sumCentroids.push_back(s);
        pointsCentroid.push_back(0);
    }
    for (size_t i = 0; i < data.size(); i++) {
        for (int j = 0; j < Clusters::getClusters(); j++) {
            if (data[i][2] == j) {
                pointsCentroid[j] += 1;
                sumCentroids[j][0] += data[i][0];
                sumCentroids[j][1] += data[i][1];
            }
        }
    }
}



