#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <user.h>
#include <QString>
#include <QList>

class Customer : public User  // sub of user is c
{
	friend class Movie;
public:
	Customer();

private :
	int ReservedMoviesNum;
};



#endif // CUSTOMER_H


