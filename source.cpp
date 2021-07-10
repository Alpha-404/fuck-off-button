#include <Windows.h>
#include <iostream>

int minimise() {
    if (!GetConsoleWindow())
        AllocConsole();
    HMENU menu = GetSystemMenu(GetConsoleWindow(), FALSE);
    EnableMenuItem(menu, SC_CLOSE, MF_GRAYED);

    ShowWindow(GetConsoleWindow(), false ? SW_SHOWNORMAL : SW_HIDE);

    return 0;
}

void SendInput2(UINT button, int delay)
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKeyA(button, 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(delay);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

bool isRunning(LPCSTR pName)
{
    HWND hwnd;
    hwnd = FindWindow(NULL, pName);
    if (hwnd != 0) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    if (isRunning("the fuck off button"))
    {
        MessageBox(0, "Already Running", "fuck off button", 0);
        return 0;
    }
    SetConsoleTitleA("the fuck off button");
    printf("fuck off button loaded");
    printf("\npress - to tell sombody to fuck off");
    printf("\nclosing menu in 5 secs");
    Sleep(5000);
    minimise();
    while(true)
    {
        if (GetAsyncKeyState(VK_OEM_MINUS)) //-
        {
            SendInput2(VK_BACK, 10);
            SendInput2(0x46, 10);
            SendInput2(0x55, 10);
            SendInput2(0x43, 10);
            SendInput2(0x4B, 10);
            SendInput2(VK_SPACE, 10);
            SendInput2(0x4F, 10);
            SendInput2(0x46, 10);
            SendInput2(0x46, 10);
            Sleep(500);
        }
    }
}
