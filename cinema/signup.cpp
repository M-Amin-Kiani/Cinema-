#include "signup.h"
#include "ui_signup.h"
#include <exitmsg.h>
#include <selectuser.h>
#include <customer.h>
#include <message.h>
SignUp::SignUp(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::SignUp)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	this->ui->InputName->setPlaceholderText ("Name");
	this->ui->InputFamily->setPlaceholderText ("Last Name");
	this->ui->InputUsername->setPlaceholderText ("Username");
	this->ui->InputPassword->setPlaceholderText ("Password");


}

SignUp::~SignUp()
{
	delete ui;
}

void SignUp::on_pushButton_2_clicked()
{
	ExitMsg * Msg = new ExitMsg;
	Msg->show ();

}

void SignUp::on_pushButton_3_clicked()
{
	SelectUser *F = new SelectUser;
	this->close ();
	F->show ();
}

void SignUp::on_pushButton_clicked()
{
	Customer C;
	if(C.SaveFile (ui->InputName->text () , ui->InputFamily->text () , ui->InputUsername->text () , ui->InputPassword->text (), "CustomerData.dat"))
	{
		SelectUser *F = new SelectUser;
		this->close ();
		F->show ();
	}
	else
	{
		Message *F = new Message;
		F->setText ("Username has been used by someone");
		F->show ();

		ui->InputName->clear ();
		ui->InputFamily->clear ();
		ui->InputUsername->clear ();
		ui->InputPassword->clear ();
	}
}
