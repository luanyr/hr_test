#include "info_thread.h"

info_thread::info_thread(QObject *parent) : QObject(parent)
{

}

void info_thread::dowork()
{
    while(1){
     emit get_temp_signal();
     Mysleep(100);
     emit get_ver_signal();
     Mysleep(100);
    }
}

