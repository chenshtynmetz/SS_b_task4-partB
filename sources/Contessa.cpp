#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#include "Contessa.hpp"

namespace coup{
    //constructor
    Contessa::Contessa(Game& g, std::string str):Player(g, str){
        this->my_role = "Contessa";
    }

    //block assassin
    void Contessa::block(Player &p){
        if(this->game->sum_of_players < MIN_PLAYERS || this->game->sum_of_players > MAX_PLAYERS){
            throw std::runtime_error("the number of players not legall");
        }
        if(!this->status){
            throw std::runtime_error("this player not in the game");
        }
        std::string last = p.get_last_action();
        if(p.role() == "Assassin"){
            if(last != "as_coup"){
                throw std::runtime_error("you can't block this action");
            }
            this->game->last_coup->set_status(true);
            this->game->sum_of_players++;
            this->game->last_coup = NULL;
        }
    }   
}