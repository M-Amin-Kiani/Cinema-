#include "message.h"
#include "ui_message.h"

Message::Message(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Message)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Message::~Message()
{
	delete ui;
}

void Message::setText(QString Text)
{
	this->ui->text->setText (Text);
	ui->text->setWordWrap (true);
}

void Message::on_pushButton_3_clicked()
{
	this->close ();
}
