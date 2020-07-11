#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "BaseController.h"
#include <memory>
class Controller : public BaseController
{
 public:
  void HandleInput(bool &&running, std::shared_ptr<Snake> &snake) const override;

 private:
  void ChangeDirection(std::shared_ptr<Snake> &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif