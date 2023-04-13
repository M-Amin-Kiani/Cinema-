#include "movie.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <vector>
#include <iostream>
Movie::Movie()
{

}

void Movie::ReadReservedNum(Customer *C)
{
	QFile file("ReservedNum.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadNum = in.readLine ();
		if(ReadName == C->getName ())
		{
			C->ReservedMoviesNum = ReadNum.toInt ();
			break;
		}
	}
}

void Movie::WriteReservedNum(Customer *C)
{
	QList<QString> list;

	QFile file("ReservedNum.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;


	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadNum = in.readLine ();

		if(ReadName != C->getName ())
		{
			list << ReadName <<ReadName << ReadNum;
		}
		else
		{
			list << ReadName <<ReadName << QString::number ((ReadNum.toInt () + 1));
		}

	}




	file.close ();
	UpdateC(list);

}

int Movie::getCapasity (QString Name)
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return -1;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();

		if(ReadName == Name)
		{
			return ReadCapasity.toInt ();
		}
	}
	return -1;
}

void Movie::UpdateCapasity(int num)
{
	QList<QString> list;

	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;


	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();



		if(ReadName != Name)
		{
			list << ReadName <<ReadYear << ReadDirector << ReadGenre << ReadCapasity << tmp;
		}
		else
		{
			list << ReadName << ReadYear << ReadDirector << ReadGenre << QString::number((ReadCapasity.toInt () - num ))<< tmp;
		}

	}




	file.close ();
	Write(list);

}

void Movie::Write(QString text)
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return ;

	QTextStream out(&file);
	out << text;
}

void Movie::Write(QList<QString> list)
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return ;

	QTextStream out(&file);

	for(int i = 0 ; i < list.length () ; i++)
	{
		out << list[i] << endl;
		std::cerr << list[i].toStdString ();

	}
}

void Movie::UpdateC(QList<QString> list)
{
	QFile file("ReservedNum.dat");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return ;

	QTextStream out(&file);

	for(int i = 0 ; i < list.length () ; i++)
	{
		out << list[i] << endl;
		std::cerr << list[i].toStdString ();

	}
}

QString Movie::ReadAll ()
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return "";

	file.close ();
	return file.readAll ();
}

void Movie::AddMovie(QString Name , QString Year , QString Director , QString Genre , QString Capacity)
{
	setData (Name , Year , Director , Genre , Capacity);

	QFile file("Movie.dat");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return ;

	QTextStream out(&file);
	out << Name << endl << Year << endl << Director << endl << Genre << endl<< Capacity << endl;
	out << "===========================================" << endl;
}

bool Movie::SearchByName(QString Name)
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return 0;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();

		if(ReadName == Name)
		{
			this->setData (ReadName , ReadYear , ReadDirector , ReadGenre , ReadCapasity);
			return 1;
		}
	}
	return 0;
}

bool Movie::SearchByDirector(QString Direcor)
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return 0;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();

		if(ReadDirector == Direcor)
		{
			this->setData (ReadName , ReadYear , ReadDirector , ReadGenre , ReadCapasity);
			return 1;
		}
	}
	return 0;
}

bool Movie::SearchByGenre(QString Genre)
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return 0;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();

		if(ReadGenre == Genre)
		{
			this->setData (ReadName , ReadYear , ReadDirector , ReadGenre , ReadCapasity);
			return 1;
		}
	}
	return 0;
}

void Movie::ShowAll(QListWidget * list)
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return ;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();


		list->addItem (ReadName);
	}
}




void Movie::AddToCombo(QComboBox * list)
{
	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return ;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();


		list->addItem (ReadName);
	}
}

void Movie::Delete(QString Name)
{

	QList<QString> list;

	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;


	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();



		if(ReadName != Name)
		{
			list << ReadName <<ReadYear << ReadDirector << ReadGenre << ReadCapasity << tmp;
		}

	}




	file.close ();
	Write(list);

}

void Movie::Edit(QString Name , QString NewName , QString NewYear , QString NewDirector , QString NewGenre , QString NewCapasity)
{

	QList<QString> list;

	QFile file("Movie.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;


	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadName = in.readLine ();
		QString ReadYear = in.readLine ();
		QString ReadDirector = in.readLine ();
		QString ReadGenre = in.readLine ();
		QString ReadCapasity = in.readLine ();
		QString tmp = in.readLine ();



		if(ReadName != Name)
		{
			list << ReadName <<ReadYear << ReadDirector << ReadGenre << ReadCapasity << tmp;
		}
		else
		{
			list << NewName << NewYear << NewDirector << NewGenre << NewCapasity << tmp;
		}

	}




	file.close ();
	Write(list);


}

void Movie::setData(QString Name, QString Director, QString Year, QString Genre, QString Capasity)
{
	this->Name = Name;
	this->Year = Year;
	this->Director = Director;
	this->Genre = Genre;
	this->Capasity = Capasity;
}



QString Movie::getName()
{
	return this->Name;
}

QString Movie::getYear()
{
	return this->Year;
}

QString Movie::getGenre()
{
	return this->Genre;
}

QString Movie::getCapasity()
{
	return this->Capasity;
}

QString Movie::getDirector()
{
	return this->Director;
}

