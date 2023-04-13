#include "starter_page.h"
#include "ui_starter_page.h"
#include <QMovie>

using namespace std;
starter_page::starter_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::starter_page)
{
    ui->setupUi(this);

	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	QMovie *CamGif = new QMovie(":/new/prefix1/Images/CamGif.gif");
	QMovie *LoadingGif = new QMovie(":/new/prefix1/Images/Loading3.gif");
	QSize CamGifSize(125 , 125);
	QSize LoadingGifSize(300 , 40);
	CamGif->setScaledSize (CamGifSize);
	LoadingGif->setScaledSize (LoadingGifSize);
	ui->label->setMovie (CamGif);
	ui->label_4->setMovie (LoadingGif);
	CamGif->start ();
	LoadingGif->start ();

}


starter_page::~starter_page()
{
    delete ui;
}


