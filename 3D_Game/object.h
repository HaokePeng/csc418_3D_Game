//
//  objects.hpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/8.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#ifndef objects_hpp
#define objects_hpp

#include <stdio.h>
//#include <stdio.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <glui.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <GLUI/GLUI.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include "basic_element.h"
#include "sky_ground.h"

#define PI 3.14159
class object {
    
    
    
    float r_speed;
    float speed;
    float wing_speed;
    bool wing_up;
    
    
public:
    clock_t lastTime;
    float rotation_up_down;
    float rotation_left_right;
    float rotation_z;
    float rotation_wing;
    float x;
    float y;
    float z;
    float dx;
    float dy;
    float dz;
    object();
    void updata_postion_angle(bool key_w_down,
                              bool key_a_down,
                              bool key_s_down,
                              bool key_d_down,
                              bool key_i_down,
                              bool key_k_down);
    void draw_object();
    
};
class enemy {
    
    
    
public:
    bool killed;
    bool food;
    clock_t lastTime;
    float speed;
    float x;
    float y;
    float z;
    float dx;
    float dy;
    float dz;
    enemy(int i);//i =0 for enemy, i = 1 for food
    void updata_postion(object player);
    void draw_object();
    
};




void get_ground_height_obj(int unit_length);
void check_location_ground_height(float x,float z,float &y);
#endif /* objects_hpp */
