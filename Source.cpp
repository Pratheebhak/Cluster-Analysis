/*
    File Name   : Source.cpp
    Purpose     : Cluster Analysis for Unsupervised Machine Learning Problems
*/

/* 
    Project Description: Cluster Analysis for Unsupervised Machine Learning 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

#include "clusters.h"
#include "kmeans.h"
#include "clustering.h"


#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

using namespace std;

// Function to convert input csv file into a 2D vector
vector<vector<double>> csvToVector(fstream& inputFile) {
    if (inputFile.is_open()) {
        cout << "The input file is loaded successfully " << endl;
    }
    else {
        cout << " Can't load the input file. Place the file to be loaded in the same directory as the source file" << endl;
    }
    // Create a vector of vectors(2D array) to store the contents of the csv file
    vector<vector<double>> arr;
    vector<double> rows;

    // Read string from the file
    string data, value;

    // Store each line in the csv file into a 2D array
    while (getline(inputFile, data)) {
        rows.clear();
        stringstream ss(data);

        while (getline(ss, value, ',')) {
            rows.push_back(stof(value));
        }
        rows.push_back(-1);
        arr.push_back(rows);
    }
    random_shuffle(arr.begin(), arr.end());
    return arr;
}

// Function to print the contents of a vector
void printVector(vector<vector<double>> vec) {
    for (size_t i = 0; i < vec.size() ; i++) {
        for (size_t j = 0; j < vec[0].size(); j++) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}

// Funtion to write the vector to an output csv file
void vectorToCSV(vector<vector<double>> samplePoints) {
    ofstream out;
    out.open("output.csv");
    out << "x,y,c" << endl;
    for (size_t z = 0; z < samplePoints.size(); z++) {
        out << samplePoints[z][0] << "," << samplePoints[z][1] << "," << samplePoints[z][2] << endl;
    }
    out.close();
}

// Function to plot the scatter plot of the result
void scatterPlot(vector<vector<double>> data, int k) {
    vector<double> x1, y1, x2, y2, x3, y3;
    vector<double> x, y;
    vector<double> c;


    for (size_t i = 0; i < data.size(); i++) {
        x.push_back(data[i][0]);
        y.push_back(data[i][1]);
        c.push_back(data[i][2]);
    }

    plt::figure(1);
    plt::plot(x, y, "k*");
    plt::title("Before Clustering");
    plt::show();
    plt::save("./data.png");


    for (size_t j = 0; j < data.size(); j++) {        
        if (c[j] == 0) {
                x1.push_back(data[j][0]);
                y1.push_back(data[j][1]);
        }
        else if (c[j] == 1) {
                x2.push_back(data[j][0]);
                y2.push_back(data[j][1]);
        }
        else {
                x3.push_back(data[j][0]);
                y3.push_back(data[j][1]);
        }
    }

    plt::figure(2);
    plt::plot(x1, y1, "r*");
    plt::plot(x2, y2, "g*");
    plt::plot(x3, y3, "b*");
    plt::title("After Clustering");
    plt::show();
    plt::save("./clusters.png");
    
}

int main() {

    vector<vector<double>> dataArray;

    // Load input data file and convert it into a vector for computation purposes
    fstream file("data.csv"); 
    cout << "Loading Input Data File" << endl;
    dataArray = csvToVector(file);
    
    // Perform Clustering for 10 iterations and 3 clusters
    Clustering c(dataArray, 3, 10);
    c.evaluate();
    dataArray = c.getData();
    
    // Print the data points and the assigned cluster Id
    //cout << "Cluster Assignments" << endl;
    //printVector(dataArray);

    vectorToCSV(dataArray);

    // Plot the output clusters
    scatterPlot(dataArray, 3);    
    

    return 0;
}