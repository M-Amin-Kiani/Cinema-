#ifndef MOVIE_H
#define MOVIE_H
#include <QString>
#include <QListWidget>
#include <QComboBox>
#include <customer.h>
class Movie
{
	friend class AdminForm;
	friend class CostumerForm;
public:
	Movie();

	void setData(QString Name , QString DIrector , QString Year , QString Genre ,QString Capasity);


    QString getName();
    QString getDirector();
    QString getYear();
    QString getGenre();
    QString getCapasity();

private :
    QString Name;
    QString Director;
    QString Year;
    QString Genre;
    QString Capasity;

	void AddMovie(QString Name , QString Year , QString Director , QString Genre , QString Capacity);

	bool SearchByName(QString Name);
	bool SearchByGenre(QString Genre);
	bool SearchByDirector(QString Direcor);
	void ShowAll(QListWidget *);
	void ShowAll(QListWidget * , int);
	void AddToCombo(QComboBox *);
	void Delete(QString Name);
	void Edit(QString Name , QString NewName , QString NewYear , QString NewDirector , QString NewGenre , QString NewCapasity);
	void Write(QString text);
	void Write(QList<QString>);
	QString ReadAll();
	int getCapasity(QString );
	void UpdateCapasity(int = 1);
	void ReadReservedNum(Customer * );
	void WriteReservedNum(Customer * C);
	void UpdateC(QList<QString> );
	QString getData()
	{
		return "Name : " + this->getName () + "\nDirector : " + this->getDirector ()
				+ "\nYear of construction : " + this->getYear () + "\nGenre : " + this->getGenre () +
				"\nCapasity : " + this->getCapasity ();

	}
};

#endif // MOVIE_H
