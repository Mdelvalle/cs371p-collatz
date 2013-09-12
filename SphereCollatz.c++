// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------------

/*
To run the program:
% g++ -pedantic -std=c++0x -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz
% valgrind RunCollatz < RunCollatz.in > RunCollatz.out

To configure Doxygen:
% doxygen -g
That creates the file "Doxyfile".
Make the following edits:
EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
GENERATE_LATEX = NO

To document the program:
% doxygen Doxyfile
*/

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout
#include <cassert> // assert

// ------------
// collatz_read
// ------------

/**
* reads two ints into i and j
* @param r a std::istream
* @param i an int by reference
* @param j an int by reference
* @return true if that succeeds, false otherwise
*/
bool collatz_read (std::istream&, int&, int&);

// ------------
// collatz_eval
// ------------

/**
* @param i the beginning of the range, inclusive
* @param j the end of the range, inclusive
* @return the max cycle length in the range [i, j]
*/
int collatz_eval (int, int);

// -------------
// collatz_print
// -------------

/**
* prints the values of i, j, and v
* @param w a std::ostream
* @param i the beginning of the range, inclusive
* @param j the end of the range, inclusive
* @param v the max cycle length
*/
void collatz_print (std::ostream&, int, int, int);

// -------------
// collatz_solve
// -------------

/**
* read, eval, print loop
* @param r a std::istream
* @param w a std::ostream
*/
void collatz_solve (std::istream&, std::ostream&);


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
int cache[1000000] = {0};
int collatz_eval (int i, int j) {
    // <your code>
    int max = 0;
    int c, n, temp;
    bool hit;

    assert(i > 0);
    assert(j > 0);

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


// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}


