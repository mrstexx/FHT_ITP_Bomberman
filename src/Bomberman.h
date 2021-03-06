#include <vector>
#include <algorithm>

#include ".\engine\IGameLogic.h"
#include "objects\GameItem.h"
#include ".\objects\battlefield\Battlefield.h"
#include ".\objects\player\Player.h"
#include ".\objects\menu\dialog\Dialog.h"

class Bomberman : public IGameLogic
{

public:
  Bomberman(int numberOfPlayers);
  void init();
  void input();
  void update();
  void render(sf::RenderWindow *window);

private:
  int numberOfPlayers;
  BattleField *battlefield;
  Player player;
  Dialog *popupEndGame;
  std::vector<GameItem> backGroundItems;
  std::vector<sf::Texture> backGroundTextures;
  std::vector<GameItem> gameItems;
};
