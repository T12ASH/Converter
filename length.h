#include <stdexcept>
#include <cstring>
#include <iostream>

#ifndef LENGTH_H
#define LENGTH_H

class Length {
public:
    enum Type {
        km,  // kilometer
        m,   // meter
        cm,  // centimeter
        mm   // millimeter
    };

private:
    double _length{};
    Type _type{};

public:
    Length()
    {  }

    void set_type(Type type);
    void set_length(double length);

    double get_length() const;
    Type get_type() const;

    static Type define_uon(const char* str, bool& uon);
    void print();
};

#endif // LENGTH_H
