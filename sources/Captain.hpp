#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Captain : public Player{
        private:

        public:
            Captain(Game& g, std::string str);
            void steal(Player &p);
            void block(Player &p);
    };
}