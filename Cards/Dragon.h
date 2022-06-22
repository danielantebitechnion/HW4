#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

class Dragon : public Battle
{
    public:

        Dragon ();

        void printInfo(std::ostream& os) const override;
        
    private:

        // Nothing
};

#endif // EX4_DRAGON_H