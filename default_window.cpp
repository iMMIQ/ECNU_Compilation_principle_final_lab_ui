#include "default_window.h"

#include <gtkmm/builder.h>

DefaultWindow::DefaultWindow() {
  auto builder = Gtk::Builder::create_from_file("ui.glade");
  builder->get_widget("Box", box);
  builder->get_widget("code_text", code_text);
  builder->get_widget("IR_text", IR_text);
  builder->get_widget("asm_text", asm_text);
  builder->get_widget("result_text", result_text);
  builder->get_widget("open_file_button", open_file_button);
  builder->get_widget("clear_button", clear_button);
  builder->get_widget("run_button", run_button);
  open_file_button->signal_clicked().connect(
      sigc::mem_fun(*this, &DefaultWindow::on_open_file_button_clicked));
  clear_button->signal_clicked().connect(
      sigc::mem_fun(*this, &DefaultWindow::on_clear_button_clicked));
  run_button->signal_clicked().connect(
      sigc::mem_fun(*this, &DefaultWindow::on_run_button_clicked));
  add(*box);
}

auto DefaultWindow::on_open_file_button_clicked() -> void {}

auto DefaultWindow::on_clear_button_clicked() -> void {
  Glib::RefPtr<Gtk::TextBuffer> void_buffer;
  code_text->set_buffer(void_buffer);
  IR_text->set_buffer(void_buffer);
  asm_text->set_buffer(void_buffer);
  result_text->set_buffer(void_buffer);
}

auto DefaultWindow::on_run_button_clicked() -> void {}
