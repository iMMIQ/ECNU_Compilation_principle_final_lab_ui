#include <gtkmm/main.h>

#include "default_window.h"

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "top.immiq.lab");
  DefaultWindow window;
  return app->run(window);
}