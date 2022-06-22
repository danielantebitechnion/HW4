#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include "Battle.h"
#include <vector>

class Gang : public Card
{
    public:

        Gang (const std::vector<Battle> monsters);

        void applyEncounter(Player& player) const override;

    private:

        const std::vector<Battle> m_monsters;
};

#endif // EX4_GANG_H