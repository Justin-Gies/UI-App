#include "menu.h"

void add_menu(HWND window){
  main_menu = CreateMenu();

  HMENU file_menu = CreateMenu();
  AppendMenu(file_menu, MF_STRING, FILE_MENU_NEW, "New");
  AppendMenu(file_menu, MF_SEPARATOR,0,NULL);
  AppendMenu(file_menu, MF_STRING, FILE_MENU_OPEN, "Open");
  AppendMenu(file_menu, MF_STRING, FILE_MENU_SAVE, "Save");
  AppendMenu(file_menu, MF_SEPARATOR,0,NULL);
  AppendMenu(file_menu, MF_STRING, FILE_MENU_EXIT, "Exit");
  AppendMenu(main_menu, MF_POPUP, (UINT_PTR)file_menu, "File");


  AppendMenu(main_menu,MF_STRING,2,"Edit");
  AppendMenu(main_menu,MF_STRING,3,"Options");
  AppendMenu(main_menu,MF_STRING,4,"Help");
  SetMenu(window, main_menu);
}
