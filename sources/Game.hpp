#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

namespace coup{
    class Player;
    class Game{
        public:
            unsigned curr;
            bool started;
            int sum_of_players;
            std::vector<Player*> game_players;
            Player* last_coup;
            Game();
            std::string turn();
            std::vector<std::string> players();
            std::string winner();
            void add_player(Player *p);
    };
}
