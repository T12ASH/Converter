#include <iostream>
#include <cstdlib>

#include "length.h"
#include "temperature.h"
#include "weight.h"

enum class Types { Temperature, Weight, Length };

void print_usage();
void error_print(bool, bool);
bool define_Type(const char* type_str, Types* type);
template <typename T>
bool convert(double, const char*, const char*);


int main(int argc, const char** argv)
{
    if (argc != 5) {
        std::cout <<
            "Error: you need exactly 3 parameters! "
                  <<
            "Don't make mistake!"
                  <<
            std::endl;

        print_usage();
        return -1;
    }

    Types type{};

    if(!define_Type(argv[1], &type)) {
        std::cout <<
            "Error: Type is not defined! "
                  <<
            "Don't make mistake!"
                  <<
            std::endl;
        print_usage();
        return -2;
    }

    double value;
    try {
        value = std::stod(argv[2]);
    } catch (const std::exception&) {
        std::cout << "Error: value must be a number!" << std::endl;
        return -3;
    }

    bool result;

    switch(type) {
    case Types::Temperature:
        result = convert<Temperature>(value, argv[3], argv[4]);
        break;
    case Types::Weight:
        result = convert<Weight>(value, argv[3], argv[4]);
        break;
    case Types::Length:
        result = convert<Length>(value, argv[3], argv[4]);
        break;
    }

    if(result){
        std::cout <<
            "Succes!"
                  <<
            std::endl;
    } else {
        std::cout <<
            "Somthing bad!:("
                  <<
            std::endl;
        print_usage();
    }

    return 0;
}
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
template <typename T>
bool convert(double value, const char* from, const char* to) {
    bool ok1, ok2;
    auto type1 = T::define_uon(from, ok1);
    auto type2 = T::define_uon(to, ok2);
    error_print(ok1, ok2);
    if (!(ok1 && ok2)) return false;

    T unit;
    try {
        unit.set_type(type1);
        unit.set_value(value);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return false;
    }
    unit.print();
    std::cout << " -->convert to--> ";
    unit.set_type(type2);
    unit.print();
    std::cout << std::endl;
    return true;
}

bool define_Type(const char* type_str, Types* type) {
    if(strcmp(type_str,"temperature") == 0) {
        *type = Types::Temperature;
        return true;
    }
    if(strcmp(type_str,"weight") == 0) {
        *type = Types::Weight;
        return true;
    }
    if(strcmp(type_str,"length") == 0) {
        *type = Types::Length;
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


void print_usage() {
    std::cout <<
        "Usage: converter <type> <value> <from> <to>"
              <<
        std::endl;
    std::cout <<
        "  type: temperature | weight | length"
              <<
        std::endl;
    std::cout <<
        "  temperature units: C, F, K"
              <<
        std::endl;
    std::cout <<
        "  weight units: kg, lb, g, oz"
              <<
        std::endl;
    std::cout <<
        "  length units: km, m, cm, mm"
              <<
        std::endl;
    std::cout <<
        "Example: converter temperature 100 C F"
              <<
        std::endl;
}
void error_print(bool for_type1, bool for_type2) {
    if(!for_type1) {
        std::cout <<
            "Error: param1 is wrong"
                  <<
            std::endl;
    }
    if(!for_type2) {
        std::cout <<
            "Error: param2 is wrong"
                  <<
            std::endl;
    }
}