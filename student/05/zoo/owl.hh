#ifndef OWL_HH
#define OWL_HH
#include"bird.hh"

class Owl: public Bird
{
public:
    Owl();
    virtual ~Owl();
    void vocalize(std::ostream& output) const override;
private:
    // attributes
};

#endif // OWL_HH
