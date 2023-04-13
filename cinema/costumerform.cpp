#include "costumerform.h"
#include "ui_costumerform.h"
#include <message.h>
#include <iostream>
#include <selectuser.h>
CostumerForm::CostumerForm(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::CostumerForm)
{
	ui->setupUi(this);

	Clear();
	this->ui->ShowAllFrame->show ();
}
CostumerForm::~CostumerForm()
{
	delete ui;
}

void CostumerForm::setIdentity(QString Name , QString Family)
{
	this->Name = Name;
	this->Family = Family;
}

void CostumerForm::ShowIdentity()
{
	this->ui->UserName->setText(this->Name + " " + this->Family);
}


void CostumerForm::on_Reserve_clicked()
{
	ui->listWidget->clear ();
	ClearAllBorders ();
	ui->Reserve->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	ui->Reserve->setCheck (1);
	Clear();
	ui->ShowAllFrame->show ();

	this->M.ShowAll (ui->listWidget );

}

//to clear all lines
void CostumerForm::ClearAllBorders()
{

	ui->Reserve->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");
	ui->Edit->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");

	ui->Reserve->setCheck (0);


}

//to hide everything
void CostumerForm::Clear()
{
	ui->NewFrame->hide ();

}



void CostumerForm::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
	this->M.SearchByName (item->text ());

	this->ui->Data->setText (this->M.getData ());

	if(this->M.getCapasity () != 0)
	{
		this->M.UpdateCapasity (1);

		Message *F = new Message;
		F->setText ("Reserved successfuly");
		F->show ();
		this->ui->Data->setText (this->M.getData ());
		this->M.ReadReservedNum (&C);
		this->M.WriteReservedNum (&C);
	}
	else
	{
		Message *F = new Message;
		F->setText ("This movie has no place");
		F->show ();
	}
}

void CostumerForm::on_SignOut_clicked()
{
	ClearAllBorders ();
	ui->SignOut->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");

	ui->SignOut->setCheck (1);
	Clear();
	ui->SignOutFrame->show ();

	SelectUser *F = new SelectUser;
	this->close ();
	F->show ();
}

void CostumerForm::on_Edit_clicked()
{
//    this->ui->Fuc
}
