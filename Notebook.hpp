//
// Created by rivka on 20/03/2022.
//

#ifndef NOTEBOOK_A_NOTEBOOK_H
#define NOTEBOOK_A_NOTEBOOK_H
#include "Direction.hpp"
#include "string"
using namespace std;

namespace ariel {
    class Notebook {

    public:
    void write(int page,int row,int column, Direction direction,string const& str);
    static string read(int page,int row,int column, Direction direction,int length);
    void erase(int page,int row,int column, Direction direction,int length);
    void show(int page);
};
};


#endif //NOTEBOOK_A_NOTEBOOK_H
