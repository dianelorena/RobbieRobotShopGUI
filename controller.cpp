/*
    Robbie Robot Shop v1.0 beta, (c) 2016 by Professor George F. Rice.

    This file is part of Robbie Robot Shop (RRS), an example solution
    to Project #5 for UTA CSE 1325. 

    Permission is expressly DENIED to students in this class to include
    ANY of this code in a submitted Homework #5 solution during any semester 
    of this class. This restriction supercedes the license granted below,
    and use of this code for Homework #5 will be deemed an Honor Code Violation 
    regardless of disclosure.
    
    Permission is expressly GRANTED to students in this class to include
    this code, or any derivatives thereof, in Project #6 of the same class,
    providing that this header is not removed.
    
    RRS is otherwise free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    RRS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with RRS.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "controller.h"
#include <iostream>
#include <string>
#include <climits>
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/FL_Group.H"
#include "FL/Fl_Menu_Bar.H"
#include "FL/Fl_Menu_Item.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Radio_Button.H"



using namespace std;


void Controller::main_menu() {
  cout << endl;
  cout << "========================" << endl
       << shop.name() << endl
       << "========================" << endl;
  cout << MENU_LIST_ORDERS << ") List orders" << endl;
  cout << MENU_CREATE_ORDER << ") Create new order" << endl;
  cout << endl;
  cout << "People" << endl;
  cout << "------" << endl;
  cout << MENU_LIST_PEOPLE << ") List Customers and Sales Associates" << endl;
  cout << MENU_CREATE_CUSTOMER << ") Create new customer" << endl;
  cout << MENU_CREATE_SA << ") Create new sales associate" << endl;
  cout << endl;
  cout << "Robot Models" << endl;
  cout << "------------" << endl;
  cout << MENU_LIST_MODELS << ") List robot models" << endl;
  cout << MENU_CREATE_MODEL << ") Create new robot model" << endl;
  cout << endl;
  cout << "Robot Parts" << endl;
  cout << "-----------" << endl;
  cout << MENU_LIST_PARTS << ") List robot parts" << endl;
  cout << MENU_CREATE_TORSO << ") Create new torso" << endl;
  cout << MENU_CREATE_ARM << ") Create new arm" << endl;
  cout << MENU_CREATE_HEAD << ") Create new head" << endl;
  cout << MENU_CREATE_LOCOMOTOR << ") Create new locomotor" << endl;
  cout << MENU_CREATE_BATTERY << ") Create new battery" << endl;
  cout << endl;
  cout << "Miscellaneous" << endl;
  cout << "-------------" << endl;
  cout << MENU_SHOW_MENU << ") Menu" << endl;
  cout << MENU_EXIT << ") Exit" << endl;
  cout << endl;
} 

string Controller::get_string(string prompt) {
    cout << prompt << " ";
    string s;
    getline(cin, s);
    return s;
}

int Controller::get_int(string prompt) {
    string s = get_string(prompt);
    return atoi(s.c_str());
}

double Controller::get_double(string prompt) {
    string s = get_string(prompt);
    return atof(s.c_str());
}

Customer& Controller::get_customer(string prompt) {
    for (int i=0; i < shop.customers().size(); ++i) {
        cout << i << ") " << shop.customers()[i] << endl;
    }
    cout << endl;
    return shop.customers()[get_int(prompt)];
}

Sales_associate& Controller::get_sa(string prompt) {
    for (int i=0; i < shop.sales_associates().size(); ++i) {
        cout << i << ") " << shop.sales_associates()[i] << endl;
    }
    cout << endl;
    return shop.sales_associates()[get_int(prompt)];
}


Robot_model& Controller::get_model(string prompt) {
    for (int i=0; i < shop.models().size(); ++i) {
        cout << i << ") " << shop.models()[i] << endl;
    }
    cout << endl;
    return shop.models()[get_int(prompt)];
}

Torso& Controller::get_torso(string prompt) 
{
    for (int i=0; i < shop.torsos().size(); ++i) 
    {
        cout << i << ") " << shop.torsos()[i] << endl;
    }
    cout << endl;
    return shop.torsos()[get_int(prompt)];
}

Arm& Controller::get_arm(string prompt) {
    for (int i=0; i < shop.arms().size(); ++i) {
        cout << i << ") " << shop.arms()[i] << endl;
    }
    cout << endl;
    return shop.arms()[get_int(prompt)];
}

Head& Controller::get_head(string prompt) {
    for (int i=0; i < shop.heads().size(); ++i) {
        cout << i << ") " << shop.heads()[i] << endl;
    }
    cout << endl;
    return shop.heads()[get_int(prompt)];
}

Locomotor& Controller::get_locomotor(string prompt) {
    for (int i=0; i < shop.locomotors().size(); ++i) {
        cout << i << ") " << shop.locomotors()[i] << endl;
    }
    cout << endl;
    return shop.locomotors()[get_int(prompt)];
}

Battery& Controller::get_battery(string prompt) {
    for (int i=0; i < shop.batteries().size(); ++i) {
        cout << i << ") " << shop.batteries()[i] << endl;
    }
    cout << endl;
    return shop.batteries()[get_int(prompt)];
}

void Controller::cli() {
  int cmd = 0;
  main_menu();
  while (cmd != MENU_EXIT) {
    cmd = get_int("Command (" + to_string(MENU_SHOW_MENU) + " for menu, "
                              + to_string(MENU_EXIT) + " to exit)? ");
    execute_cmd(cmd);
  }
}
////////////////////////////////////////////////////////////GUI CODE////////////////////////////////////////////////////////////////////
int Controller::gui() 
{

    //widgets
    Fl_Window *window = new Fl_Window(300,180, "Robbie Robot Shop");
    Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0,0,640,30);
    


    menubar->add("File/Quit", FL_CTRL+'q', quit_CB);
    menubar->add("Create/Order");
    menubar->add("Create/Customer");
    menubar->add("Create/Sales Associate");
    menubar->add("Create/Robot Model");
    menubar->add("Create/Robot Part", FL_CTRL+'c', show_robot_part_form_CB);
    menubar->add("View/Orders");
    menubar->add("View/People");
    menubar->add("View/Robot Model");
    menubar->add("View/Robot Part");
    menubar->add("Help/Manual");
    
    window->end();
    window->show();
    return Fl::run();
}

void Controller::quit_CB(Fl_Widget *w, void *p) 
{
    exit(0);
}

void Controller::buttonHeadPushed(Fl_Widget* w, void* p)
{
    //printf("%s says:", (char*)p);
    if (((Fl_Radio_Button*)w)->value())
        printf("Head\n");
}

void Controller::buttonTorsoPushed(Fl_Widget* w, void* p)
{
    //printf("%s says:", (char*)p);
    if (((Fl_Radio_Button*)w)->value())
        printf("Torso\n");
}



void Controller::show_robot_part_form_CB(Fl_Widget *w, void *p) {
    Fl_Window *robot_part_create = new Fl_Window(340, 430, "New Robot Part");

    Fl_Input *rp_name = new Fl_Input(120, 10, 210, 25, "Name");
    rp_name->align(FL_ALIGN_LEFT);

    Fl_Input *rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
    rp_part_number->align(FL_ALIGN_LEFT);

    Fl_Input *rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
    rp_type->align(FL_ALIGN_LEFT);


    Fl_Radio_Button *radioButtonHead = new Fl_Radio_Button(120,100,210,25, "Head");
    radioButtonHead->when(FL_WHEN_RELEASE);
    radioButtonHead->callback(buttonHeadPushed);
    Fl_Radio_Button *radioButtonTorso = new Fl_Radio_Button(120,130,210,25, "Torso");
    radioButtonTorso->when(FL_WHEN_RELEASE);
    radioButtonTorso->callback(buttonTorsoPushed);
    Fl_Radio_Button *radioButtonArm = new Fl_Radio_Button(120,160,210,25, "Arm");
    Fl_Radio_Button *radioButtonLocomotor= new Fl_Radio_Button(120,190,210,25, "Locomotor");
    Fl_Radio_Button *radioButtonBattery = new Fl_Radio_Button(120,220,210,25, "Battery");


    Fl_Input *rp_weight = new Fl_Input(120, 250, 210, 25, "Weight:");
    rp_weight->align(FL_ALIGN_LEFT);

    Fl_Input *rp_cost = new Fl_Input(120, 280, 210, 25, "Cost:");
    rp_cost->align(FL_ALIGN_LEFT);

    Fl_Input *rp_description = new Fl_Multiline_Input(120, 310, 210, 75, "Description:");
    rp_description->align(FL_ALIGN_LEFT);

    Fl_Button *rp_create_button = new Fl_Return_Button(145, 400, 120, 25, "Create");
    rp_create_button->callback((Fl_Callback *)create_robot_part_CB, 0);

    Fl_Button *rp_cancel_button = new Fl_Button(270, 400, 60, 25, "Cancel");
    rp_cancel_button->callback((Fl_Callback *)cancel_robot_part_CB, 0);

    robot_part_create->end();
    robot_part_create->set_non_modal();
    robot_part_create->show();
}

void Controller::create_robot_part_CB(Fl_Widget *w, void *p) {

    ////Saving user input into variables
    Fl_Input* i1 = (Fl_Input*) w->parent()->child(0);
    Fl_Input* i2 = (Fl_Input*) w->parent()->child(1);
    Fl_Input* i3 = (Fl_Input*) w->parent()->child(2);
    Fl_Radio_Button* i4 = (Fl_Radio_Button*) w->parent()->child(3);
    Fl_Radio_Button* i5 = (Fl_Radio_Button*) w->parent()->child(4);
    Fl_Radio_Button* i6 = (Fl_Radio_Button*) w->parent()->child(5);
    Fl_Radio_Button* i7 = (Fl_Radio_Button*) w->parent()->child(6);
    Fl_Radio_Button* i8 = (Fl_Radio_Button*) w->parent()->child(7);
    Fl_Input* i9 = (Fl_Input*) w->parent()->child(8);
    Fl_Input* i10 = (Fl_Input*) w->parent()->child(9);
    Fl_Input* i11 = (Fl_Input*) w->parent()->child(10);

    
 
    //Fl_Radio_Button* i4 = (Fl_Radio_Button*) w->parent()->child(3);


    //printing out user input
    cout << i1->value() << endl;
    cout << i2->value() << endl;
    cout << i3->value() << endl;
    cout << i4->value() << endl;
    cout << i9->value() << endl;
    cout << i10->value() << endl;
    cout << i11->value() << endl;

    w->parent()->hide();
}

void Controller::cancel_robot_part_CB(Fl_Widget *w, void *p) {
    w->parent()->hide();
}

////////////////////////////////////////////////////////////////ORIGINAL CODE//////////////////////////////////////////////////////////////////
void Controller::execute_cmd(int cmd) {
  switch(cmd) {
    case MENU_SHOW_MENU:
        main_menu();
        break;
    case MENU_LIST_ORDERS: 
        cout << "Orders" << endl;
        cout << "------" << endl;
        for (Order o: shop.orders()) cout << o << endl;
        break;
    case MENU_LIST_PEOPLE: 
        cout << "Customers" << endl;
        cout << "---------" << endl;
        for (Customer c: shop.customers()) cout << c << endl;
        cout << endl;
        cout << "Sales Associates" << endl;
        cout << "----------------" << endl;
        for (Sales_associate s: shop.sales_associates()) cout << s << endl;
        cout << endl;
        break;
    case MENU_LIST_MODELS:
        cout << "Robot Models" << endl;
        cout << "------------" << endl;
        for (Robot_model r: shop.models()) cout << r << endl;
        break;
    case MENU_LIST_PARTS:
        cout << "Torsos" << endl;
        cout << "------" << endl;
        for (Torso t: shop.torsos()) cout << t << endl;
        cout << endl;
        cout << "Arms" << endl;
        cout << "----" << endl;
        for (Arm a: shop.arms()) cout << a << endl;
        cout << endl;
        cout << "Heads" << endl;
        cout << "-----" << endl;
        for (Head h: shop.heads()) cout << h << endl;
        cout << endl;
        cout << "Locomotors" << endl;
        cout << "----------" << endl;
        for (Locomotor l: shop.locomotors()) cout << l << endl;
        cout << endl;
        cout << "Batteries" << endl;
        cout << "---------" << endl;
        for (Battery b: shop.batteries()) cout << b << endl;
        cout << endl;
        break;
    case MENU_CREATE_ORDER:
        shop.create_order(
            get_string("Order number?"),
            get_string("Date of sale?"),
            get_model("Select Robot Model by index?"),
            get_customer("Select Customer by index?"),
            get_sa("Select Sales Associate by index?")
        );
        break;
    case MENU_CREATE_CUSTOMER:
        shop.create_customer(
            get_string("Customer name?"),
            get_string("Customer number?")
        );
        break;
    case MENU_CREATE_SA:
        shop.create_sales_associate(
            get_string("Sales Associate name?"),
            get_string("Employee number?")
        );
        break;
    case MENU_CREATE_MODEL:
        shop.create_model(
            get_string("Model name?"),
            get_string("Model number?"),
            get_double("Price?"),
            get_torso("Torso?"),
            get_head("Head?"),
            get_arm("Left arm?"),
            get_arm("Right arm?"),
            get_locomotor("Locomotor?"),
            get_battery("Battery 1?"),
            get_battery("Battery 2?"),
            get_battery("Battery 3?")
        );
        break;
    case MENU_CREATE_TORSO:
        shop.create_torso(
            get_string("Name?"),
            get_string("Part Number?"),
            get_double("Weight?"),
            get_double("Cost?"),
            get_int("Number of battery slots?"),
            get_string("Description?")
        );
        break;
    case MENU_CREATE_ARM:
        shop.create_arm(
            get_string("Name?"),
            get_string("Part Number?"),
            get_double("Weight?"),
            get_double("Cost?"),
            get_int("Max power consumed (W)?"),
            get_string("Description?")
        );
        break;
    case MENU_CREATE_HEAD:
        shop.create_head(
            get_string("Name?"),
            get_string("Part Number?"),
            get_double("Weight?"),
            get_double("Cost?"),
            get_string("Description?")
        );
        break;
    case MENU_CREATE_LOCOMOTOR:
        shop.create_locomotor(
            get_string("Name?"),
            get_string("Part Number?"),
            get_double("Weight?"),
            get_double("Cost?"),
            get_int("Max power consumed (W)?"),
            get_int("Max speed (mph)?"),
            get_string("Description?")
        );
        break;
    case MENU_CREATE_BATTERY:
        shop.create_battery(
            get_string("Name?"),
            get_string("Part Number?"),
            get_double("Weight?"),
            get_double("Cost?"),
            get_int("Max energy stored (kWh)?"),
            get_string("Description?")
        );
        break;
    case MENU_EXIT:
        break;
    default:
        cout << "Invalid command" << endl;
        break;
  }
}

