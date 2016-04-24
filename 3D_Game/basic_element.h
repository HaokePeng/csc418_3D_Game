//
//  basic_element.hpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/8.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#ifndef basic_element_hpp
#define basic_element_hpp
#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <GLUI/GLUI.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <glui.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "loadBMP.h"

#include <stdio.h>
void drawCube();
void draw_xyz();
void draw_trapazoid(const float height, const float upper_width, const float lower_width, const float upper_depth, const float lower_depth);
void draw_triangle(const float lenght, const float width, const float height);
void draw_cuboid(const float height, const float width, const float depth);
void draw_side(int unit);
#endif /* basic_element_hpp */
