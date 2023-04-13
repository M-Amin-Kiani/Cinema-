#include "exitmsg.h"
#include "ui_exitmsg.h"

ExitMsg::ExitMsg(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ExitMsg)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

}

ExitMsg::~ExitMsg()
{
	delete ui;
}

void ExitMsg::on_pushButton_3_clicked()
{
	exit(0);
}

void ExitMsg::on_pushButton_4_clicked()
{
	this->close();
}
