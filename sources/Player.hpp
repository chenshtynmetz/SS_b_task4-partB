#pragma once
#include <string>
#include "Game.hpp"

#define SUM_FOR_COUP 7
#define MAX_COINS 10
#define MAX_PLAYERS 6
#define MIN_PLAYERS 2

namespace coup{
    class Game;
    class Player{
        protected:
            Game* game;
            std::string name;
            int my_coins;
            std::string my_role;
            std::string last_action;
            std::vector<Player*> stolen;
            bool status; //the player in play?  
            std::string stolen_from;    
        public:
            Player(Game& g, std::string &str);
            void income();
            void foreign_aid();
            virtual void coup(Player& p);
            std::string role();
            int coins()const;
            std::string get_last_action();
            void set_coins(int sum);
            std::string get_name();
            bool get_status()const;
            void set_status(bool b);
            std::string get_stolen();
    };
}
