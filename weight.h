#include <stdexcept>
#include <cstring>
#include <iostream>

#ifndef WEIGHT_H
#define WEIGHT_H

class Weight {
public:
    enum Type {
        kg,  // kilogram
        lb,  // pound
        g,   // gram
        oz   // ounce
    };

private:
    double _weight{};
    Type _type{};

public:
    Weight()
    {  }

    void set_type(Type type);
    void set_value(double weight);

    double get_value() const;
    Type get_type() const;

    static Type define_uon(const char* str, bool& uon);
    void print();
};

#endif // WEIGHT_H