#include "qhoversensitivebutton.h"

QHoverSensitiveButton::QHoverSensitiveButton(QWidget *parent) : QPushButton(parent)
{
	setMouseTracking(true);
	setAttribute(Qt::WA_Hover);
}

void QHoverSensitiveButton::hoverEnter(QHoverEvent *)
{

	this->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgb(4, 36, 30);");
	repaint();
}

void QHoverSensitiveButton::hoverLeave(QHoverEvent *)
{
	if(getCheck () != true)
	{
		this->setStyleSheet ("background-color : #289c8e; border-radius : 1%; font: 15pt \"Calibri\"; color: rgb(255, 255, 255); text-align:left; border-left: 4px solid rgba(4, 36, 30,0);");
		repaint();
	}
}

void QHoverSensitiveButton::hoverMove(QHoverEvent *)
{
}

bool QHoverSensitiveButton::event(QEvent *event)
{
	switch(event->type())
	{
	case QEvent::HoverEnter:
		hoverEnter(static_cast<QHoverEvent*>(event));
		return true;
		break;
	case QEvent::HoverLeave:
		hoverLeave(static_cast<QHoverEvent*>(event));
		return true;
		break;
	case QEvent::HoverMove:

		break;
	default:
		break;
	}
	return QWidget::event(event);
}
