//
// Created by rivka on 06/03/2022.
//
#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;
ariel::Notebook notebook;

TEST_CASE("Wrong value write"){
    CHECK_THROWS(notebook.write(100, 100, 150, Direction::Horizontal, "abcd"));
    CHECK_THROWS(notebook.write(1, 1, 101, Direction::Horizontal, "abcd"));
    CHECK_THROWS(notebook.write(1, 1, 200, Direction::Horizontal, "abcd"));
    CHECK_THROWS(notebook.write(1, 98, 98, Direction::Horizontal, "abcd"));
    notebook.write(100, 100, 50, Direction::Horizontal, "abcd");
    CHECK_THROWS(notebook.write(100, 99,52, Direction::Vertical, "xyz"));

}

TEST_CASE("negative input write") {
    CHECK_THROWS(notebook.write(-1, 100, 50, Direction::Horizontal, "abcd"));
    CHECK_THROWS(notebook.write(100, -1, 20, Direction::Vertical, "abcd"));
    CHECK_THROWS(notebook.write(100, 100, -2, Direction::Horizontal, "abcd"));
}

TEST_CASE("good inputs write") {
    CHECK_NOTHROW(notebook.write(100, 100, 50, Direction::Horizontal, "abcd"));
    CHECK_NOTHROW(notebook.write(100, 5, 50, Direction::Horizontal, "kjh"));
    CHECK_NOTHROW(notebook.write(150, 100, 50, Direction::Vertical, "test"));
    CHECK_NOTHROW(notebook.write(160, 100, 50, Direction::Vertical, "abcd"));

}


TEST_CASE("Wrong value read"){
    CHECK_THROWS(notebook.read(100, 99, 150, Direction::Horizontal, 3));
    CHECK_THROWS(notebook.read(1, 1, 101, Direction::Vertical, 3));
    CHECK_THROWS(notebook.read(1, 1, 101, Direction::Vertical, 101));
    CHECK_THROWS(notebook.read(1, 1, 101, Direction::Vertical, 200));

}
TEST_CASE("negative input read") {
    CHECK_THROWS(notebook.read(-1, 100, 50, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.read(100, -1, 20, Direction::Vertical, 3));
    CHECK_THROWS(notebook.read(100, 100, -2, Direction::Horizontal, 4));
    CHECK_THROWS(notebook.read(100, 100, 2, Direction::Horizontal, -4));
}


TEST_CASE("negative input erase") {
    CHECK_THROWS(notebook.erase(-1, 100, 50, Direction::Horizontal, 5));
    CHECK_THROWS(notebook.erase(100, -1, 20, Direction::Vertical, 3));
    CHECK_THROWS(notebook.erase(100, 100, -2, Direction::Horizontal, 4));
    CHECK_THROWS(notebook.erase(100, 100, 2, Direction::Horizontal, -4););


}
TEST_CASE("good inputs erase") {
    CHECK_NOTHROW(notebook.erase(100, 100,50, Direction::Horizontal,3 ));
    CHECK_NOTHROW(notebook.erase(200, 5,59, Direction::Vertical,99 ));
    CHECK_NOTHROW(notebook.erase(200, 5,59, Direction::Vertical,99 ));


}
TEST_CASE("Wrong value erase"){
    CHECK_THROWS(notebook.erase(100, 99, 150, Direction::Horizontal, 3));
    CHECK_THROWS(notebook.erase(1, 1, 101, Direction::Vertical, 3));
    CHECK_THROWS(notebook.erase(1, 1, 101, Direction::Vertical, 101));
    CHECK_THROWS(notebook.erase(1, 1, 101, Direction::Vertical, 200));

}
TEST_CASE("good inputs read") {
    notebook.write(50, 100, 50, Direction::Horizontal, "abcd");
    CHECK(notebook.read(50, 99, 51, Direction::Vertical, 3)== " b ");
    CHECK(notebook.read(50, 100, 50, Direction::Horizontal, 3)== "abcd");

}


