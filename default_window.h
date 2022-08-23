#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UI_DEFAULT_WINDOW_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UI_DEFAULT_WINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/textview.h>
#include <gtkmm/window.h>

class DefaultWindow : public Gtk::Window {
private:
  Gtk::Box *box{};
  Gtk::TextView *code_text{};
  Gtk::TextView *IR_text{};
  Gtk::TextView *asm_text{};
  Gtk::TextView *result_text{};
  Gtk::Button *open_file_button{};
  Gtk::Button *clear_button{};
  Gtk::Button *run_button{};

public:
  DefaultWindow();

  ~DefaultWindow() override = default;

  auto on_open_file_button_clicked() -> void;
  auto on_clear_button_clicked() -> void;
  auto on_run_button_clicked() -> void;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UI_DEFAULT_WINDOW_H
