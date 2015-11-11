/*
 * main.cpp - implement a command tool for testing u-blox gps chipset.
 */
#include "ubx_serial.h"
#include "ubx_log.h"
#include <unistd.h>

void usage() {
    char* help_str = \
        "gpscli - u-blox command line test tool\n"      \
        "usage:\n"                                      \
        "    gpscli -iSerial_path|-h\n"                 \
        "    \n"                                        \
        "    -h show this help information.\n"          \
        "    Serial_path u-blox gps chipset serial path.\n";
    UBX_LOG(LCAT_INFO, help_str);
}
int main(int argc, char* argv[]) {
    if (argc != 2 || (argv[1][0] != '-') || (argv[1][1] != 'i')) {
        usage();
        return 0;
    }

    char* serial_path = argv[1] + 2;
    UBX_LOG(LCAT_ERROR, "ublox gps serial path is %s\n", serial_path);
    int pfd[2] = {-1, -1};
    bool isQuit = false;
    char inCommand[64] = "\0";

    //init work thread.
    if (pipe(pfd) != 0) {
        UBX_LOG(LCAT_ERROR, "open pipe failed\n");
        return -1;
    }


    //get user input command, and send to work thread.
    while (!isQuit) {
        std::cout << ">>";
        std::cin >> inCommand;
    }
    CSerialPort port;
    if (port.openSerial("/dev/ttyACM0", 115200, 1)) {
        UBX_LOG(LCAT_ERROR, "open /dev/ttyACM0 success");
    } else {
        UBX_LOG(LCAT_ERROR, "failed!\n");
    }
    return 0;
}
