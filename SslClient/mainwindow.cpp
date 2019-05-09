#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (QSslSocket::supportsSsl())
    {
      ui->pushButton_connect->setEnabled(true);
    }
    else
    {
      QString noSslMsg = QString("%1\n%2")
          .arg("*** Your version of Qt does support SSL ***")
          .arg("You must obtain a version of Qt that has SSL"
               "support enabled.  If you believe that your "
               "version of Qt has SSL support enabeld, you may "
               "need to install the OpenSSL run-time libraries.");

      ui->textEdit_messages->setText(noSslMsg);
    }
    // QSslSocket emits the encrypted() signal after the encrypted connection is established
   // connect(&socket, SIGNAL(encrypted()), this, SLOT(connectedToServer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
