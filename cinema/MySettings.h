#ifndef MYSETTINGS_H
#define MYSETTINGS_H
#include <QMessageBox>
#include <QString>
class MySettings
{
public :
	static int ShowMessage(QString Message , int button)
	{
		if(button == 1) // OK
		{
			QMessageBox msgBox;
			msgBox.setInformativeText(Message);
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setStyleSheet ("background-color : #289c8e; color : #FFFFFF; width : 310px; height : 20px; font: 15pt \"Calibri\";border-radius : 2px; border-color : #FFFFFF");
			msgBox.setDefaultButton(QMessageBox::Ok);
			int R = msgBox.exec();
			return R;
		}

		return 0;
	}
};




#endif // MYSETTINGS_H
