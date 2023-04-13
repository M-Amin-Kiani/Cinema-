#ifndef COSTUMERFORM_H
#define COSTUMERFORM_H

#include <QMainWindow>
#include <movie.h>
#include <customer.h>
namespace Ui {
class CostumerForm;
}

class CostumerForm : public QMainWindow
{
	friend class SelectUser;
	Q_OBJECT

public:
	explicit CostumerForm(QWidget *parent = nullptr);
	~CostumerForm();

private slots:
	void on_Reserve_clicked();

	void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

	void on_SignOut_clicked();

	void on_Edit_clicked();

private:
	Ui::CostumerForm *ui;
	QString Name;
	QString Family;
	void setIdentity(QString = "" , QString = "");
	void ShowIdentity();

	void ClearAllBorders();
	void Clear();
	Movie M;
	Customer C;

};

#endif // COSTUMERFORM_H
