//
//  basic_element.cpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/8.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#include "basic_element.h"
void drawCube()
{
    glBegin(GL_QUADS);
    // draw front face
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);
    glVertex3f( 1.0,  1.0, 1.0);
    glVertex3f(-1.0,  1.0, 1.0);
    
    // draw back face
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    
    // draw left face
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f(-1.0,  1.0,  1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    
    // draw right face
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    
    // draw top
    glVertex3f(-1.0,  1.0,  1.0);
    glVertex3f( 1.0,  1.0,  1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    
    // draw bottom
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glEnd();
}

void draw_xyz()
{
//    glLineWidth(2.5);
//    glBegin(GL_LINES);
//    glVertex3f(0.0, 0.0, 0.0);
//    glVertex3f( 10000.0, 0.0, 0.0);
//    glEnd();
//    
//    glBegin(GL_LINES);
//    glVertex3f(0.0, 0.0, 0.0);
//    glVertex3f(0.0, 10000.0, 0.0);
//    glEnd();
//    
//    glBegin(GL_LINES);
//    
//    glVertex3f(0.0, 0.0, 0.0);
//    glVertex3f(0.0, 0.0, 10000.0);
//    glEnd();
    
    
}

void draw_triangle(const float lenght, const float width, const float height) {
    const float half_length = lenght / 2;
    const float half_width = width / 2;
    const float half_height = height / 2;
    
    glBegin(GL_TRIANGLES);
    
    
    glNormal3f(0, 1, 0); glVertex3f(0,  half_length,  -half_height);
    glNormal3f(0, 1, 0); glVertex3f(half_width,  half_length,  half_height);
    glNormal3f(0, 1, 0); glVertex3f(-half_width, half_length, half_height);
    
    
    glNormal3f(0, -1, 0); glVertex3f(0,  -half_length,  -half_height);
    glNormal3f(0, -1, 0); glVertex3f(half_width,  -half_length,  half_height);
    glNormal3f(0, -1, 0); glVertex3f(-half_width, -half_length, half_height);
    
    
    glEnd();
    glBegin(GL_QUADS);
    
    glNormal3f(height, 0, -half_width); glVertex3f(0,  half_length,  -half_height);
    glNormal3f(height, 0, -half_width); glVertex3f(0,  -half_length,  -half_height);
    glNormal3f(height, 0, -half_width); glVertex3f(half_width,  -half_length,  half_height);
    glNormal3f(height, 0, -half_width); glVertex3f(half_width,  half_length,  half_height);
    
    glNormal3f(0, 0, 1); glVertex3f(half_width,  -half_length,  half_height);
    glNormal3f(0, 0, 1); glVertex3f(half_width,  half_length,  half_height);
    glNormal3f(0, 0, 1); glVertex3f(-half_width,  half_length,  half_height);
    glNormal3f(0, 0, 1); glVertex3f(-half_width,  -half_length,  half_height);
    
    glNormal3f(-height, 0, -half_width); glVertex3f(-half_width,  half_length,  half_height);
    glNormal3f(-height, 0, -half_width); glVertex3f(-half_width,  -half_length,  half_height);
    glNormal3f(-height, 0, -half_width); glVertex3f(0,  -half_length,  -half_height);
    glNormal3f(-height, 0, -half_width); glVertex3f(0,  half_length,  -half_height);
    
    
    glEnd();
}
void draw_trapazoid(const float height, const float upper_width, const float lower_width, const float upper_depth, const float lower_depth)
{
    const float half_upper_width = upper_width / 2;
    const float half_upper_depth = upper_depth / 2;
    const float half_lower_width = lower_width / 2;
    const float half_lower_depth = lower_depth / 2;
    const float half_height = height / 2;
    const float width_difference = half_lower_width - half_upper_width;
    const float depth_difference = half_lower_depth - half_upper_depth;
    glBegin(GL_QUADS);
    
    // draw cover
    
    glNormal3f(0, 1, 0); glVertex3f(half_upper_width, half_height, -half_upper_depth);
    glNormal3f(0, 1, 0); glVertex3f(-half_upper_width,  half_height, -half_upper_depth);
    glNormal3f(0, 1, 0); glVertex3f(-half_upper_width,  half_height, half_upper_depth);
    glNormal3f(0, 1, 0); glVertex3f(half_upper_width, half_height, half_upper_depth);
    
    // draw bottom
    
    glNormal3f(0, -1, 0); glVertex3f(half_lower_width, -half_height, -half_lower_depth);
    glNormal3f(0, -1, 0); glVertex3f(-half_lower_width,  -half_height, -half_lower_depth);
    glNormal3f(0, -1, 0); glVertex3f(-half_lower_width,  -half_height, half_lower_depth);
    glNormal3f(0, -1, 0); glVertex3f(half_lower_width, -half_height, half_lower_depth);
    
    
    
    glNormal3f(-height, width_difference, 0); glVertex3f(-half_lower_width, -half_height,  -half_lower_depth);
    glNormal3f(-height, width_difference, 0); glVertex3f(-half_upper_width,  half_height, -half_upper_depth);
    glNormal3f(-height, width_difference, 0); glVertex3f(-half_upper_width,  half_height,  half_upper_depth);
    glNormal3f(-height, width_difference, 0); glVertex3f(-half_lower_width, -half_height,  half_lower_depth);
    
    glNormal3f(height, width_difference, 0); glVertex3f(half_lower_width, -half_height,  half_lower_depth);
    glNormal3f(height, width_difference, 0); glVertex3f(half_lower_width, -half_height,  -half_lower_depth);
    glNormal3f(height, width_difference, 0); glVertex3f(half_upper_width,  half_height, -half_upper_depth);
    glNormal3f(height, width_difference, 0); glVertex3f(half_upper_width,  half_height,  half_upper_depth);
    
    
    glNormal3f(0, depth_difference, height); glVertex3f(half_upper_width,  half_height,  half_upper_depth);
    glNormal3f(0, depth_difference, height); glVertex3f(-half_upper_width,  half_height, half_upper_depth);
    glNormal3f(0, depth_difference, height); glVertex3f(-half_lower_width,  -half_height, half_lower_depth);
    glNormal3f(0, depth_difference, height); glVertex3f(half_lower_width,  -half_height,  half_lower_depth);
    
    
    glNormal3f(0, depth_difference, -height); glVertex3f(half_upper_width,  half_height,  -half_upper_depth);
    glNormal3f(0, depth_difference, -height); glVertex3f(-half_upper_width,  half_height, -half_upper_depth);
    glNormal3f(0, depth_difference, -height); glVertex3f(-half_lower_width,  -half_height, -half_lower_depth);
    glNormal3f(0, depth_difference, -height); glVertex3f(half_lower_width,  -half_height,  -half_lower_depth);
    
    glEnd();
}
void draw_cuboid(const float height, const float width, const float depth){
    draw_trapazoid(height,width, width,depth,depth);
}

void draw_side(int unit){
    int limit = unit*255;
    glPushMatrix();
    glScalef(limit, limit, limit);
    glColor3f(1.0, 0, 0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f( 0.0,0.0, 0.0);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.0,1.0, 0.0);
    
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0 ,1.0, 0);
    
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1,0, 0);
    glPopMatrix();
}