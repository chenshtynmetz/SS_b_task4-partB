#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Ambassador : public Player{
        private:

        public:
            Ambassador(Game& g, std::string str);
            void transfer(Player &p1, Player &p2);
            void block(Player &p);
    };
}