#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Game.hpp"
#include "Player.hpp"


namespace coup{
    //constructor
    Game::Game(){
        this->game_players = {}; //vector of players
        this->curr = 0; //the current turn
        this->sum_of_players = 0;
        this->last_coup = NULL; 
        this->started = false; //the game start?
    }

    //return the current turn on the game
    std::string Game::turn(){
        return (*this->game_players.at((unsigned)this->curr)).get_name();
    }

    //return list of all the vector that play in the game
    std::vector<std::string> Game::players(){
        std::vector<std::string> ans = {};
        int len= this->game_players.size();
        for(unsigned i=0; i<len; i++){
            //if this player dead- dont return him
            if(!this->game_players.at(i)->get_status()){
                continue;
            }
            ans.push_back(this->game_players.at(i)->get_name());
        } 
        return ans; 
    }

    // return the winner in the game
    std::string Game::winner(){
        //check if the game over
        if(this->sum_of_players != 1){
            throw std::runtime_error("the game dont over");
        }
        //check if the game start
        if(this->game_players.size()<=1){
            throw std::runtime_error("the game didnt start"); 
        }
        std::string win;
        //find the winner
        for(unsigned i=0; i<this->game_players.size(); i++){
            if((*this->game_players.at(i)).get_status()){
                win = (*this->game_players.at(i)).get_name();
                break;
            }
        }
        return win;
    }

    //this function add player to the vector
    void Game::add_player(Player *p){
        this->sum_of_players++;
        this->game_players.push_back(p);
    }
}