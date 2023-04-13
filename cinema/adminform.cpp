#include "adminform.h"
#include "ui_adminform.h"
#include <selectuser.h>
#include <iostream>
#include<qhoversensitivebutton.h>
#include <message.h>
#include <selectuser.h>
AdminForm::AdminForm(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::AdminForm)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	ui->New->setText ("New");
	setIcons ();

	setNewPlaceholders();
	setSearchPlaceholders();
	setEditPlaceholders();
	setNewPersonPlaceholders();

	ClearAllBorders ();
	ui->New->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	ui->New->setCheck (1);

	ui->radioName->setChecked (1);

	Clear();
	ui->NewFrame->show ();



}

AdminForm::~AdminForm()
{
	delete ui;
}

void AdminForm::setIdentity(QString Name , QString Family)
{
	this->Name = Name;
	this->Family = Family;
}

void AdminForm::ShowIdentity()
{
	this->ui->UserName->setText(this->Name + " " + this->Family);
}

void AdminForm::setForPersonel()
{
	this->ui->NewPersonel->hide ();
}

//for Placeholder -63
void AdminForm::setNewPlaceholders()
{

	ui->MovieName->setPlaceholderText ("Movie Name");
	ui->Director->setPlaceholderText ("DirectorName");
	ui->Year->setPlaceholderText ("Year");
	ui->AgeLimit->setPlaceholderText ("Genre");
	ui->Capacity->setPlaceholderText ("Capacity");
}

void AdminForm::setSearchPlaceholders()
{
	ui->SearchTB->setPlaceholderText ("Name , Director , ...");
}

void AdminForm::setEditPlaceholders()
{
	ui->NewName->setPlaceholderText ("New Name");
	ui->NewDirector->setPlaceholderText ("New Director");
	ui->NewGenre->setPlaceholderText ("New Genre");
	ui->NewCapasity->setPlaceholderText ("New Capasity");
	ui->NewYear->setPlaceholderText ("New Year");

}

void AdminForm::setNewPersonPlaceholders()
{
	ui->PName->setPlaceholderText ("Name");
	ui->PFamily->setPlaceholderText ("Family");
	ui->PUserName->setPlaceholderText ("Username");
	ui->PPassword->setPlaceholderText ("Password");
}

//to hide everything
void AdminForm::Clear()
{
	ui->NewFrame->hide ();
	ui->SearchFrame->hide ();
	ui->DeleteFrame->hide ();
	ui->EditFrame->hide ();
	ui->NewPersonFrame->hide ();
	ui->ShowAllFrame->hide ();
	ui->SearchFrame->hide ();
	ui->SignOutFrame->hide ();
}

//to set buttons icons
void AdminForm::setIcons ()
{
	QIcon New(":/new/prefix1/Images/Plus.png");
	QIcon Delete(":/new/prefix1/Images/delete.png");
	QIcon Edit(":/new/prefix1/Images/edit.png");
	QIcon Search(":/new/prefix1/Images/search.png");
	QIcon NewPersonel(":/new/prefix1/Images/user.png");
	QIcon ShowAll(":/new/prefix1/Images/show.png");
	QIcon SignOut(":/new/prefix1/Images/logout.png");


	ui->New->setIcon (New);
	ui->Delete->setIcon (Delete);
	ui->Edit->setIcon (Edit);
	ui->Search->setIcon (Search);
	ui->NewPersonel->setIcon (NewPersonel);
	ui->ShowAll->setIcon (ShowAll);
	ui->SignOut->setIcon (SignOut);
}

//to clear all lines
void AdminForm::ClearAllBorders()
{

	ui->New->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");
	ui->Edit->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");
	ui->Delete->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");
	ui->Search->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");
	ui->NewPersonel->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");
	ui->ShowAll->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");
	ui->SignOut->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");


	ui->Search->setCheck (0);
	ui->New->setCheck (0);
	ui->Edit->setCheck (0);
	ui->Delete->setCheck (0);
	ui->NewPersonel->setCheck (0);
	ui->SignOut->setCheck (0);
	ui->ShowAll->setCheck (0);
	ui->NewPersonel->setCheck (0);


}

void AdminForm::on_New_clicked()
{
	ClearAllBorders ();
	ui->New->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	ui->New->setCheck (1);
	Clear();
	ui->NewFrame->show ();
}

void AdminForm::on_Search_clicked()
{
	ClearAllBorders ();
	ui->Search->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	ui->Search->setCheck (1);
	Clear();
	ui->SearchFrame->show ();
}

void AdminForm::on_ShowAll_clicked()
{
	ui->listWidget->clear ();
	ClearAllBorders ();
	ui->ShowAll->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	ui->ShowAll->setCheck (1);
	Clear();
	ui->ShowAllFrame->show ();

	this->M.ShowAll (ui->listWidget);
}

void AdminForm::on_Delete_clicked()
{
	ui->comboBox->clear ();

	ClearAllBorders ();
	ui->Delete->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	ui->Delete->setCheck (1);
	Clear();
	this->M.AddToCombo (ui->comboBox);
	ui->DeleteFrame->show();


}

void AdminForm::on_Edit_clicked()
{
	ui->EditComboName->clear ();

	ClearAllBorders ();
	ui->Edit->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	ui->Edit->setCheck (1);
	Clear();
	ui->EditFrame->show ();

	this->M.AddToCombo (ui->EditComboName);


}

void AdminForm::on_NewPersonel_clicked()
{
	ClearAllBorders ();
	ui->NewPersonel->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	ui->NewPersonel->setCheck (1);
	Clear();
	ui->NewPersonFrame->show ();
}

void AdminForm::on_SignOut_clicked()
{
	ClearAllBorders ();
	ui->SignOut->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");

	ui->SignOut->setCheck (1);
	Clear();
	ui->SignOutFrame->show ();

	this->P.ClearData ();
	SelectUser *F = new SelectUser;
	this->close ();
	F->show ();
}


void AdminForm::on_pushButton_clicked()
{
	this->M.AddMovie (ui->MovieName->text () ,  ui->Year->text () , ui->Director->text (), ui->AgeLimit->text () , ui->Capacity->text ());

	ui->MovieName->clear ();
	ui->Director->clear ();
	ui->Year->clear ();
	ui->AgeLimit->clear ();
	ui->Capacity->clear ();
}

void AdminForm::on_pushButton_4_clicked()
{

	QString value = this->ui->SearchTB->text ();
	bool check = 0;
	if(this->ui->radioName->isChecked ())
	{
		if(M.SearchByName (value))
		{

			this->ui->SearchResult->setText (this->M.getData ());
			check = 1;
		}
	}
	else if ( this->ui->radioGenre->isChecked ())
	{
		if(M.SearchByGenre (value))
		{


			this->ui->SearchResult->setText (this->M.getData ());
			check = 1;
		}
	}
	else
	{
		if(this->ui->radioDirector->isChecked ())
		{
			if(M.SearchByDirector (value))
			{


				this->ui->SearchResult->setText (this->M.getData ());
				check = 1;
			}
		}
	}
	this->ui->SearchTB->clear();

	if(check == 0)
	{
		Message *F = new Message;
		F->setText ("Record was not found");
		F->show ();
	}
}
//edit button
void AdminForm::on_pushButton_3_clicked()
{
	//	this->M.Delete (this->ui->EditComboName->currentText ());
	this->M.Edit (this->ui->EditComboName->currentText () , ui->NewName->text () , ui->NewYear->text () , ui->NewDirector->text () , ui->NewGenre->text () , ui->NewCapasity->text ());

	Message *F = new Message;
	F->setText ("Done!");
	F->show ();


}

void AdminForm::on_EditComboName_currentTextChanged(const QString &arg1)
{
	this->M.SearchByName (this->ui->EditComboName->currentText ());
	ui->DataForEdit->setText (this->M.getData ());

	this->ui->NewName->clear ();
	this->ui->NewYear->clear ();
	this->ui->NewDirector->clear ();
	this->ui->NewGenre->clear ();
	this->ui->NewCapasity->clear ();



}

void AdminForm::on_comboBox_currentTextChanged(const QString &arg1)
{
	this->M.SearchByName (this->ui->EditComboName->currentText ());
}
//delete button
void AdminForm::on_pushButton_10_clicked()
{
	this->M.Delete (ui->comboBox->currentText ());

	Message *F = new Message;
	F->setText ("Done!");
	F->show ();
}
//add personel
void AdminForm::on_Register_clicked()
{
	Message *F = new Message;

	if(!this->P.SaveFile (ui->PName->text () , ui->PFamily->text () , ui->PUserName->text() , ui->PPassword->text () , "PersonelData.dat"))
	{
		F->setText ("Personel added successfuly!");
		F->show ();
	}
	else
	{
		F->setText ("Username has been used by someone");
		F->show ();
	}

	ui->PName->clear ();
	ui->PFamily->clear();
	ui->PPassword->clear ();
	ui->PUserName->clear ();

}
