#include <Windows.h>

int main() {
    HKEY hKey;
    DWORD dwValue = 1;

    // Вимкнення контекстного меню Панелі завдань
    RegOpenKeyEx(HKEY_LOCAL_MACHINE,
        TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"),
        0,
        KEY_SET_VALUE,
        &hKey);

    RegSetValueEx(hKey, TEXT("NoTrayContextMenu"), 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));

    RegCloseKey(hKey);

    // Вимкнення контекстного меню Провідника файлів
    RegOpenKeyEx(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"),
        0,
        KEY_SET_VALUE,
        &hKey);

    RegSetValueEx(hKey, TEXT("NoViewContextMenu"), 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));

    RegCloseKey(hKey);

    return 0;
}