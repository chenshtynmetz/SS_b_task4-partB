#include <iostream>
#include <string>
#include <stdexcept>
#include "Game.hpp"
#include "Player.hpp"


namespace coup{
    //constructor
    Player::Player(Game &g, std::string &str){
        this->game = &g; //the game
        if(this->game->started){ //cannot add player if the game already begin
            throw std::runtime_error("the game already started");
        }
        this->name = str;
        this->my_coins = 0;
        this->last_action = "";
        this->stolen_from = "";
        //tha player is alive?
        this->status = true;
        //the maximum player in the game is 6
        if(this->game->sum_of_players >= MAX_PLAYERS){
            throw std::runtime_error("too many players");
        }
        //add the player to the game
        this->game->add_player(this);
    }

    //take 1 coin 
    void Player::income(){
        if(this->game->sum_of_players < MIN_PLAYERS || this->game->sum_of_players > MAX_PLAYERS){
            throw std::runtime_error("the number of players not legall");
        }
        if(this->game->turn() != this->name){
            throw std::runtime_error("this not your turn");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("you must do coup in this turn");
        }
        this->game->started = true;
        my_coins++;
        while(true){
            this->game->curr++;
            if(this->game->curr == this->game->game_players.size()){
                this->game->curr = 0;
            }
            if(this->game->game_players.at(this->game->curr)->status){
                break;
            }
        }
        this->last_action = "income";
    }
    //take 2 coins
    void Player::foreign_aid(){
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
        this->my_coins += 2;
        while(true){
            this->game->curr++;
            if(this->game->curr == this->game->game_players.size()){
                this->game->curr = 0;
            }
            if(this->game->game_players.at(this->game->curr)->status){
                break;
            }
        }
        this->last_action = "foreign_aid";
    }

    void Player::coup(Player& p){
        if(this->game->sum_of_players < MIN_PLAYERS || this->game->sum_of_players > MAX_PLAYERS){
            throw std::runtime_error("the number of players not legall");
        }
        if(!this->status){
            throw std::runtime_error("this player not in the game");
        }
        if(!p.status){
            throw std::runtime_error("this player not in the game");
        }
        if(this->game->turn() != this->name){
            throw std::runtime_error("this not your turn");
        }
        if(this->my_coins < SUM_FOR_COUP){
            throw std::runtime_error("you dont have enough coins for this action"); 
        }
        this->game->started = true;
        p.status = false;
        this->game->last_coup = &p;
        while(true){
            this->game->curr++;
            if(this->game->curr == this->game->game_players.size()){
                this->game->curr = 0;
            }
            if(this->game->game_players.at(this->game->curr)->status){
                break;
            }
        }
        this->last_action = "coup";
        this->game->sum_of_players--;
        this->set_coins(this->coins() - SUM_FOR_COUP);
    } 

    //return the role pf the player
    std::string Player::role(){
        return this->my_role;
    }

    //return the sum of coins
    int Player::coins()const{
        return this->my_coins;
    }

    //return the last action
    std::string Player::get_last_action(){
        return this->last_action;
    }

    //set num of coins
    void Player::set_coins(int sum){
        if(!this->status){
            throw std::runtime_error("this player not in the game");
        }
        this->my_coins = sum;
    }

    //return the name of the player
    std::string Player::get_name(){
        return this->name;
    }

    //return the status of the player
    bool Player::get_status()const{
        return this->status;
    }

    //set status
    void Player::set_status(bool b){
        this->status = b;
    }

    //return from who steal
    std::string Player::get_stolen(){
        return this->stolen_from;
    }
}