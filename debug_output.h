#pragma once

#ifdef DEBUG_OUTPUT

#include <iostream>
#include <string>
#include <utility>
#include <tuple>

#define DEBUG(x,...) DebugOutput::run(std::cerr, __FILE__, __LINE__, #x, x, std::make_tuple(__VA_ARGS__))

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

    template <typename T>
    static void print(std::ostream &out, T* array, std::tuple<int> tuple){
    	out << "{";
    	int count = std::get<0>(tuple);
    	for(int i = 0; i < count; ++i){
    		if(i>0)
    			out<<", ";
    		print(out, array[i]);
    	}
    	out << "}";
    }

    template <typename T, typename U>
    static void print(std::ostream &out, T&, U&){
    	out<<"No matching function to print";
    }

    template<typename T, typename U>
    static void run(std::ostream &out, const std::string &fileName, int lineNumber, const std::string &name, const T &value, const U& args) {
        out << "file \"" << fileName << "\" line " << lineNumber << ": " << name << " = ";
        if(std::tuple_size<U>::value == 0)
        	print(out, value);
        else
        	print(out, value, args);
        out << std::endl;
    }
};
#else
#define DEBUG(args...) {}
#endif
