/**
 * @author Igor Podtsepko i.podtsepko@outlook.com
 * */

#ifndef CACHE_OBLIVIOUS_ALGORITHM_TEST_MATRIX_H
#define CACHE_OBLIVIOUS_ALGORITHM_TEST_MATRIX_H
class matrix {
public:
    matrix(int size);
    ~matrix();

    void fillRandom(int seed);
    void fillRandom();

    int & operator()(int i, int j);

    int size();

    void putStupidTranspositionTo(matrix &dest);
    void putNaiveTranspositionTo(matrix &dest);
    void putCacheObliviousTranspositionTo(matrix &dest);

private:
    int n;
    int** data;

    void putCacheObliviousTranspositionTo(int x, int dx, int y, int dy, matrix &dest);
};
#endif //CACHE_OBLIVIOUS_ALGORITHM_TEST_MATRIX_H
