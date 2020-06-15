#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->set_tables(1);
    get_info = new info_thread;
    get_info->moveToThread(&getinfothread);
    connect(&getinfothread, &QThread::finished, get_info, &QObject::deleteLater);
    connect(this, &MainWindow::operate, get_info, &info_thread::dowork);
    connect(&tcp_Client, SIGNAL(disconnect_signal(bool)), this, SLOT(Disconnected()));
    connect(&tcp_Client, SIGNAL(read_signal()), this, SLOT(display_recv()));
    connect(get_info, &info_thread::get_ver_signal, this, &MainWindow::client_getver);
    connect(get_info, &info_thread::get_temp_signal, this, &MainWindow::client_gettemp);
    getinfothread.start();
}

MainWindow::~MainWindow()
{
    getinfothread.quit();
    getinfothread.wait();
    delete ui;
}

void MainWindow::set_tables(uint8_t mode)
{
    if( mode == 1)
    {
        ui->tableStatus_2->insertColumn(0);
        ui->tableStatus_2->insertColumn(1);
        ui->tableStatus_2->verticalHeader()->setVisible(false);//去表头
        ui->tableStatus_2->horizontalHeader()->setVisible(false);
        ui->tableStatus_2->setShowGrid(false);//去网格线
    }
    ui->tableStatus->setRowCount(7);
    ui->tableStatus->setColumnCount(2);
    ui->tableStatus->setColumnWidth(0,100);
    ui->tableStatus->setColumnWidth(1,150);
    ui->tableStatus->verticalHeader()->setVisible(false);
    ui->tableStatus->setShowGrid(false);//去网格线
    QStringList header;
    header << "测试项目" << "测试结果";
    ui->tableStatus->setHorizontalHeaderLabels(header);
    ui->tableStatus->setItem(0, 0, new QTableWidgetItem("FFT测试"));
    ui->tableStatus->setItem(0, 1, new QTableWidgetItem("尚未测试"));
    ui->tableStatus->setItem(1, 0, new QTableWidgetItem("CDMA测试"));
    ui->tableStatus->setItem(1, 1, new QTableWidgetItem("尚未测试"));
    ui->tableStatus->setItem(2, 0, new QTableWidgetItem("SRIO测试"));
    ui->tableStatus->setItem(2, 1, new QTableWidgetItem("尚未测试"));
    ui->tableStatus->setItem(3, 0, new QTableWidgetItem("基础测试"));
    ui->tableStatus->setItem(3, 1, new QTableWidgetItem("尚未测试"));
    ui->tableStatus->setItem(4, 0, new QTableWidgetItem("ALL测试"));
    ui->tableStatus->setItem(4, 1, new QTableWidgetItem("尚未测试"));
    ui->tableStatus->setItem(5, 0, new QTableWidgetItem("温度"));
    ui->tableStatus->setItem(5, 1, new QTableWidgetItem("未得到温度"));
    ui->tableStatus->setItem(6, 0, new QTableWidgetItem("版本"));
    ui->tableStatus->setItem(6, 1, new QTableWidgetItem("未得到版本"));
}

void MainWindow::Disconnected()
{
     time = QDateTime::currentDateTime();
     rowcount = ui->tableStatus_2->rowCount();
     ui->tableStatus_2->insertRow(rowcount);
     ui->tableStatus_2->setItem(rowcount,0,new QTableWidgetItem(time.toString("hh:mm:ss")));
     ui->tableStatus_2->setItem(rowcount,1,new QTableWidgetItem("[INFO]:断开连接"));
     ui->PbConnect->setEnabled(true);
}

void MainWindow::on_PbConnect_clicked()
{
    if((ui->TcpAddrEdit->text().isEmpty() == 1) || (ui->TcpPortEdit->text().isEmpty() == 1))
    {
      QMessageBox::warning(this, "WARNING","缺少IP地址或端口");
    } else {
      ip = ui->TcpAddrEdit->text();
      port = ui->TcpPortEdit->text().toInt();
      time = QDateTime::currentDateTime();
      rowcount = ui->tableStatus_2->rowCount();
      ui->tableStatus_2->insertRow(rowcount);
      ui->tableStatus_2->setItem(rowcount, 0, new QTableWidgetItem(time.toString("hh:mm:ss")));
      if(tcp_Client.client_connect(ip,port) == true)
      {
           ui->tableStatus_2->setItem(rowcount, 1, new QTableWidgetItem("[INFO]:连接成功"));
           ui->PbConnect->setDisabled(true);
           ui->PbDisConnect->setEnabled(true);
           get_info->dowork();
      } else {
          ui->tableStatus_2->setItem(rowcount, 1, new QTableWidgetItem("[INFO]:连接失败"));
      }
    }
}

void MainWindow::on_PbDisConnect_clicked()
{
    if(tcp_Client.get_client_sta() == true)
    {
        tcp_Client.client_disconnect();
        set_tables(0);
    }
    else
        QMessageBox::warning(this, "WARNING","尚未连接");
}

void MainWindow::display_recv()
{
    uint8_t test_result;
    QTableWidgetItem *item_passed = new QTableWidgetItem("测试通过");
    item_passed->setBackground(QColor(0 ,205, 0));
    QTableWidgetItem *item_nopassed = new QTableWidgetItem("测试未通过");
    item_nopassed->setBackground(QColor( 205 ,0, 0));
    QString str_rec = tcp_Client.client_read();
    if(str_rec.contains("temp", Qt::CaseSensitive) == true || str_rec.contains("ver", Qt::CaseSensitive) == true) {
    } else {
        time = QDateTime::currentDateTime();
        rowcount = ui->tableStatus_2->rowCount();
        ui->tableStatus_2->insertRow(rowcount);
        ui->tableStatus_2->setItem(rowcount, 0, new QTableWidgetItem(time.toString("hh:mm:ss")));
        ui->tableStatus_2->setItem(rowcount, 1, new QTableWidgetItem(str_rec));
    }
    test_result = handle.handle_result(str_rec);
    if (test_result == handle.fft_passed) {
        ui->tableStatus->setItem(0, 1, item_passed);
    } else if (test_result == handle.fft_nopassed) {
        ui->tableStatus->setItem(0, 1, item_nopassed);
    } else if (test_result == handle.cdma_passed) {
        ui->tableStatus->setItem(1, 1, item_passed);
    } else if (test_result == handle.cdma_nopassed) {
        ui->tableStatus->setItem(1, 1, item_nopassed);
    } else if (test_result == handle.srio_passed) {
        ui->tableStatus->setItem(2, 1, item_passed);
    } else if (test_result == handle.srio_nopassed) {
        ui->tableStatus->setItem(2, 1, item_nopassed);
    } else if (test_result == handle.base_passed) {
        ui->tableStatus->setItem(3, 1, item_passed);
    } else if (test_result == handle.base_nopassed) {
        ui->tableStatus->setItem(3, 1, item_nopassed);
    } else if (test_result == handle.all_passed) {
        ui->tableStatus->setItem(4, 1, item_passed);
    } else if (test_result == handle.all_nopassed) {
        ui->tableStatus->setItem(4, 1, item_nopassed);
    } else if (test_result == handle.temp) {
        str_rec = str_rec.right(2);
        str_rec = str_rec + "°C";
        ui->tableStatus->setItem(5, 1, new QTableWidgetItem(str_rec));
    } else if(test_result == handle.version) {
        str_rec = str_rec.right(12);
        ui->tableStatus->setItem(6, 1, new QTableWidgetItem(str_rec));
    }
}



void MainWindow::on_toolFormat_clicked()
{
    if(tcp_Client.get_client_sta() == true)
    {
        QByteArray ba_send;
        ba_send = QString("FFT").toLatin1();
        tcp_Client.client_send(ba_send);
        ui->tableStatus->setItem(0, 1, new QTableWidgetItem("测试中"));
    } else
        QMessageBox::warning(this, "WARNING", "尚未连接");
}

void MainWindow::on_PbReset_clicked()
{
    if( tcp_Client.get_client_sta() == true )
    {
        QByteArray ba_send;
        ba_send = QString("CDMA").toLatin1();
        tcp_Client.client_send(ba_send);
        ui->tableStatus->setItem(1, 1, new QTableWidgetItem("测试中"));
    } else
        QMessageBox::warning(this, "WARNING", "尚未连接");
}



void MainWindow::on_toolUpdate_clicked()
{
    if( tcp_Client.get_client_sta() == true )
    {
        QByteArray ba_send;
        ba_send = QString("SRIO").toLatin1();
        tcp_Client.client_send(ba_send);
        ui->tableStatus->setItem(2, 1, new QTableWidgetItem("测试中"));
    } else
        QMessageBox::warning(this, "WARNING", "尚未连接");
}

void MainWindow::on_toolSelfDest_clicked()
{
    if( tcp_Client.get_client_sta() == true )
    {
        QByteArray ba_send;
        ba_send = QString("BASE").toLatin1();
        tcp_Client.client_send(ba_send);
        ui->tableStatus->setItem(3, 1, new QTableWidgetItem("测试中"));
    } else
        QMessageBox::warning(this, "WARNING", "尚未连接");
}



void MainWindow::on_toolSelfDest_2_clicked()
{
    if( tcp_Client.get_client_sta() == true )
    {
        QByteArray ba_send;
        ba_send = QString("ALL").toLatin1();
        tcp_Client.client_send(ba_send);
        ui->tableStatus->setItem(4, 1, new QTableWidgetItem("测试中"));
    } else {
        QMessageBox::warning(this, "WARNING", "尚未连接");
    }
}

void MainWindow::client_getver()
{
    QByteArray ba_send;
    ba_send = QString("version").toLatin1();
    tcp_Client.client_send(ba_send);
}

void MainWindow::client_gettemp()
{
    QByteArray ba_send;
    ba_send = QString("tempture").toLatin1();
    tcp_Client.client_send(ba_send);
}
