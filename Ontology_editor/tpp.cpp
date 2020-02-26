#include "tpp.h"

TPP::TPP()
{

}
QString TPP::getTPP(TPPs tpp)
{
    if (tpp == TPPs::TPP_Static)
        return "static";
    if (tpp == TPPs::TPP_Dinamic)
        return "dinamic";
    if (tpp == TPPs::TPP_Tutoring)
        return "tutoring";
}
TPP::TPPs TPP::getObject(QString tpp)
{
    if(tpp == "static")
        return TPPs::TPP_Static;
    if(tpp == "dinamic")
        return TPPs::TPP_Dinamic;
    if(tpp == "tutoring")
        return TPPs::TPP_Tutoring;

}
