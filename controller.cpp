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
#include "stdlib.h"
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "shop.h"
#include "FL/FL_Group.H"
#include "FL/Fl_Menu_Bar.H"
#include "FL/Fl_Menu_Item.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Radio_Button.H"
#include "FL/Fl_Text_Display.H"



using namespace std;
Shop Controller::shop{"Robbie Robot Shop"};

Fl_Window *robot_part_create_head;
Fl_Window *robot_get_part_type;
Fl_Window *robot_part_create_torso;
Fl_Window *robot_part_create_locomotor;
Fl_Window *robot_part_create_battery;
Fl_Window *robot_part_create_arm;

Controller::Controller()
{

}

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
    menubar->add("Create/Robot Part", FL_CTRL+'c', show_robot_part_type_CB);
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

/////////// Starting Creating a Robot Part////////////////

void Controller::show_robot_part_type_CB(Fl_Widget *w, void *p) {
    //getting user input to know what robot part they want to create
    Fl_Window *robot_get_part_type = new Fl_Window(340, 430, "New Robot Part");

    Fl_Input *rp_part_type = new Fl_Input(120, 90, 210, 25, "Part Type:");
    rp_part_type->align(FL_ALIGN_LEFT);

    Fl_Button *rp_create_button = new Fl_Return_Button(145, 400, 120, 25, "Select");
    rp_create_button->callback((Fl_Callback *) create_robot_part_CB, 0);

    Fl_Button *rp_cancel_button = new Fl_Button(270, 400, 60, 25, "Cancel");
    rp_cancel_button->callback((Fl_Callback *)cancel_robot_part_CB, 0);

    robot_get_part_type->end();
    robot_get_part_type->set_non_modal();
    robot_get_part_type->show();
}

void Controller::create_robot_part_CB(Fl_Widget *w, void *p) {
    //Identifying what specific robot part the user wants to create
    Fl_Input* robotPartType = (Fl_Input*) w->parent()->child(0);
    string robotType = robotPartType->value();

    if(robotType.compare("head") == 0 || robotType.compare("HEAD") == 0 || robotType.compare("Head") == 0)
    {
        robotPartType->callback((Fl_Callback *) show_robot_part_form_head_CB, 0); 
    }

    if(robotType.compare("torso") == 0 || robotType.compare("TORSO") == 0 || robotType.compare("Torso") == 0)
    {
        robotPartType->callback((Fl_Callback *) show_robot_part_form_torso_CB, 0); 
    } 

    if(robotType.compare("locomotor") == 0 || robotType.compare("LOCOMOTOR") == 0 || robotType.compare("Locomotor") == 0)
    {
        robotPartType->callback((Fl_Callback *) show_robot_part_form_locomotor_CB, 0); 
    }

     if(robotType.compare("battery") == 0 || robotType.compare("BATTERY") == 0 || robotType.compare("Battery") == 0)
    {
        robotPartType->callback((Fl_Callback *) show_robot_part_form_battery_CB, 0); 
    } 

     if(robotType.compare("arm") == 0 || robotType.compare("ARM") == 0 || robotType.compare("Arm") == 0)
    {
        robotPartType->callback((Fl_Callback *) show_robot_part_form_arm_CB, 0); 
    } 

    w->parent()->hide();
}
///////////////getting user input to create robot parts///////////////
void Controller::show_robot_part_form_head_CB(Fl_Widget *w, void *p) {

    Fl_Window *robot_part_create_head = new Fl_Window(340, 430, "New Robot Part");

    Fl_Input *rp_name = new Fl_Input(120, 10, 210, 25, "Name");
    rp_name->align(FL_ALIGN_LEFT);

    Fl_Input *rp_part_number = new Fl_Input(120, 50, 210, 25, "Part Number:");
    rp_part_number->align(FL_ALIGN_LEFT);

    Fl_Input *rp_weight = new Fl_Input(120, 250, 210, 25, "Weight:");
    rp_weight->align(FL_ALIGN_LEFT);

    Fl_Input *rp_cost = new Fl_Input(120, 280, 210, 25, "Cost:");
    rp_cost->align(FL_ALIGN_LEFT);

    Fl_Input *rp_description = new Fl_Multiline_Input(120, 310, 210, 75, "Description:");
    rp_description->align(FL_ALIGN_LEFT);

    Fl_Button *rp_create_button = new Fl_Return_Button(145, 400, 120, 25, "Create");
    rp_create_button->callback((Fl_Callback *)create_final_robot_part_head_CB, 0);

    Fl_Button *rp_cancel_button = new Fl_Button(270, 400, 60, 25, "Cancel");
    rp_cancel_button->callback((Fl_Callback *)cancel_robot_part_CB, 0);


    robot_part_create_head->end();
    robot_part_create_head->set_non_modal();
    robot_part_create_head->show();
}

void Controller::show_robot_part_form_torso_CB(Fl_Widget *w, void *p) {

    Fl_Window *robot_part_create_torso = new Fl_Window(340, 430, "New Robot Part");

    Fl_Input *rp_name = new Fl_Input(120, 10, 210, 25, "Name");
    rp_name->align(FL_ALIGN_LEFT);

    Fl_Input *rp_part_number = new Fl_Input(120, 50, 210, 25, "Part Number:");
    rp_part_number->align(FL_ALIGN_LEFT);

    Fl_Input *rp_weight = new Fl_Input(120, 80, 210, 25, "Weight:");
    rp_weight->align(FL_ALIGN_LEFT);

    Fl_Input *rp_cost = new Fl_Input(120, 110, 210, 25, "Cost:");
    rp_cost->align(FL_ALIGN_LEFT);

    Fl_Input *rp_maxBatteries = new Fl_Input(120, 140, 210, 25, "Max Number of Batteries:");
    rp_maxBatteries->align(FL_ALIGN_LEFT);    

    Fl_Input *rp_description = new Fl_Multiline_Input(120, 170, 210, 75, "Description:");
    rp_description->align(FL_ALIGN_LEFT);

    Fl_Button *rp_create_button = new Fl_Return_Button(145, 400, 120, 25, "Create");
    rp_create_button->callback((Fl_Callback *)create_final_robot_part_torso_CB, 0);

    Fl_Button *rp_cancel_button = new Fl_Button(270, 400, 60, 25, "Cancel");
    rp_cancel_button->callback((Fl_Callback *)cancel_robot_part_CB, 0);


    robot_part_create_torso->end();
    robot_part_create_torso->set_non_modal();
    robot_part_create_torso->show();
}

void Controller::show_robot_part_form_locomotor_CB(Fl_Widget *w, void *p) {

    Fl_Window *robot_part_create_locomotor = new Fl_Window(340, 430, "New Robot Part");

    Fl_Input *rp_name = new Fl_Input(120, 10, 210, 25, "Name");
    rp_name->align(FL_ALIGN_LEFT);

    Fl_Input *rp_part_number = new Fl_Input(120, 50, 210, 25, "Part Number:");
    rp_part_number->align(FL_ALIGN_LEFT);

    Fl_Input *rp_weight = new Fl_Input(120, 80, 210, 25, "Weight:");
    rp_weight->align(FL_ALIGN_LEFT);

    Fl_Input *rp_cost = new Fl_Input(120, 110, 210, 25, "Cost:");
    rp_cost->align(FL_ALIGN_LEFT);

    Fl_Input *rp_maxPowerConsume = new Fl_Input(120, 140, 210, 25, "Max Power Consume:");
    rp_maxPowerConsume->align(FL_ALIGN_LEFT); 

    Fl_Input *rp_maxSpeedPossible = new Fl_Input(120, 170, 210, 25, "Max Speed Possible:");
    rp_maxSpeedPossible->align(FL_ALIGN_LEFT);    

    Fl_Input *rp_description = new Fl_Multiline_Input(120, 210, 210, 75, "Description:");
    rp_description->align(FL_ALIGN_LEFT);

    Fl_Button *rp_create_button = new Fl_Return_Button(145, 400, 120, 25, "Create");
    rp_create_button->callback((Fl_Callback *)create_final_robot_part_locomotor_CB, 0);

    Fl_Button *rp_cancel_button = new Fl_Button(270, 400, 60, 25, "Cancel");
    rp_cancel_button->callback((Fl_Callback *)cancel_robot_part_CB, 0);

    robot_part_create_locomotor->end();
    robot_part_create_locomotor->set_non_modal();
    robot_part_create_locomotor->show();
}

void Controller::show_robot_part_form_battery_CB(Fl_Widget *w, void *p) {

    Fl_Window *robot_part_create_battery = new Fl_Window(340, 430, "New Robot Part");

    Fl_Input *rp_name = new Fl_Input(120, 10, 210, 25, "Name");
    rp_name->align(FL_ALIGN_LEFT);

    Fl_Input *rp_part_number = new Fl_Input(120, 50, 210, 25, "Part Number:");
    rp_part_number->align(FL_ALIGN_LEFT);

    Fl_Input *rp_weight = new Fl_Input(120, 80, 210, 25, "Weight:");
    rp_weight->align(FL_ALIGN_LEFT);

    Fl_Input *rp_cost = new Fl_Input(120, 110, 210, 25, "Cost:");
    rp_cost->align(FL_ALIGN_LEFT);

    Fl_Input *rp_maxEnergyStored = new Fl_Input(120, 140, 210, 25, "Max Energy Stored:");
    rp_maxEnergyStored->align(FL_ALIGN_LEFT);    

    Fl_Input *rp_description = new Fl_Multiline_Input(120, 170, 210, 75, "Description:");
    rp_description->align(FL_ALIGN_LEFT);

    Fl_Button *rp_create_button = new Fl_Return_Button(145, 400, 120, 25, "Create");
    rp_create_button->callback((Fl_Callback *)create_final_robot_part_battery_CB, 0);

    Fl_Button *rp_cancel_button = new Fl_Button(270, 400, 60, 25, "Cancel");
    rp_cancel_button->callback((Fl_Callback *)cancel_robot_part_CB, 0);


    robot_part_create_battery->end();
    robot_part_create_battery->set_non_modal();
    robot_part_create_battery->show();
}

void Controller::show_robot_part_form_arm_CB(Fl_Widget *w, void *p) {

    Fl_Window *robot_part_create_arm = new Fl_Window(340, 430, "New Robot Part");

    Fl_Input *rp_name = new Fl_Input(120, 10, 210, 25, "Name");
    rp_name->align(FL_ALIGN_LEFT);

    Fl_Input *rp_part_number = new Fl_Input(120, 50, 210, 25, "Part Number:");
    rp_part_number->align(FL_ALIGN_LEFT);

    Fl_Input *rp_weight = new Fl_Input(120, 80, 210, 25, "Weight:");
    rp_weight->align(FL_ALIGN_LEFT);

    Fl_Input *rp_cost = new Fl_Input(120, 110, 210, 25, "Cost:");
    rp_cost->align(FL_ALIGN_LEFT);

    Fl_Input *rp_maxPowerConsume = new Fl_Input(120, 140, 210, 25, "Max Power Consume:");
    rp_maxPowerConsume->align(FL_ALIGN_LEFT);    

    Fl_Input *rp_description = new Fl_Multiline_Input(120, 170, 210, 75, "Description:");
    rp_description->align(FL_ALIGN_LEFT);

    Fl_Button *rp_create_button = new Fl_Return_Button(145, 400, 120, 25, "Create");
    rp_create_button->callback((Fl_Callback *)create_final_robot_part_arm_CB, 0);

    Fl_Button *rp_cancel_button = new Fl_Button(270, 400, 60, 25, "Cancel");
    rp_cancel_button->callback((Fl_Callback *)cancel_robot_part_CB, 0);


    robot_part_create_arm->end();
    robot_part_create_arm->set_non_modal();
    robot_part_create_arm->show();
}

////////// adding robot parts to shop ////////////////////////
void Controller::create_final_robot_part_head_CB(Fl_Widget *w, void *p) {
    w->parent()->hide();
    Fl_Input* robotPartName = (Fl_Input*) w->parent()->child(0);
    Fl_Input* robotPartNumber = (Fl_Input*) w->parent()->child(1);
    Fl_Input* robotPartWeight = (Fl_Input*) w->parent()->child(2);
    Fl_Input* robotPartCost = (Fl_Input*) w->parent()->child(3);
    Fl_Input* robotPartDescription = (Fl_Input*) w->parent()->child(4);

    // turns weight and cost into type double
    string tempCost = string(robotPartWeight->value());
    double partWeight = std::stod(tempCost);

    string tempPrice = string(robotPartCost->value());
    double partPrice = std::stod(tempPrice);

    shop.create_head(robotPartName->value(), robotPartNumber->value(), partWeight, partPrice, robotPartDescription->value());

    // testing to make sure that robot parts are added to the shop 
   cout << "Heads" << endl;
    cout << "-----" << endl;
    for (Head h: shop.heads()) cout << h << endl;
    cout << endl;
}

void Controller::create_final_robot_part_torso_CB(Fl_Widget *w, void *p) {
    w->parent()->hide();
    Fl_Input* robotPartName = (Fl_Input*) w->parent()->child(0);
    Fl_Input* robotPartNumber = (Fl_Input*) w->parent()->child(1);
    Fl_Input* robotPartWeight = (Fl_Input*) w->parent()->child(2);
    Fl_Input* robotPartCost = (Fl_Input*) w->parent()->child(3);
    Fl_Input* robotPartMaxBatteries = (Fl_Input*) w->parent()->child(4);
    Fl_Input* robotPartDescription = (Fl_Input*) w->parent()->child(5);

    // turns weight and cost into type double
    string tempCost = string(robotPartWeight->value());
    double partWeight = std::stod(tempCost);

    string tempPrice = string(robotPartCost->value());
    double partPrice = std::stod(tempPrice);

    //turns number of batteries to int
    string tempMaxBatteries = string(robotPartMaxBatteries->value());
    int partMaxBattery = std::stoi(tempMaxBatteries);

    shop.create_torso(robotPartName->value(), robotPartNumber->value(), partWeight, partPrice,
                          partMaxBattery, robotPartDescription->value());
   
    // testing to make sure that robot parts are added to the shop 
    cout << "Torsos" << endl;
        cout << "------" << endl;
        for (Torso t: shop.torsos()) cout << t << endl;
        cout << endl;
}

void Controller::create_final_robot_part_locomotor_CB(Fl_Widget *w, void *p) {
    w->parent()->hide();
    Fl_Input* robotPartName = (Fl_Input*) w->parent()->child(0);
    Fl_Input* robotPartNumber = (Fl_Input*) w->parent()->child(1);
    Fl_Input* robotPartWeight = (Fl_Input*) w->parent()->child(2);
    Fl_Input* robotPartCost = (Fl_Input*) w->parent()->child(3);
    Fl_Input* robotPartMaxPowerConsume = (Fl_Input*) w->parent()->child(4);
    Fl_Input* robotPartMaxSpeedPossible = (Fl_Input*) w->parent()->child(5);
    Fl_Input* robotPartDescription = (Fl_Input*) w->parent()->child(6);

    // turns weight and cost into type double
    string tempCost = string(robotPartWeight->value());
    double partWeight = std::stod(tempCost);

    string tempPrice = string(robotPartCost->value());
    double partPrice = std::stod(tempPrice);

    //turns number of batteries to int
    string tempMaxPowerConsume = string(robotPartMaxPowerConsume->value());
    int partMaxPower = std::stoi(tempMaxPowerConsume);

    string tempMaxSpeedPossible = string(robotPartMaxSpeedPossible->value());
    int partMaxSpeed = std::stoi(tempMaxSpeedPossible);

    shop.create_locomotor(robotPartName->value(), robotPartNumber->value(), partWeight, partPrice,
                          partMaxPower, partMaxSpeed, robotPartDescription->value());
   
    // testing to make sure that robot parts are added to the shop 
    cout << "Locomotors" << endl;
        cout << "----------" << endl;
        for (Locomotor l: shop.locomotors()) cout << l << endl;
        cout << endl;
   
}

void Controller::create_final_robot_part_battery_CB(Fl_Widget *w, void *p) {
    w->parent()->hide();
    Fl_Input* robotPartName = (Fl_Input*) w->parent()->child(0);
    Fl_Input* robotPartNumber = (Fl_Input*) w->parent()->child(1);
    Fl_Input* robotPartWeight = (Fl_Input*) w->parent()->child(2);
    Fl_Input* robotPartCost = (Fl_Input*) w->parent()->child(3);
    Fl_Input* robotPartMaxEnergyStored = (Fl_Input*) w->parent()->child(4);
    Fl_Input* robotPartDescription = (Fl_Input*) w->parent()->child(5);

    // turns weight and cost into type double
    string tempCost = string(robotPartWeight->value());
    double partWeight = std::stod(tempCost);

    string tempPrice = string(robotPartCost->value());
    double partPrice = std::stod(tempPrice);

    //turns number of batteries to int
    string tempMaxEnergyStored = string(robotPartMaxEnergyStored->value());
    int partMaxEnergy = std::stoi(tempMaxEnergyStored);

    shop.create_battery(robotPartName->value(), robotPartNumber->value(), partWeight, partPrice,
                          partMaxEnergy, robotPartDescription->value());
   
    // testing to make sure that robot parts are added to the shop 
    cout << "Batteries" << endl;
        cout << "---------" << endl;
        for (Battery b: shop.batteries()) cout << b << endl;
        cout << endl;
}

void Controller::create_final_robot_part_arm_CB(Fl_Widget *w, void *p) {
    w->parent()->hide();
    Fl_Input* robotPartName = (Fl_Input*) w->parent()->child(0);
    Fl_Input* robotPartNumber = (Fl_Input*) w->parent()->child(1);
    Fl_Input* robotPartWeight = (Fl_Input*) w->parent()->child(2);
    Fl_Input* robotPartCost = (Fl_Input*) w->parent()->child(3);
    Fl_Input* robotPartMaxPowerConsume = (Fl_Input*) w->parent()->child(4);
    Fl_Input* robotPartDescription = (Fl_Input*) w->parent()->child(5);

    // turns weight and cost into type double
    string tempCost = string(robotPartWeight->value());
    double partWeight = std::stod(tempCost);

    string tempPrice = string(robotPartCost->value());
    double partPrice = std::stod(tempPrice);

    //turns number of batteries to int
    string tempMaxPowerConsume = string(robotPartMaxPowerConsume->value());
    int partMaxPower = std::stoi(tempMaxPowerConsume);

    shop.create_arm(robotPartName->value(), robotPartNumber->value(), partWeight, partPrice,
                          partMaxPower, robotPartDescription->value());
   
    // testing to make sure that robot parts are added to the shop 
   cout << "Arms" << endl;
        cout << "----" << endl;
        for (Arm a: shop.arms()) cout << a << endl;
        cout << endl;
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

