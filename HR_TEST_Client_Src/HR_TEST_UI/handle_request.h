#ifndef HANDLE_REQUEST_H
#define HANDLE_REQUEST_H

#include <QObject>
#include <QString>
#include <QDebug>
class handle_request : public QObject
{
    Q_OBJECT
public:
    explicit handle_request(QObject *parent = nullptr);

    uint8_t fft_passed    = 0x01;
    uint8_t fft_nopassed  = 0x02;
    uint8_t cdma_passed   = 0x03;
    uint8_t cdma_nopassed = 0x04;
    uint8_t srio_passed   = 0x05;
    uint8_t srio_nopassed = 0x06;
    uint8_t base_passed   = 0x07;
    uint8_t base_nopassed = 0x08;
    uint8_t all_passed    = 0x09;
    uint8_t all_nopassed  = 0x0a;
    uint8_t temp          = 0x0b;
    uint8_t version       = 0x0c;
signals:

public slots:
     uint8_t handle_result(QString result);
};

#endif // HANDLE_REQUEST_H
