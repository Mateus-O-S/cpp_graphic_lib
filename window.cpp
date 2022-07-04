#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int Wmain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR args, int ncmd){
        WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)10;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpszClassName = L"myWIN";
    wc.lpfnWndProc = WindowProcedure;


    if (!RegisterClassW(&wc)){
        return -1;
    }

    CreateWindowW(L"myWIN", L"window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while(GetMessage(&msg, 0, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}