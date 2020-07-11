#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include "snake.h"
#include <memory>

class BaseController
{
    public:
        virtual void HandleInput(bool &&running, std::shared_ptr<Snake> &snake) const = 0;
};


#endif