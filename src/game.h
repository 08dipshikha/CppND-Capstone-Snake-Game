#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <memory>
#include <string.h>
class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, const char* userName);
  ~Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  std::string GetPlayerName() const;
  void SetSpeed(float &speed);
 private:

  std::shared_ptr<Snake> snake;
  //Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  float speed_;
  void PlaceFood();
  void Update();
  char* playerName;
  std::size_t grid_width, grid_height;
};

#endif