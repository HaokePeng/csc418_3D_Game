//
//  objects.cpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/8.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#include "object.h"
#include <iostream>

vector< vector<int> > height;
int unit_length_;

void get_ground_height_obj(int unit_length){
    height = get_ground_height();
    unit_length_ = unit_length;
}

void object::updata_postion_angle(bool key_w_down,
                                  bool key_a_down,
                                  bool key_s_down,
                                  bool key_d_down,
                                  bool key_i_down,
                                  bool key_k_down){
    
    
    // Compute time difference between current and last frame
    double currentTime = clock();
    float deltaTime = float(currentTime - lastTime)/CLOCKS_PER_SEC;
    //std::cout<<deltaTime<<std::endl;
    //change the angle
    if (key_w_down) {
        rotation_up_down += r_speed* deltaTime;
    }
    if (key_s_down) {
        rotation_up_down -= r_speed* deltaTime;
    }
    if (key_d_down) {
        rotation_left_right -= r_speed* deltaTime;
        rotation_z = -20.0;
    }else if (key_a_down){
        rotation_left_right += r_speed* deltaTime;
        rotation_z = 20.0;
    }
    else{
        rotation_z = 0;
    }
    
    
    std::cout<<rotation_wing<<std::endl;
    if (rotation_wing>15) {
        wing_up = false;
        rotation_wing = 15;
    }else if (rotation_wing<-15){
        wing_up = true;
        rotation_wing = -15;
    }else if(wing_up){//should increase
        rotation_wing = rotation_wing + wing_speed * deltaTime;
    }else{
        rotation_wing = rotation_wing - wing_speed * deltaTime;
    }
    
    
    //get the direction
    float x0 = 0;
    float y0 =0;
    float z0 = 1;
    
    float x1 = x0;
    float y1 = cosf(-rotation_up_down/180.0*PI)*y0 + -sinf(-rotation_up_down/180.0*PI)*z0;
    float z1 = sinf(-rotation_up_down/180.0*PI)*y0 + -cosf(-rotation_up_down/180.0*PI)*z0;
    
    dx = cosf(rotation_left_right/180*PI)*x1+sinf(rotation_left_right/180.0*PI)*z1;
    dy = y1;
    dz = -sinf(rotation_left_right/180.0*PI)*x0 +cosf(rotation_left_right/180.0*PI)*z1;
    
    
    
    
    //change the location
    if (key_i_down) {
        //if ((50<x)&&(x<5500)) {
            x = x + dx * speed* deltaTime;
        if (x<50) {
            x = 50;
        }
        if (x>5050) {
            x = 5050;
        }
        
            y = y + dy * speed* deltaTime;;
        if (y<50) {
            y = 50;
        }
        if (y>5050) {
            y = 5050;
        }
        
        z = z + dz * speed* deltaTime;
        check_location_ground_height(x,z,y);
        //if z is large less then the height+5
        //then let z = height + 5
    }
    if (key_k_down) {
        x = x - dx * speed* deltaTime;
        //if ((50<y)&&(y<5500)) {
        y = y - dy * speed* deltaTime;
        //std::cout<<1/deltaTime<<std::endl;
        //}
        z = z - dz * speed* deltaTime;
        check_location_ground_height(x,z,y);
    }
    lastTime = currentTime;
    glutPostRedisplay();
}

void object::draw_object(){
    
    
    
    
    
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotated(rotation_left_right, 0, 1, 0);
    glRotated(rotation_up_down, 1, 0, 0);
    glRotated(rotation_z, 0, 0, 1);
    glColor3f(1, 0, 0);
    
    if (1) {//begin to draw the bird
        draw_xyz();
        
        glPolygonMode(GL_FRONT_FACE, GL_FILL);
        glColor3f(0, 0, 1);
        GLUquadricObj *objCylinder =gluNewQuadric();
        glutSolidSphere(1,30, 20);
        
        
        glPushMatrix();//for the ear
        glColor3f(1, 0.8, 0.8);
        //glRotated(-45, 0, 1, 0);
        //glRotated(-60, 0, 0, 1);
        //glRotated(-90, 0, 1, 0);
        //glTranslatef(0, 1, 0);
        glRotated(30, 0, 0, 1);
        glTranslatef(0, 1, 0);
        draw_triangle(0.1, 0.3, 0.3);
        glPopMatrix();////for the ear
        
        glPushMatrix();//for the ear
        glColor3f(1, 0.8, 0.8);
        //glRotated(-45, 0, 1, 0);
        //glRotated(-60, 0, 0, 1);
        //glRotated(-90, 0, 1, 0);
        //glTranslatef(0, 1, 0);
        glRotated(-30, 0, 0, 1);
        glTranslatef(0, 1, 0);
        draw_triangle(0.1, 0.3, 0.3);
        glPopMatrix();////for the ear
        
        glPushMatrix();//for the right wing
        glColor3f(1, 0, 1);
        glRotated(-45, 0, 1, 0);
        glRotated(-60, 0, 0, 1);
        glRotated(-90, 0, 1, 0);
        glTranslatef(0, 1, 0);
        glRotated(rotation_wing, 1, 0, 0);//run angle
        glTranslatef(0, 0.5, 0);
        draw_trapazoid(1, 0.8, 0.3, 0.1, 0.1);
        glPopMatrix();//end for the wing
        
        glPushMatrix();//for the right wing
        glColor3f(1, 0, 1);
        glRotated(45, 0, 1, 0);
        glRotated(60, 0, 0, 1);
        glRotated(90, 0, 1, 0);
        glTranslatef(0, 1, 0);
        glRotated(rotation_wing, 1, 0, 0);//run angle
        glTranslatef(0, 0.5, 0);
        draw_trapazoid(1.0, 0.8, 0.3, 0.1, 0.1);
        glPopMatrix();//end for the wing
    }
    glPopMatrix();
    

    
    
}

object::object(){
    wing_speed = 500;
    wing_up = true;
    x = 2000;
    y = 200;
    z = 2000;
    rotation_z = 0;
    rotation_up_down = -22.0;
    rotation_left_right = -147.0;
    dx = 0;
    dy = 0;
    dz = 1;
     speed = 600;
     r_speed = 250;
    lastTime = clock();
}
void check_location_ground_height(float x,float z,float &y){
    int index_x = x / unit_length_ + 1;
    int index_z = z / unit_length_ + 1;
    float g_height = height[index_x][index_z] + 5;
    
    if (y<g_height) {
        y = g_height+5;
    }
}



enemy::enemy(int i){
    killed = false;
    x = rand()%5000+12;
    z = rand()%5000+12;
    y = rand()%100;
    check_location_ground_height(x,z,y);
    speed = rand()%100+200;
    dx = 1;
    dy = 0;
    dz = 0;
    if (i==0) {
        food = false;
    }
    else{
        food = true;
    }
    lastTime = clock();
}
void enemy::updata_postion(object player){
    if (killed ==false) {
      
    
    
    
        
        // Compute time difference between current and last frame
        double currentTime = clock();
        float deltaTime = float(currentTime - lastTime)/CLOCKS_PER_SEC;
        float ddx = player.x - x;
        float ddy = player.y - y;
        float ddz = player.z - z;
        float ll = powf(ddx, 2.0)+powf(ddy, 2.0)+powf(ddz, 2.0);
        
        if (ll<=100) {
            if(food==false){
                exit(0);
            }else{
                killed = true;
            }
        }
    

        if(rand()%10>=4){
            float lll = powf(ll, 0.5);
            
        
            dx = ddx / lll;
            dy = ddy / lll;
            dz = ddz / lll;
            if (food == true) {
                //std::cout<<"i am food"<<std::endl;
                dx = -dx;
                dy = -dy;
                dz = -dz;
            }
            
        }
        
        //move
        x = x + dx * speed* deltaTime;
        y = y + dy * speed* deltaTime;
        z = z + dz * speed* deltaTime;
    
        if (x<50) {
            x = 50;
        }
        if (x>5050) {
            x = 5050;
        }

        if (y<50) {
            y = 50;
        }
        if (y>5050) {
            y = 5050;
        }
        check_location_ground_height(x,z,y);

        lastTime = currentTime;

        glutPostRedisplay();
    }
    
}
    
void enemy::draw_object(){
    if (killed==false) {
       
    
    
    if (food == true) {
        std::cout<<"draw food"<<std::endl;
        glPushMatrix();
        glTranslatef(x, y, z);
        glPolygonMode(GL_FRONT_FACE, GL_FILL);
        glColor3f(1.0, 1.0, 1.0);
        GLUquadricObj *objCylinder =gluNewQuadric();
        glutSolidSphere(10,30, 20);
        glPopMatrix();
    }
    else{
    glPushMatrix();
    glTranslatef(x, y, z);
    glPolygonMode(GL_FRONT_FACE, GL_FILL);
    glColor3f(1.0, 0.0, 0.0);
    GLUquadricObj *objCylinder =gluNewQuadric();
    glutSolidSphere(10,30, 20);
    glPopMatrix();
    }
    }
    
}




