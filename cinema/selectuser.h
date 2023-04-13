#ifndef SELECTUSER_H
#define SELECTUSER_H

#include <QMainWindow>
#include <QTimer>
#include <personel.h>
#include <customer.h>


namespace Ui {
class SelectUser;
}

class SelectUser : public QMainWindow
{
	Q_OBJECT

public:
	explicit SelectUser(QWidget *parent = nullptr);
	~SelectUser();
	void Show(int delay)
	{
		QTimer::singleShot (delay *1000 , this ,[this] {show();});
	}

private slots:
	void on_pushButton_2_clicked();

	void on_pushButton_clicked();

	void on_ShowPassBtn_clicked();

	void on_pushButton_3_clicked();

private:
	Ui::SelectUser *ui;
	Personel P;
	Customer C;
};

#endif // SELECTUSER_H
