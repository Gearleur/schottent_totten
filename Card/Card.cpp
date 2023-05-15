//
// Created by alexa on 15/05/2023.
//

#include "Card.h"
#include "../Utils/enums.h"
#include "../Player/Player.h"

#include <iostream>

//showcard() function
//This function is used to display the card in the console
void Card::showCard() const {
    std::cout << "Card: " << this->name << std::endl;
    std::cout << "Type: " << this->type << std::endl;
    std::cout << "Color: " << this->color << std::endl;
    std::cout << "Description: " << this->description << std::endl;

}