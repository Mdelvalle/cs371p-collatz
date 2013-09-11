// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    int max = 0;
    int c, n, temp;
    int cache[1000000] = {0};
    bool hit;

    if (i > j) {
        temp = i;
        i = j;
        j = temp;}
        
    for (i; i <= j; i++) {
        n = i;
        c = 1;

        if (cache[i] == 0)
            hit = false;
        else
            hit = true;

        if (!hit) {
            while (n > 1) {
                if ((n % 2) == 0)
                    n = n / 2;
                else {
                    n = n + (n >> 1) + 1;
                    c++;}
                c++;}

            cache[i] = c;
            if (c > max)
                max = c;}
        else {
            if (cache[i] > max)
                max = cache[i];
            hit = false;}}

    assert(max > 0);
    return max;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
