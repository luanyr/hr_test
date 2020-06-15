#include "handle_request.h"

handle_request::handle_request(QObject *parent) : QObject(parent)
{

}

uint8_t handle_request::handle_result(QString result)
{
    char compare_result;

    if (result.contains("FFT", Qt::CaseSensitive) == true) {
        compare_result = result.compare("FFT TEST PASSED", Qt::CaseSensitive);
        if(compare_result == 0)
            return fft_passed;
        else
            return fft_nopassed;
    } else if (result.contains("CDMA", Qt::CaseSensitive) == true) {
        compare_result = result.compare("CDMA TEST PASSED",Qt::CaseSensitive);
        if(compare_result == 0)
            return cdma_passed;
        else
            return cdma_nopassed;
    } else if (result.contains("SRIO", Qt::CaseSensitive) == true) {
        compare_result = result.compare("SRIO TEST PASSED", Qt::CaseSensitive);
        if(compare_result == 0)
            return srio_passed;
        else
            return srio_nopassed;
    } else if (result.contains("BASE", Qt::CaseSensitive) == true) {
        compare_result = result.compare("BASE TEST PASSED", Qt::CaseSensitive);
        if(compare_result == 0)
            return base_passed;
        else
            return base_nopassed;
    } else if (result.contains("ALL", Qt::CaseSensitive) == true) {
        compare_result = result.compare("ALL TEST PASSED", Qt::CaseSensitive);
        if(compare_result == 0)
            return all_passed;
        else
            return all_nopassed;
    }else if (result.contains("temp",Qt::CaseSensitive) == true) {
        return temp;
    } else if(result.contains("ver", Qt::CaseSensitive) == true) {
        return  version;
    }

    return 0;
}
