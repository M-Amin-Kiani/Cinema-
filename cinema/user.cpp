#include "user.h"
#include <QFile>
#include <QTextStream>
#include <user.h>
#include <iostream>
User::User()
{

}

bool User::LoadFile (QString EnteryUsername , QString EnteryPassword , QString FileName)
{
	QFile file(FileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			return 0;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadUser = in.readLine ();
		QString ReadPass = in.readLine ();
		QString ReadName = in.readLine ();
		QString ReadFam = in.readLine ();
        QString Readsplit = in.readLine();
		if(ReadUser == EnteryUsername && ReadPass == EnteryPassword)
		{
			this->setData (ReadName , ReadFam , ReadUser , ReadPass);
			return 1;
		}
	}
	return 0;

}
///returns 0 if User is not repited
bool User::LoadFile(QString Username , QString FileName)
{
	QFile file(FileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			return 0;

	QTextStream in(&file);
	while(!in.atEnd ())
	{
		QString ReadUser = in.readLine ();
		if(ReadUser == Username)
			return 1;
	}
	return 0;
}

bool User::SaveFile(QString Name , QString Family , QString Username , QString Password, QString FileName)
{
	if(LoadFile(Username , FileName))
		return 0;
	else
	{
		this->setData (Name , Family , Username , Password);

		QFile file(FileName);
		   if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
			   return 0;

		   QTextStream out(&file);
           out << Username << endl << Password << endl << Name << endl << Family << endl << "===========================================" << endl;
		   return 1;
	}
}
