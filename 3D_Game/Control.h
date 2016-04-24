//
//  Control.hpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/8.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#ifndef Control_h
#define Control_h

#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <GLUI/GLUI.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <glui.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include "object.h"

//one, update the state of the keyboard and mouse(if I have time), where I should I put the state?---> leave it in this file, let is be grobal varible
void MyKeyboardFunc(unsigned char Key, int x, int y);
void MyKeyboard_UP_Func(unsigned char Key, int x, int y);



//two,update the object position and direction(angle) at the beginning of the drawing function
//the object of this function is to update the location, and angle. we need the old andlge and old location. The direction can be computer from the angle every times.
void updata_postion_angle(object& player);


#endif /* Control_hpp */
