#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QMainWindow>
#include <QPushButton>
#include <movie.h>
#include <personel.h>
namespace Ui {
class AdminForm;
}

class AdminForm : public QMainWindow
{
	friend class SelectUser;
	Q_OBJECT

public:

	explicit AdminForm(QWidget *parent = nullptr);
	~AdminForm();



private slots:

	void on_New_clicked();

	void on_Search_clicked();

	void on_ShowAll_clicked();

	void on_Delete_clicked();

	void on_Edit_clicked();

	void on_NewPersonel_clicked();

	void on_SignOut_clicked();

	void on_pushButton_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_3_clicked();

	void on_EditComboName_currentTextChanged(const QString &arg1);

	void on_comboBox_currentTextChanged(const QString &arg1);

	void on_pushButton_10_clicked();

	void on_Register_clicked();

private:
	Ui::AdminForm *ui;

	void setIcons();
	void ClearAllBorders();
	void setNewPlaceholders();
	void Clear();
	void setSearchPlaceholders();
	void setEditPlaceholders();
	void setNewPersonPlaceholders();
	void setForPersonel();
	void setIdentity(QString = "" , QString = "admin");
	void ShowIdentity();
	QString Name;
	QString Family;
	Movie M;
	Personel P;
};

#endif // ADMINFORM_H
