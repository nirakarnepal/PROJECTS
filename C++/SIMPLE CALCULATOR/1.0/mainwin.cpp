#include "mainwin.h"
#include <cmath>
// CONSTRUCTOR
Mainwin::Mainwin()


  : 
    entry{Gtk::manage(new Gtk::Entry{})},
    comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})},
    label{Gtk::manage(new Gtk::Label{"This Label displays the vlaue of above operations"})}

{
// SETTING THE TITLE OF WINDOW
    set_title("SLT CALCULATOR");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // This is where we add the vbox

    vbox->pack_start(*entry);
    entry->set_text("Enter your number (0-100)");
    entry->signal_activate().connect([this]{this->on_comboboxtext_activate();});


 
// THE USE OF COMBOBOX
    vbox->pack_start(*comboboxtext);
    comboboxtext->append("Square root");
    comboboxtext->append("Natural logarithm (base e)");
    comboboxtext->append("Trigonometric cosine");
    comboboxtext->set_active(1);
    comboboxtext->signal_changed().connect([this]{this->on_comboboxtext_activate();});
//DISPLAY RESULT
    vbox->pack_start(*label);


    vbox->show_all();
}
// DESTRUCTOR
Mainwin::~Mainwin() { }


//FUNCTIONS
void Mainwin::on_entry_activate() {
    Gtk::MessageDialog{*this, entry->get_text()}.run();
}

void Mainwin::on_comboboxtext_activate() {
// STRING TO DOUBLE CONVERTION
    double a = atof(entry->get_text().c_str());
    if(comboboxtext->get_active_row_number()==0)
      {

         a = pow(a,0.5);

       }
     else if(comboboxtext->get_active_row_number()==1)

      {
           a = log(a);
       }
      else if(comboboxtext->get_active_row_number()==2)

      {
           a = cos(a);
       }


    label->set_text(std::to_string(a));
}




