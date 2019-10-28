#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_entry_activate();
    void on_comboboxtext_activate();

  private:
    Gtk::Entry* entry;
    Gtk::ComboBoxText* comboboxtext;
    Gtk::Label* label;

};

#endif
