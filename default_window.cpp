#include "default_window.h"

#include <fstream>
#include <gtkmm/builder.h>
#include <iostream>

DefaultWindow::DefaultWindow() {
  set_size_request(1200, 800);

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

auto DefaultWindow::on_open_file_button_clicked() -> void {
  Gtk::FileChooserDialog dialog("选择文件", Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  dialog.add_button("取消", Gtk::RESPONSE_CANCEL);
  dialog.add_button("打开", Gtk::RESPONSE_OK);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Code");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  if (dialog.run() == Gtk::RESPONSE_OK) {
    std::string path = dialog.get_filename();
    code_text->get_buffer()->set_text(get_file_text(path));
  }
}

auto DefaultWindow::on_clear_button_clicked() -> void {
  code_text->get_buffer()->set_text("");
  IR_text->get_buffer()->set_text("");
  asm_text->get_buffer()->set_text("");
  result_text->get_buffer()->set_text("");
}

auto DefaultWindow::on_run_button_clicked() -> void {
  std::ofstream os("code.txt", std::ios::out);
  os << code_text->get_buffer()->get_text() << std::endl;
  if (!system("./compiler -c code.txt -o code.ll -S")) {
    IR_text->get_buffer()->set_text(get_file_text("code.ll"));
    system("./compiler -c code.txt -o code.s -s");
    asm_text->get_buffer()->set_text(get_file_text("code.s"));
    system("./compiler -c code.txt -o code -O && ./code > result.txt");
    result_text->get_buffer()->set_text(get_file_text("result.txt"));
  } else {
    // TODO: 错误流处理
  }
}

auto DefaultWindow::get_file_text(const std::string &path)
    -> std::string const {
  if (std::ifstream is{path, std::ios::binary | std::ios::ate}) {
    auto size = is.tellg();
    std::string str(size, '\0');
    is.seekg(0);
    if (is.read(&str[0], size)) {
      return str;
    }
  }
}
