#include <bits/stdc++.h>
#include "matrix.h"

/**
 * @author Igor Podtsepko i.podtsepko@outlook.com
 * */

using namespace std;

#define TIME(action) \
double start = clock();\
action;\
double finish = clock();\
return (finish - start) / CLOCKS_PER_SEC;


double getTimeStupidTransposition(matrix &A, matrix &stupidTransposed) {
    TIME(A.putStupidTranspositionTo(stupidTransposed))
}


double getTimeNaiveTransposition(matrix &A, matrix &naiveTransposed) {
    TIME(A.putNaiveTranspositionTo(naiveTransposed))
}


double getTimeCacheObliviousTransposition(matrix &A, matrix &cacheObliviousTransposed) {
    TIME(A.putCacheObliviousTranspositionTo(cacheObliviousTransposed))
}


void test(
        bool log = false,
        int testCount = 1,
        int start = 1000,
        int stop = 10000,
        int step = 500,
        string outputFileName = "results.txt") {
    ofstream output(outputFileName);
    int nSizes = ((stop + 1) - start) / step;
    vector<double> stupidAverage(nSizes, 0);
    vector<double> naiveAverage(nSizes, 0);
    vector<double> cacheObliviousAverage(nSizes, 0);
    for (int iTest = 1; iTest < testCount + 1; iTest++) {
        cout << ">>> test " << iTest << '\n';
        if (log) {
            output << "Results for test " << iTest << ":\n";
        }
        for (int n = start; n < stop; n += step) {
            matrix A(n), stupidTransposed(n), naiveTransposed(n), cacheObliviousTransposed(n);
            A.fillRandom();

            int iSize = (n - start) / step;
            double stupidTime = getTimeStupidTransposition(A, stupidTransposed);
            double naiveTime = getTimeNaiveTransposition(A, naiveTransposed);
            double cacheObliviousTime = getTimeCacheObliviousTransposition(A, cacheObliviousTransposed);

            stupidAverage[iSize] += stupidTime;
            naiveAverage[iSize] += naiveTime;
            cacheObliviousAverage[iSize] += cacheObliviousTime;

            if (log) {
                output << n << '\t' << stupidTime << '\t' << naiveTime << '\t' << cacheObliviousTime << '\n';
            }
        }
        if (log) {
            output << '\n';
        }
    }
    output << "Average values\n";
    for (int i = 0; i < nSizes; i++) {
        output << start + i * step << '\t'
        << stupidAverage[i] / testCount << '\t'
        << naiveAverage[i] / testCount << '\t'
        << cacheObliviousAverage[i] / testCount << '\n';
    }
    output.close();
}


int main() {
    test(true, 5, 1000, 10000, 500);
    return 0;
}
