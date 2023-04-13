#ifndef MESSAGE_H
#define MESSAGE_H

#include <QMainWindow>

namespace Ui {
class Message;
}

class Message : public QMainWindow
{
	Q_OBJECT

public:
	explicit Message(QWidget *parent = nullptr);
	~Message();

	void setText(QString Text);

private slots:
	void on_pushButton_3_clicked();

private:
	Ui::Message *ui;
};

#endif // MESSAGE_H
