#include <iostream>
#include <string>
#include <stdexcept>
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"

namespace coup{
    //constructor
    Duke::Duke(Game& g, std::string str):Player(g, str){
        this->my_role = "Duke";
    }

    //take 3 coins
    void Duke::tax(){
        if(this->game->sum_of_players < MIN_PLAYERS || this->game->sum_of_players > MAX_PLAYERS){
            throw std::runtime_error("the number of players not legall");
        }
        if(!this->status){
            throw std::runtime_error("this player not in the game");
        }
        if(this->game->turn() != this->name){
            throw std::runtime_error("this not your turn");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("you must do coup in this turn");
        }
        this->game->started = true;
        this->my_coins += 3;
        while(true){
            this->game->curr++;
            if(this->game->curr == this->game->game_players.size()){
                this->game->curr = 0;
            }
            if(this->game->game_players.at(this->game->curr)->get_status()){
                break;
            }
        }
        this->last_action = "tax";
    }

    //block "foreign_aid"
    void Duke::block(Player &p){
        if(this->game->sum_of_players < MIN_PLAYERS || this->game->sum_of_players > MAX_PLAYERS){
            throw std::runtime_error("the number of players not legall");
        }
        if(!this->status){
            throw std::runtime_error("this player not in the game");
        }
        if(!p.get_status()){
            throw std::runtime_error("this player not in the game");
        }
        std::string last = p.get_last_action();
        if(last != "foreign_aid"){
            throw std::runtime_error("you can't block this action");
        }
        int sum = p.coins();
        sum -= 2;
        p.set_coins(sum);
    }
}