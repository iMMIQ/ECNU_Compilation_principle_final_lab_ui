#include "default_window.h"

#include <gtkmm/builder.h>

DefaultWindow::DefaultWindow() {
  auto builder = Gtk::Builder::create_from_file("ui.glade");
  builder->get_widget("Box", box);
  add(*box);
}
