#ifndef HOCKEY_PLAYER_H
#define HOCKEY_PLAYER_H

#include <string>

class HockeyPlayer {
public:
    int id;
    std::string name;
    int jersey;
    std::string teamName;

    HockeyPlayer(int id, std::string& name, int jersey, std::string& teamName);
};

#endif // HOCKEY_PLAYER_H