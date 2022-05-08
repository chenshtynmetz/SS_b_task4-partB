#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#include "Captain.hpp"

namespace coup{
    //constructor
    Captain::Captain(Game& g, std::string str):Player(g, str){
        this->my_role = "Captain";
    }

    //steal 2 coins
    void Captain::steal(Player &p){
        if(this->game->sum_of_players < MIN_PLAYERS || this->game->sum_of_players > MAX_PLAYERS){
            throw std::runtime_error("the number of players not legall");
        }
        if(!this->status){
            throw std::runtime_error("this player not in the game");
        }
        if(!p.get_status()){
            throw std::runtime_error("this player not in the game");
        }
        if(this->game->turn() != this->name){
            throw std::runtime_error("this not your turn");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("you must do coup in this turn");
        }
        this->game->started = true;
        this->stolen_from = p.get_name();
        int sum = p.coins();
        if(sum <= 0){
            this->game->curr++;
            return;
        }
        if(sum == 1){
            sum = 0;
            p.set_coins(sum);
            sum = this->coins();
            sum += 1;
            this->set_coins(sum);
        }
        else{
            sum -= 2;
            p.set_coins(sum);
            sum = this->coins();
            sum += 2;
            this->set_coins(sum);
        }
        while(true){
            this->game->curr++;
            if(this->game->curr == this->game->game_players.size()){
                this->game->curr = 0;
            }
            if(this->game->game_players.at(this->game->curr)->get_status()){
                break;
            }
        }
        this->last_action = "steal";
    }

    //block steal
    void Captain::block(Player &p){
        if(this->game->sum_of_players < MIN_PLAYERS || this->game->sum_of_players > MAX_PLAYERS){
            throw std::runtime_error("the number of players not legall");
        }
        if(!this->status){
            throw std::runtime_error("this player not in the game");
        }
        if(!p.get_status()){
            throw std::runtime_error("this player not in the game");
        }
        if(p.get_last_action() != "steal"){
            throw std::runtime_error("you can't block this action");
        }
        unsigned ind = 0;
        for(unsigned i= 0; i<this->game->game_players.size(); i++){
            if(this->game->game_players.at(i)->get_name() == p.get_stolen()){
                ind = i;
            }
        }
        int sum = this->game->game_players.at(ind)->coins();
        sum += 2;
        this->game->game_players.at(ind)->set_coins(sum);
        sum = p.coins();
        sum -= 2;
        p.set_coins(sum);
    }
}