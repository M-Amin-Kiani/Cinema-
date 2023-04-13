#ifndef STARTER_PAGE_H
#define STARTER_PAGE_H

#include <QMainWindow>
#include <selectuser.h>
#include <QMovie>
#include <ui_starter_page.h>
#include <QLabel>
#include <QtGui>
#include <chrono>
#include <time.h>
#include <QTimer>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class starter_page; }
QT_END_NAMESPACE

class starter_page : public QMainWindow
{
	friend int main(int, char *[]);

    Q_OBJECT

public:
    starter_page(QWidget *parent = nullptr);
    ~starter_page();

	void HideLoading()
	{
		this->ui->label_4->hide ();
	}

	void ShowLoading()
	{
		this->ui->label_4->show();
	}


	void SplashEffect()
	{

		chrono::steady_clock::time_point tend = chrono::steady_clock::now()
			+ chrono::milliseconds(600);
		// for timer

		this->setWindowOpacity (0.0);
		double Value = 0.000065;


		while (chrono::steady_clock::now() < tend) // timer loop :)
		{
			this->setWindowOpacity (Value);
			Value += 0.0005;
		}
		Sleep(200);
	}


	void delay(int delay)
	{
		QTimer::singleShot (delay *1000 , this ,[this] {hide();});

//		this->hide();
//		Sleep(6000);
//		F->show();
	}





private slots:

private:
    Ui::starter_page *ui;

};
#endif // STARTER_PAGE_H
