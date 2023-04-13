#ifndef QHOVERSENSITIVEBUTTON_H
#define QHOVERSENSITIVEBUTTON_H

#include <QtWidgets>

class QHoverSensitiveButton : public QPushButton
{
	Q_OBJECT
public:
	explicit QHoverSensitiveButton(QWidget *parent = 0);

	void setCheck(bool x)
	{
		check = x;
	}
	bool getCheck()
	{
		return check;
	}

protected:
	void hoverEnter(QHoverEvent *event);
	void hoverLeave(QHoverEvent *event);
	void hoverMove(QHoverEvent *event);
	bool event(QEvent *event);

private:
	bool check;

signals:

public slots:
};

#endif // QHOVERSENSITIVEBUTTON_H
