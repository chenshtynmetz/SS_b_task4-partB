#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"

namespace coup{
    //constructor
    Assassin::Assassin(Game& g, std::string str):Player(g, str){
        this->my_role = "Assassin";
    }

    //coup with 3 coins
    void Assassin:: coup(Player &p){
        if(this->game->sum_of_players < MIN_PLAYERS || this->game->sum_of_players > MAX_PLAYERS){
            throw std::runtime_error("the number of players not legall");
        }
        if(!this->status){
            throw std::runtime_error("this player not in the game");
        }
        if(!p.get_status()){
            throw std::runtime_error("this player not in the game");
        }
        if(this->coins() >= SUM_FOR_COUP){
            Player::coup(p);
            return;
        }
        if(this->game->turn() != this->name){
            throw std::runtime_error("this not your turn");
        }
        if(this->coins() < SUM_ASS_COUP){
            throw std::runtime_error("you dont have enough money");
        }
        this->game->started = true;
        p.set_status(false);
        this->game->last_coup = &p;
        while(true){
            this->game->curr++;
            if(this->game->curr == this->game->game_players.size()){
                this->game->curr = 0;
            }
            if(this->game->game_players.at(this->game->curr)->get_status()){
                break;
            }
        }
        this->set_coins(this->coins() - 3);
        this->last_action = "as_coup";
        this->game->sum_of_players--;
    }
}