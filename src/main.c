#ifndef UNICODE
#define UNICODE
#endif

#define WM_LBUTTONDOWN 0x0201

#include <stdint.h>
#include <stdbool.h>

#include "resources.h"
#include "window.h"


int WINAPI wWinMain(HINSTANCE instance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  int posx = 300;
  int posy = 200;
  int width = 1024;
  int height = 768;
  
  // Register the window class.
  const wchar_t CLASS_NAME[] = L"Test App";

  WNDCLASSEX wc = {0};
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.hIcon = LoadIcon(instance, MAKEINTRESOURCE(IDI_ICON1));
  wc.hIconSm = LoadIcon(instance, MAKEINTRESOURCE(IDI_ICON1));
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = instance;
  wc.lpszClassName = CLASS_NAME;
  wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);

  if(!RegisterClassExW(&wc))
    return -1;

  /* Create the window. */

  HWND hwnd =
      CreateWindowEx(0,                                                                 // Optional window styles.
                     CLASS_NAME,                                                        // Window class
                     L"Test App",                                                       // Window text
                     WS_OVERLAPPEDWINDOW,                                               // Window style
                     posx,                                                              // X Position
                     posy,                                                              // Y Position
                     width,                                                             // Window Width
                     height,                                                            // Window Height
                     NULL,                                                              // Parent window
                     NULL,                                                              // Menu
                     instance,                                                          // Instance handle
                     NULL                                                               // Additional application data
      );

  if (hwnd == NULL) {
    return 0;
  }

  ShowWindow(hwnd, nCmdShow); 

  // Run the message loop.

  MSG msg = {0};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  
  return 0;
}

