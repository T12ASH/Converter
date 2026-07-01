#include <stdexcept>
#include <cstring>
#include <iostream>

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature {
public:
    enum Type {
        C,  // Celsius
        F,  // Fahrenheit
        K   // Kelvin
    };

private:
    double _temperature{};
    Type _type{};

public:
    Temperature()
    {  }

    void set_type(Type type);
    void set_value(double temperature);

    double get_value() const;
    Type get_type() const;

    static Type define_uon(const char* str, bool& uon);
    void print();
};

#endif // TEMPERATURE_H