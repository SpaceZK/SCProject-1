#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QMessageBox.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cuttingData = new CuttingData();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cuttingData;
}

void MainWindow::on_btnAddCuttingLength_clicked()
{
    int len = ui->leCuttingLength->text().toInt();
    if(len > 0){
        if(cuttingData->AddCuttingItem(len)){
            QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
            QStyle::StandardPixmap sp = (QStyle::StandardPixmap)(2);

            item->setData(Qt::DecorationRole, qApp->style()->standardPixmap(sp).scaled(QSize(16,16), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
            item->setData(Qt::DisplayRole,QObject::tr("%1 厘米").arg(len));
        }else{
            QMessageBox::information(this, QString("警告"),QString("输入数据已存在,请勿重复输入!"));
        }
    }
    else{
        QMessageBox::information(this, QString("警告"),QString("输入数据有误,请检查!"));
    }
}

void MainWindow::on_btnDelCuttingLength_clicked()
{
    if(ui->listWidget->currentItem() != Q_NULLPTR)
    {
        QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete item;

        QStringList sl = item->text().split(' ');
        int len = ((QString)sl[0]).toInt();

        if(len){
            cuttingData->RemoveCuttingItem(len);
        }
    }
}
