#ifndef USER_H
#define USER_H
#include <QString>

class User  // for all member
{

private :
int id;
QString Name;
QString Family;
QString Username;
QString Password;



public:
	User();


	void setData(QString Name , QString Family , QString Username , QString Password)
	{
		this->Name = Name;
		this->Family = Family;
		this->Username = Username;
		this->Password = Password;
	}

	QString getName()
	{
		return Name;
	}
	QString getFamily()
	{
		return Family;
	}
	QString getUsername()
	{
		return Username;
	}
	QString getPassword()
	{
		return Password;
	}


	void ClearData()
	{
		Name.clear();
		Family.clear();
		Username.clear();
		Password.clear();
	}

	bool LoadFile(QString EntryUsername , QString EnteryPassword , QString FileName);
		//read from file and set theme in object fields
		//exmpl : this.name = <name in file>;

	bool SaveFile(QString Name , QString Family , QString Username , QString Password, QString FileName);
		//save object fields in file
		//it has to be check if username us not repited with func
		//exmpl: write <this.name>

	bool LoadFile(QString Username , QString FileName);
		//open the file and check if this.Username is  repited in file ot not

};

#endif // USER_H
