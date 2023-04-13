#ifndef EXITMSG_H
#define EXITMSG_H

#include <QMainWindow>

namespace Ui {
class ExitMsg;
}

class ExitMsg : public QMainWindow
{
	Q_OBJECT

public:
	explicit ExitMsg(QWidget *parent = nullptr);
	~ExitMsg();

private slots:
	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

private:
	Ui::ExitMsg *ui;
};

#endif // EXITMSG_H
