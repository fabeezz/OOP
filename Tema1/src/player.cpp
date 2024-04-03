#include "../include/player.h"

Player::Player(const std::string &name, float balance, const std::string &password)
    : playerName(name), balance(balance), password(password) {}

bool Player::authPassword(const std::string &inputPassword) const
{
    return inputPassword == password;
}

bool Player::authPlayerName(const std::string &inputPlayerName) const
{
    return inputPlayerName == playerName;
}

std::string Player::getName() const
{
    return playerName;
}

float Player::getBalance() const
{
    return balance;
}
