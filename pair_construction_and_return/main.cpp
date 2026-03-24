#include <iostream>
#include <functional>


//my style -------->>>>///

std::tuple<int,int> cons(int a, int b){
    std::tuple<int,int> pair;
    
    pair = {a,b};
    
    
    return pair;
};


int car(std::tuple<int,int> couple){
    return std::get<0>(couple);
}

int cdr(std::tuple<int,int> couple){
    return std::get<1>(couple);
}

/// functional style ////
// cons returns a function
auto fcons(int a, int b)
{
    return [=](std::function<int(int, int)> f)
    {
        return f(a, b);
    };
}

int fcar(std::function<int(std::function<int(int, int)>)> pair)
{
    return pair([](int a, int b)
                { return a; });
}

int fcdr(std::function<int(std::function<int(int, int)>)> pair)
{
    return pair([](int a, int b)
                { return b; });
}

int main(){


    std::cout <<" car: " << car(cons(3,4));
    std::cout <<" cdr: " << cdr(cons(3,4))<<"\n";

    auto p = fcons(3, 4);

    std::cout << " fcar: " << fcar(p);
    std::cout << " fcdr: " << fcdr(p) << "\n";

    return 0;
}