#ifndef ORGANIZER_H
#define ORGANIZER_H
class organizer
{
protected:
    int type; // 1:footsal    2:wrestling        3:box
public:
    int get_type();
    virtual void show_participant() = 0;
    virtual void show_tournament() = 0;//and show matches in every tournament
    virtual void show_score_table() = 0;
    virtual bool add_tournament() = 0;
    virtual void manage_matches()=0;//define matches in a tournoment
    virtual void update_results()=0;
    virtual void edit_match()=0;
    virtual void cancel_match()=0;
};
#endif // ORGANIZER_H

