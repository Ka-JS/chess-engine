#ifndef COCKATOO_HH
#define COCKATOO_HH
#include "bird.hh"

class Cockatoo : public Bird
{
public:
    Cockatoo();
    virtual ~Cockatoo();
    void vocalize(std::ostream& output) const override;
};

#endif // COCKATOO_HH
