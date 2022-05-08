#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"


namespace coup{
    class Contessa : public Player{
        private:

        public:
            Contessa(Game& g, std::string str);
            void block(Player &p);
    };
}