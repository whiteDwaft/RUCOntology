#ifndef TPP_H
#define TPP_H

#include <QString>



class TPP
{
public:
    TPP();
    enum class TPPs
    {
       TPP_Static,
       TPP_Dinamic,
       TPP_Tutoring
    };
    QString getTPP(TPPs tpp);
    TPPs getObject(QString tpp);
};

#endif // TPP_H
