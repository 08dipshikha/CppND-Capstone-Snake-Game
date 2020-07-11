#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  float speed;
  std::string userName;
  std::cout << "Enter the player name \n";
  std::cin >> userName;

  std::cout << "Enter the speed of the snake range 0.1 to 0.5 ? \n";
  std::cin >> speed;
  if(speed <= 0.1 || speed >= 0.5) 
  { 
    std::cout << "Speed range invalid. Moving snake at speed 0.1\n";
    speed = 0.1;
  }
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, userName.c_str());
  
  game.SetSpeed(speed);

  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Player name : " << game.GetPlayerName() << "\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  return 0;
}