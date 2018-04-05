#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddCuttingLength_clicked()
{
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    QStyle::StandardPixmap sp = (QStyle::StandardPixmap)(2);

    item->setData(Qt::DecorationRole, qApp->style()->standardPixmap(sp).scaled(QSize(16,16), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
    item->setData(Qt::DisplayRole,QObject::tr("%1 厘米").arg(ui->leCuttingLength->text().toInt()));
}

void MainWindow::on_btnDelCuttingLength_clicked()
{
    if(ui->listWidget->currentItem() != Q_NULLPTR)
    {
        QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete item;
    }
}
