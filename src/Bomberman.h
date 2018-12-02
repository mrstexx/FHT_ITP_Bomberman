#include <vector>
#include <algorithm>

#include ".\engine\IGameLogic.h"
#include "objects\GameItem.h"
#include ".\objects\battlefield\Battlefield.h"
#include ".\objects\player\Player.h"

class Bomberman : public IGameLogic{

    public:
        Bomberman();
        void init();
        void input();
        void update();
        void render(sf::RenderWindow* window);


    private:
        BattleField battlefield;
        Player player;
        std::vector<GameItem> backGroundItems;
        std::vector<sf::Texture> backGroundTextures;
        std::vector<GameItem> gameItems;
};
