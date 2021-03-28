#ifndef FLYINGBEHAVIORCOMPONENT_H
#define FLYINGBEHAVIORCOMPONENT_H

#include <iostream>
#include "Component.h"

//#include <functional>
//#include <utility>

/ ------------------------------------------------------------------------
//
//  Name:   Fly Behavior
//
//  Desc:  Fly compoment class example
//
//  Author: intermediate-cpp https://daveparillo.github.io/intermediate-cpp/class-III-design/patterns.html
//
//------------------------------------------------------------------------
class Object;

class FlyingBehaviorComponent :public Component
{
public:
    FlyingBehaviorComponent(Object* owner);
   /*/ template<FunctionObject F>
    explicit fly_behavior(F strategy)
        : strategy{ strategy }
    { }

    void fly() { strategy(); }*/
private:
    //TODO work on bheavior component


};

/*#define FunctionObject typename

// an alias to avoid copying std::function ... everywhere
using fly_strategy = std::function<void()>;

class fly_behavior {
public:

private:
    fly_strategy strategy;
};

// a function object that implements a strategy
struct soar
{
    void operator() () {
        std::cout << "fly by soaring.\n";
    }
};

// a free function can also implement a strategy
void no_flying_allowed() {
    std::cout << "I don't fly.\n";
}*/



#endif