#ifndef __CONTROLLER_H
#define __CONTROLLER_H 2016

#ifndef Fl_Multiline_Input_H
#define Fl_Multiline_Input_H

#ifndef Fl_Return_Button_H
#define Fl_Return_Button_H

#ifndef Fl_Radio_Button_H
#define Fl_Radio_Button_H
 
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

#include "head.h"
#include "arm.h"
#include "locomotor.h"
#include "battery.h"
#include "torso.h"
#include "model.h"
#include "customer.h"
#include "sa.h"
#include "order.h"
#include "shop.h"
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Return_Button.H"   
#include "Fl/Fl_Button.H"

using namespace std;

//////////Makes the multiline input work/////////////////
class FL_EXPORT Fl_Multiline_Input : public Fl_Input {
  public:
    Fl_Multiline_Input(int X,int Y,int W,int H,const char *l = 0);
}; 
///return button///
class FL_EXPORT Fl_Return_Button : public Fl_Button { 
  protected:
    void draw();
  public:
    int handle(int);
    Fl_Return_Button(int X, int Y, int W, int H, const char *l=0);
};
///radio button////
class FL_EXPORT Fl_Radio_Button : public Fl_Button {
    public:
      Fl_Radio_Button(int X,int Y,int W,int H,const char *L=0);
};
class Controller {
  public:
    Controller();

    const static int MENU_LIST_ORDERS      =  1;
    const static int MENU_CREATE_ORDER     =  2;
    const static int MENU_LIST_PEOPLE      = 11;
    const static int MENU_CREATE_CUSTOMER  = 12;
    const static int MENU_CREATE_SA        = 13;

    const static int MENU_LIST_MODELS      = 21;
    const static int MENU_CREATE_MODEL     = 22;

    const static int MENU_LIST_PARTS       = 31;
    const static int MENU_CREATE_TORSO     = 32;
    const static int MENU_CREATE_ARM       = 33;
    const static int MENU_CREATE_HEAD      = 34;
    const static int MENU_CREATE_LOCOMOTOR = 35;
    const static int MENU_CREATE_BATTERY   = 36;

    const static int MENU_SHOW_MENU        = 98;
    const static int MENU_EXIT             = 99;

    void main_menu();

    string get_string(string prompt);
    int get_int(string prompt);
    double get_double(string prompt);

    Customer& get_customer(string prompt);
    Sales_associate& get_sa(string prompt);
    Robot_model& get_model(string prompt);
    Torso& get_torso(string prompt);
    Arm& get_arm(string prompt);
    Head& get_head(string prompt);
    Locomotor& get_locomotor(string prompt);
    Battery& get_battery(string prompt);

    void cli();
    int gui();
    void execute_cmd(int cmd);

    ////////GUI CODE/////////////////
    static void quit_CB(Fl_Widget *w, void *p);
    static void show_robot_part_type_CB(Fl_Widget *w, void *p);
    static void define_robot_part(Fl_Widget *w, void *p);


    static void show_robot_part_form_head_CB(Fl_Widget *w, void *p);
    static void show_robot_part_form_torso_CB(Fl_Widget *w, void *p);
    static void show_robot_part_form_locomotor_CB(Fl_Widget *w, void *p);
    static void show_robot_part_form_battery_CB(Fl_Widget *w, void *p);
    static void show_robot_part_form_arm_CB(Fl_Widget *w, void *p);

    static void create_final_robot_part_head_CB(Fl_Widget *w, void *p);
    static void create_final_robot_part_torso_CB(Fl_Widget *w, void *p);
    static void create_final_robot_part_locomotor_CB(Fl_Widget *w, void *p);
    static void create_final_robot_part_battery_CB(Fl_Widget *w, void *p);
    static void create_final_robot_part_arm_CB(Fl_Widget *w, void *p);

    static void create_robot_part_CB(Fl_Widget *w, void *p);
    static void cancel_robot_part_CB(Fl_Widget *w, void *p);
    static void buttonHeadPushed(Fl_Widget* w, void* p);
    static void buttonTorsoPushed(Fl_Widget* w, void* p);

  private:
    static Shop shop; 
    
};

#endif
#endif
#endif
#endif