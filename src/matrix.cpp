#include <random>
#include <chrono>
#include "matrix.h"

/**
 * @author Igor Podtsepko i.podtsepko@outlook.com
 * */

matrix::matrix(int size) {
    this->n = size;
    this->data = new int*[size];
    for (int i = 0; i < size; i++) {
        data[i] = new int[size];
        for (int j = 0; j < size; j++) {
            data[i][j] = 0;
        }
    }
}

matrix::~matrix() {
    for (int i = 0; i < this->size(); i++) {
        delete [] this->data[i];
    }
    delete [] this->data;
}

void matrix::fillRandom(int seed) {
    srand(seed);
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            this->data[i][j] = rand();
        }
    }
}

void matrix::fillRandom() {
    fillRandom(time(NULL) % 12960000);
}

int & matrix::operator()(int i, int j) {
    return this->data[i][j];
}

int matrix::size() {
    return this->n;
}

void matrix::putStupidTranspositionTo(matrix &dest) {
    if (this->size() != dest.size()) {
        exit(1);
    }
    for (int diagonal = 0; diagonal < this->size() * 2 - 1; diagonal++) {
        int i = (int) fmax(0, (this->size() - 1) - diagonal);
        int j = (int) fmax(0, (1 - this->size()) + diagonal);
        while (i < this->size() && j < this->size()) {
            dest(i++, j++) = this->data[j][i];
        }
    }
}

void matrix::putNaiveTranspositionTo(matrix &dest) {
    if (this->size() != dest.size()) {
        exit(1);
    }
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->size(); j++) {
            dest(i, j) = this->data[j][i];
        }
    }
}

void matrix::putCacheObliviousTranspositionTo(int x, int dx, int y, int dy, matrix &dest) {
    int bound = 10;
    if (dx < bound && dy < bound) {
        for (int i = x; i < x + dx; i++) {
            for (int j = y; j < y + dy; j++) {
                dest(i, j) = this->data[j][i];
            }
        }
        return;
    }

    if (dy > dx) {
        int m = dy / 2;
        putCacheObliviousTranspositionTo(x, dx, y, m, dest);
        putCacheObliviousTranspositionTo(x, dx, y + m, dy - m, dest);
    } else {
        int m = dx / 2;
        putCacheObliviousTranspositionTo(x, m, y, dy, dest);
        putCacheObliviousTranspositionTo(x + m, dx - m, y, dy, dest);
    }
}

void matrix::putCacheObliviousTranspositionTo(matrix &dest) {
    if (this->size() != dest.size()) {
        exit(1);
    }
    putCacheObliviousTranspositionTo(0, this->size(), 0, this->size(), dest);
}