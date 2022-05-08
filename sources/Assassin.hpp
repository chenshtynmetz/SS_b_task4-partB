#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#define SUM_ASS_COUP 3

namespace coup{
    class Assassin : public Player{
        private:

        public:
            Assassin(Game& g, std::string str);
            void coup(Player &p);
    };
}