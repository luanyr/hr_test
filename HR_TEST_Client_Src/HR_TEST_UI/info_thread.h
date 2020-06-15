#ifndef INFO_THREAD_H
#define INFO_THREAD_H

#include <QObject>
#include <windows.h>

#include <QTime>
#include <QCoreApplication>
class info_thread : public QObject
{
    Q_OBJECT
public:
    explicit info_thread(QObject *parent = nullptr);

public slots:
    void dowork();
signals:
    void get_ver_signal();
    void get_temp_signal();
protected:
    void Mysleep(UINT32 usec){
        QTime reachtime = QTime::currentTime().addMSecs(usec);
        while(QTime::currentTime() < reachtime)
            QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
};

#endif // INFO_THREAD_H
