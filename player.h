#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QGraphicsView>
#include <vector>

class player
{
protected:
    struct _vote {
        quint8 id;
        qint8 priority;
        bool operator== (const quint8 &c)
        {
            return (this->id == c);
        }
    };
        QString image = "";
        std::vector<_vote> enemies;
        void addEnemy(quint8 i, qint8 p);


        static bool comp(const _vote &a, const _vote &b);

private:

    QGraphicsView *block;
public:

    bool is_life = true;
    //Блок описания игрока
    quint8 ID;
    QString Name;
    enum {male, female} Gender;
    quint8 Age;

    struct {
        quint8 Eloquence; //Красноречие
        quint8 Incredulity; //Недоверчивость
        quint8 Aggression; //Скрытая агрессия
        quint8 Determination; //Решимость
    } Mental;

    player();
    player(quint8 id, QString name, QString gender, quint8 age, quint8 elo, quint8 inc, quint8 pas, quint8 det);

    virtual quint8 Action(quint16 time, std::vector<player*> p_list, quint8 *votes = nullptr) = 0;
    virtual quint8 Discussion(quint16 time, std::vector<player*> p_list) = 0;
    virtual void Listen(player* a, quint8 b, bool is_good) = 0;
    quint8 vote(quint16 time, quint8* votes, quint8 p_count);

    void Die(bool h);
    QGraphicsScene* createScene(bool h);
    void setGraphicsView(QGraphicsView *b);

    void delEnemy(quint8 i);

    static bool accident(quint8 p);
};

#endif // PLAYER_H
