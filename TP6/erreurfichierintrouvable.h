/*
* Titre : erreurfichierintrouvable.h - Travail pratique #6
* Date : 16 avril 2019
* Auteurs : Vlad Drelciuc et Justin van den Hanenberg
*/

#ifndef ERREURFICHIERINTROUVABLE_H
#define ERREURFICHIERINTROUVABLE_H

#include <QString>
#include <QException>

using namespace std;

class ErreurFichierIntrouvable: public QException
{
public:
    ErreurFichierIntrouvable(QString s) : s_(s){}
    virtual QString what() { return s_; }
private :
    QString s_;
};
#endif // ERREURFICHIERINTROUVABLE_H
