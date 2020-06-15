#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTime>
#include <QThread>
#include "client.h"
#include "handle_request.h"
#include "info_thread.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread getinfothread;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_PbConnect_clicked();

    void on_PbDisConnect_clicked();

    void Disconnected();

    void display_recv();

    void set_tables(uint8_t mode);

    void on_toolFormat_clicked();

    void on_PbReset_clicked();

    void on_toolUpdate_clicked();

    void on_toolSelfDest_clicked();

    void on_toolSelfDest_2_clicked();

    void client_getver();

    void client_gettemp();
private:
    Ui::MainWindow *ui;
    QString ip;
    int port;
    int rowcount;
    QDateTime time;
    class handle_request handle;
    client tcp_Client;
    class thread_getinfo *m_thread;
    info_thread *get_info;
signals:
    void operate();
};

#endif // MAINWINDOW_H
