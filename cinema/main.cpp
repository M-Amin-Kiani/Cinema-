#include "starter_page.h"
#include <selectuser.h>
#include <QApplication>
#include <windows.h>
#include <iostream>
#include <chrono>
#include <time.h>
#include <customer.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	starter_page w;
	w.HideLoading ();
	w.show();
	w.SplashEffect ();
	w.ShowLoading ();
	w.delay(7);
//#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#//
	SelectUser *F = new SelectUser;
	F->Show (7);


    return a.exec();
}
