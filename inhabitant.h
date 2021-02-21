#ifndef INHABITANT_H
#define INHABITANT_H
#include "player.h"

class inhabitant : public player
{
public:
    inhabitant();
    inhabitant(const player &player);
    inhabitant(quint8 id, QString name, QString gender, quint8 age, quint8 elo, quint8 inc, quint8 pas, quint8 det);
    quint8 Action(quint16 time, std::vector<player*> p_list, quint8 *votes);
    quint8 Discussion(quint16 time, std::vector<player*> p_list);
    void Listen(player* a, quint8 b, bool is_good);
};

#endif // INHABITANT_H
