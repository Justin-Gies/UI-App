
#include "window.h"
#include "menu.h"

LRESULT CALLBACK WindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
  switch (message) {
    case WM_COMMAND:
      switch(wParam){
        case FILE_MENU_EXIT:
          DestroyWindow(window);
          break;
        case FILE_MENU_NEW:
          MessageBeep(MB_OK);
          break;
        case FILE_MENU_SAVE:
          MessageBeep(MB_OK);
          break;
        case FILE_MENU_OPEN:
          MessageBeep(MB_OK);
          break;
        default:
          break;
      }
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    
    case WM_CREATE:
      add_menu(window);
      break;

    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(window, &ps);

      FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
      EndPaint(window, &ps);
      return 0;
    }
    default:
      return DefWindowProcW(window, message, wParam, lParam);
  }
  return 0;
}