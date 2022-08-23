#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UI_DEFAULT_WINDOW_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UI_DEFAULT_WINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/window.h>

class DefaultWindow : public Gtk::Window {
private:
  Gtk::Box *box;

public:
  DefaultWindow();

  ~DefaultWindow() override = default;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UI_DEFAULT_WINDOW_H
