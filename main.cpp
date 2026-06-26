#include <iostream>
#include <stdlib.h>

#include "length.h"
#include "temperature.h"
#include "weight.h"

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


enum Types {
    temperature,
    weight,
    length
};

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

bool convert(Types types, double value,
             const char* from, const char* to) {
    switch(types) {
        case temperature: {
            bool for_type1, for_type2;
            auto type1 = Temperature::define_uon(from, for_type1);
            auto type2 = Temperature::define_uon(to,   for_type2);
            error_print(for_type1, for_type2);
            if(!(for_type1 && for_type2)) { return false; }
            Temperature temperature;
            try {
                temperature.set_type(type1);
                temperature.set_temperature(value);
            } catch(const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
                return false;
            }
            temperature.print();

            std::cout << " -->convert to--> ";
            temperature.set_type(type2);
            temperature.print();
            std::cout << std::endl;
            return true;
        }
        case weight: {
            bool for_type1, for_type2;
            auto type1 = Weight::define_uon(from, for_type1);
            auto type2 = Weight::define_uon(to,   for_type2);
            error_print(for_type1, for_type2);
            if(!(for_type1 && for_type2)) { return false; }
            Weight weight;
            try {
                weight.set_type(type1);
                weight.set_weight(value);
            } catch(const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
                return false;
            }
            weight.print();

            std::cout << "-->convert to--> ";
            weight.set_type(type2);
            weight.print();
            std::cout << std::endl;
            return true;
        }
        case length: {
            bool for_type1, for_type2;
            auto type1 = Length::define_uon(from, for_type1);
            auto type2 = Length::define_uon(to,   for_type2);
            error_print(for_type1, for_type2);
            if(!(for_type1 && for_type2)) { return false; }
            Length length;
            try {
                length.set_type(type1);
                length.set_length(value);
            } catch(const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
                return false;
            }
            length.print();

            std::cout << "-->convert to--> ";
            length.set_type(type2);
            length.print();
            std::cout << std::endl;
            return true;
        }
    }
    return false;
}

bool define_Type(const char* type_str, Types* type) {
    if(strcmp(type_str,"temperature") == 0) {
        *type = temperature;
        return true;
    }
    if(strcmp(type_str,"weight") == 0) {
        *type = weight;
        return true;
    }
    if(strcmp(type_str,"length") == 0) {
        *type = length;
        return true;
    }
    return false;
}



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

    if(convert(type, atof(argv[2]), argv[3], argv[4])){
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
