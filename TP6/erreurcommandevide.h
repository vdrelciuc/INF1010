/*
* Titre : erreurcommandevide.h - Travail pratique #6
* Date : 16 avril 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef ERREURCOMMANDEVIDE_H
#define ERREURCOMMANDEVIDE_H

#include <QException>

class ErreurCommandeVide: public QException
{
public:
    ErreurCommandeVide(QString s) : s_(s){}
    virtual QString what() { return s_; }
private :
    QString s_;
};

#endif // ERREURCOMMANDEVIDE_H
