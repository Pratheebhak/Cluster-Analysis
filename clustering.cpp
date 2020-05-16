/*
    File Name   : clustering.cpp
    Purpose     : Perform K-Means Clustering
*/

#include "clustering.h"
#include <iostream>

using namespace std;

Clustering::Clustering(vector<vector<double>> inputData, int clusters, int iter) :KMeans(inputData, clusters) {
    iterations = iter;
}

// Implement the clustering algorithm
void Clustering::implementation() {
    vector<vector<double>> c;
    c.clear();

    KMeans::assignCluster();
    KMeans::moveCentroid();
    c = KMeans::getNewCentroids();
    KMeans::setCentroids(c);
    printCentroid(c);
}

// Print the New Centroid at i-th iteration
void Clustering::printCentroid(vector<vector<double>> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec[0].size(); j++) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}


// Repeat the clustering implemetation for i iterations
void Clustering::evaluate() {
    int step = 0;
    while (step < iterations) {
        cout << "New Centroid at step " << step << endl;
        implementation();
        ++step;
    }
}
