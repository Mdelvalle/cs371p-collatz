// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

    % g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lpthread -lgtest_main

    % valgrind TestCollatz > TestCollatz.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "Collatz.h"

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(Collatz, read) {
    std::istringstream r("1 10\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b == true);
    ASSERT_TRUE(i ==    1);
    ASSERT_TRUE(j ==   10);}

TEST(Collatz, read_1) {
    std::istringstream r("42 100\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b == true);
    ASSERT_TRUE(i ==    42);
    ASSERT_TRUE(j ==   100);}

TEST(Collatz, read_2) {
    std::istringstream r("33 52\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b == true);
    ASSERT_TRUE(i ==    33);
    ASSERT_TRUE(j ==   52);}

TEST(Collatz, read_3) {
    std::istringstream r("69 89\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b == true);
    ASSERT_TRUE(i ==    69);
    ASSERT_TRUE(j ==   89);}

// ----
// eval
// ----

TEST(Collatz, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_TRUE(v == 20);}

TEST(Collatz, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_TRUE(v == 125);}

TEST(Collatz, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_TRUE(v == 89);}

TEST(Collatz, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_TRUE(v == 174);}

TEST(Collatz, eval_5) {
    const int v = collatz_eval(54485, 98054);
    ASSERT_TRUE(v == 351);}

TEST(Collatz, eval_6) {
    const int v = collatz_eval(887357, 652959);
    ASSERT_TRUE(v == 525);}

TEST(Collatz, eval_7) {
    const int v = collatz_eval(697904, 774848);
    ASSERT_TRUE(v == 468);}

// -----
// print
// -----

TEST(Collatz, print) {
    std::ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == "1 10 20\n");}

TEST(Collatz, print_1) {
    std::ostringstream w;
    collatz_print(w, 75395, 884769, 525);
    ASSERT_TRUE(w.str() == "75395 884769 525\n");}

TEST(Collatz, print_2) {
    std::ostringstream w;
    collatz_print(w, 70390, 108641, 354);
    ASSERT_TRUE(w.str() == "70390 108641 354\n");}

TEST(Collatz, print_3) {
    std::ostringstream w;
    collatz_print(w, 610185, 788565, 468);
    ASSERT_TRUE(w.str() == "610185 788565 468\n");}


// -----
// solve
// -----

TEST(Collatz, solve) {
    std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    std::ostringstream w;
    collatz_solve(r, w);
    ASSERT_TRUE(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

TEST(Collatz, solve_1) {
    std::istringstream r("75395 884769\n70390 108641\n610185 788565\n");
    std::ostringstream w;
    collatz_solve(r, w);
    ASSERT_TRUE(w.str() == "75395 884769 525\n70390 108641 354\n610185 788565 468\n");}

TEST(Collatz, solve_2) {
    std::istringstream r("54485 98054\n887357 652959\n697904 774848\n");
    std::ostringstream w;
    collatz_solve(r, w);
    ASSERT_TRUE(w.str() == "54485 98054 351\n887357 652959 525\n697904 774848 468\n");}

TEST(Collatz, solve_3) {
    std::istringstream r("694659 260940\n990807 536166\n31750 452495\n");
    std::ostringstream w;
    collatz_solve(r, w);
    ASSERT_TRUE(w.str() == "694659 260940 470\n990807 536166 525\n31750 452495 449\n");}
