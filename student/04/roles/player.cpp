#include "player.hh"



Player::Player(int from_year) :
        Role(from_year), instrument_("")
{

}

Player::~Player()
{

}

void Player::add_instrument(const string &instrument)
{
    instrument_ = instrument;

}

void Player::print(ostream &output) const
{
    if (instrument_.empty()) {
        output << "No instrument" << endl;
    } else {
        output << "Instrument to be played: " << instrument_ << endl;
    }
}

