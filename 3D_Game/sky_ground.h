//
//  basic_element.hpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/2.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#ifndef sky_ground_h
#define sky_ground_h

#include <stdio.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <glui.h>
#include <vector>
#include <stdlib.h> 
#include <iostream>
#include "loadBMP.h"

#include "basic_element.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <GLUI/GLUI.h>


using namespace std;



void  computer_ground_height(const int base_height_,const int left_x_,const int back_z_,const float unit_,const int unit_x_long_,const int unit_z_long_);
void draw_ground();

vector< vector<int> > get_ground_height();
void draw_sky_box();

#endif /* basic_element_hpp */

