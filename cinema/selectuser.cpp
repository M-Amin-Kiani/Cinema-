#include "selectuser.h"
#include "ui_selectuser.h"
#include <QTimer>
#include <MySettings.h>
#include <exitmsg.h>
#include <QRegion>
#include <signup.h>
#include <iostream>
#include <message.h>
#include <adminform.h>
#include <costumerform.h>
SelectUser::SelectUser(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::SelectUser)
{
	ui->setupUi(this);

	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	this->ui->InputUsername->setPlaceholderText ("Username");
	this->ui->InputPassword->setPlaceholderText ("Password");


	this->ui->ShowPassBtn->setStyleSheet ("border-radius : 50%; image: url(:/new/prefix1/Images/close_eye.png); background-color: rgba(255, 255, 255 , 0);");
	this->ui->InputPassword->setEchoMode (QLineEdit::Password);

	ui->radioP->setChecked (1);

}



SelectUser::~SelectUser()
{
	delete ui;
}

void SelectUser::on_pushButton_2_clicked()
{
	ExitMsg *F = new ExitMsg;
	F->show ();
}



void SelectUser::on_pushButton_clicked()
{
	if(ui->radioC->isChecked ())
	{
		if(C.LoadFile (this->ui->InputUsername->text () , this->ui->InputPassword->text () , "CustomerData.dat"))
		{
			CostumerForm *F = new CostumerForm;
			F->setIdentity (C.getName () , C.getFamily ());
			F->ShowIdentity ();
			this->close ();
			F->show ();
		}

		else
		{
			Message *F = new Message();
			F->setText ("Invalid username or password");
			F->show ();

			ui->InputPassword->clear ();
			ui->InputUsername->clear ();
		}
	}

	else if(ui->radioP->isChecked ())
	{
		if(this->ui->InputUsername->text () == "admin" && this->ui->InputPassword->text () == "admin" )
		{
			//admin form
			AdminForm *F = new AdminForm;
			F->setIdentity ();
			F->ShowIdentity ();

			this->close ();
			F->show ();
		}

		if(P.LoadFile (this->ui->InputUsername->text () , this->ui->InputPassword->text () , "PersonelData.dat"))
		{
			AdminForm *F = new AdminForm;
			F->setForPersonel ();
			F->setIdentity (P.getName () , P.getFamily ());
			F->ShowIdentity ();
			this->close ();
			F->show ();
		}
		else
		{
			Message *F = new Message();
			F->setText ("Invalid username or password");
			F->show ();

			ui->InputPassword->clear ();
			ui->InputUsername->clear ();
		}
	}

	else
	{
		Message *F = new Message();
		F->setText ("Do you want to login as a customer or personel?");
		F->show ();


	}

}

void SelectUser::on_ShowPassBtn_clicked()
{
	if(this->ui->InputPassword->echoMode () == QLineEdit::Password)
	{
		this->ui->ShowPassBtn->setStyleSheet ("border-radius : 50%; image: url(:/new/prefix1/Images/open_eye.png); background-color: rgba(255, 255, 255 , 0);");
		this->ui->InputPassword->setEchoMode (QLineEdit::Normal);
	}

	else
	{
		this->ui->ShowPassBtn->setStyleSheet ("border-radius : 50%; image: url(:/new/prefix1/Images/close_eye.png); background-color: rgba(255, 255, 255 , 0);");
		this->ui->InputPassword->setEchoMode (QLineEdit::Password);
	}
}

void SelectUser::on_pushButton_3_clicked()
{
	SignUp *F = new SignUp;
	this->close();
	F->show ();
}
