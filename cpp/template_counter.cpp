#include <string.h>
#include <iostream>
#include <memory>

template <typename T>
class Counter
{
    T* value;

    public: 
        Counter(T *value) : value(value) {}
        void reset(){ *value = 0; };
        void operator += (int increment){ *value += increment; };
        void operator ()(){ std::cout << "Value: " << *value << "\n"; };
};

template<>
class Counter<char>
{
    char* value;

    public: 
        Counter(char *value) : value(value) {}
        void reset() { *value = 'a'; };
        void operator += (int increment) {
            if (*value + increment > 'z')
            {
                *value = 'a' + (*value + increment - 'z' - 1);
            }else{
                *value += increment;
            }
        };
        void operator ()() { std::cout << "Value: " << *value << "\n"; };
};

int main(int argc, char const *argv[])
{
    char a = 'a';
    Counter<char> char_counter(&a);
    for (size_t i = 0; i < 30; i++)
    {
        char_counter();
        char_counter += i;
    }
    char_counter();
    
    return 0;
}
