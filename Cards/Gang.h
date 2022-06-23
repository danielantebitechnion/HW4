#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include "Battle.h"
#include <memory>
#include <vector>

class Gang : public Card
{
    public:

        Gang (std::vector<std::unique_ptr<Battle>>&& monsters);

        void applyEncounter(Player& player) const override;

    private:

        std::vector<std::unique_ptr<Battle>> m_monsters;
};

#endif // EX4_GANG_H