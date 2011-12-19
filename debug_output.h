#pragma once

#ifdef DEBUG_OUTPUT

#include <iostream>
#include <string>
#include <utility>

#define DEBUG(x) DebugOutput::run(std::cerr, __FILE__, __LINE__, #x, x)

struct DebugOutput {
    template <typename T>
    struct IsContainer
    {
        template<typename U>
        static char test(U* u, typename U::const_iterator b = ((U*)0)->begin(), typename U::const_iterator e = ((U*)0)->end());

        template<typename U>
        static int test(...);

        enum { value = (1 == sizeof test<T>(0)) };
    };

    template<typename T>
    struct IsCharacter {
        static char test(char* u);

        static char test(unsigned char* u);

        static int test(...);

        enum { value = (1 == sizeof test((T*)0)) };
    };

    template<typename T>
    static void print(std::ostream &out, const T &value, char(*)[!IsContainer<T>::value && !IsCharacter<T>::value] = 0) {
        out << value;
    }

    template<typename T>
    static void print(std::ostream &out, const T &value, char(*)[!IsContainer<T>::value && IsCharacter<T>::value] = 0) {
        out << "'" << value << "'";
    }

    template<typename T>
    static void print(std::ostream &out, const T &value, char(*)[IsContainer<T>::value] = 0) {
        out << "{";
        bool first = true;
        for (const auto &item : value) {
            if (first) {
                first = false;
            }
            else {
                out << ", ";
            }
            print(out, item);
        }
        out << "}";
    }

    static void print(std::ostream &out, const std::string &value) {
        out << "\"" << value << "\"";
    }

    static void print(std::ostream &out, const char * const value) {
        out << "\"" << value << "\"";
    }

    template<typename T1, typename T2>
    static void print(std::ostream &out, const std::pair<T1, T2> &value) {
        out << "(";
        print(out, value.first);
        out << ", ";
        print(out, value.second);
        out << ")";
    }

    template<typename T>
    static void run(std::ostream &out, const std::string &fileName, int lineNumber, const std::string &name, const T &value) {
        out << "file \"" << fileName << "\" line " << lineNumber << ": " << name << " = ";
        print(out, value);
        out << std::endl;
    }
};
#else
#define DEBUG(x) {}
#endif
