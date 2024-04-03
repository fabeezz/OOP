#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
private:
    std::string playerName;
    float balance;
    std::string password;

public:
    Player(const std::string &name, float balance, const std::string &password);

    bool authPassword(const std::string &inputPassword) const;
    bool authPlayerName(const std::string &inputPlayerName) const;
    std::string getName() const;
    float getBalance() const;
};

#endif // PLAYER_H
