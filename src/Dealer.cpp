// 
// MacOSX Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Dealer.hpp"

std::array<int, 52> Dealer::newShuffledDeck() {
    std::array<int, 52> newDeck = deck;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(newDeck.begin(), newDeck.end(), std::default_random_engine(seed));
    return newDeck;
}