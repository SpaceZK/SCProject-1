#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QList>

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

void MainWindow::on_btnAddCuttingLength_clicked(){
    int len = ui->leCuttingLength->text().toInt();
    if(len > 0){
        if(cuttingData->AddCuttingItem(len)){
            QListWidgetItem *item = new QListWidgetItem();
            QCheckBox *checkBox = new QCheckBox(QString().sprintf("%d 厘米", len));
            checkBox->setCheckable(true);

            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item, checkBox);
        }else{
            QMessageBox::information(this, QString("警告"),QString("输入数据已存在,请勿重复输入!"));
        }
    }
    else{
        QMessageBox::information(this, QString("警告"),QString("输入数据有误,请检查!"));
    }
}

void MainWindow::on_btnDelCuttingLength_clicked(){
    QList<int> qlRemoveItems;
    for (int i = 0; i < ui->listWidget->count(); i++){
        QWidget *widget = ui->listWidget->itemWidget(ui->listWidget->item(i));
        QCheckBox *checkBox = dynamic_cast<QCheckBox *>(widget);
        if(checkBox && checkBox->isChecked()){
            QStringList sl = checkBox->text().split(' ');
            int len = ((QString)sl[0]).toInt();
            if(len){
                cuttingData->RemoveCuttingItem(len);
            }
            qlRemoveItems << i;
        }
    }

    int count = 0;
    foreach(int i, qlRemoveItems){
        QListWidgetItem *item = ui->listWidget->takeItem(i - count);
        delete item;

        count++;
    }
}
