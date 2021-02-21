#ifndef DOCTOR_H
#define DOCTOR_H
#include "player.h"

class doctor : public player
{
private:
    quint8 last_choice;
public:
    doctor();
    doctor(quint8 id, QString name, QString gender, quint8 age, quint8 elo, quint8 inc, quint8 pas, quint8 det);
    doctor(const player &player);
    quint8 Action(quint16 time, std::vector<player*> p_list, quint8 *votes);
    quint8 Discussion(quint16 time, std::vector<player*> p_list);
    void Listen(player* a, quint8 b, bool is_good);
};

#endif // DOCTOR_H
