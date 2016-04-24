//
//  Matrix.cpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/3.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#include "Matrix.h"


Matrix4x4::Matrix4x4(){
    for (int i =0; i<16; i++) {
        m_data[i] = 0;
    }
}


Matrix4x4::Matrix4x4(char axis, float angle){
     angle = angle/180*3.14159;
    if (axis=='x') {
        m_data[0] =1;  m_data[1] =0;  m_data[2] =0;  m_data[3] =0;
        m_data[4] =0;  m_data[5] =cosf(angle);  m_data[6] =-sinf(angle);  m_data[7] =0;
        m_data[8] =0;  m_data[9] =sinf(angle);  m_data[10]=cosf(angle); m_data[11]=0;
        m_data[12] =0; m_data[13] =0; m_data[14] =0;  m_data[15] =1;
    }
    else if(axis =='y'){
        m_data[0] =cosf(angle);  m_data[1] =0;  m_data[2] =sinf(angle);  m_data[3] =0;
        m_data[4] =0;  m_data[5] =1;  m_data[6] =0;  m_data[7] =0;
        m_data[8] =-sinf(angle);  m_data[9] =0;  m_data[10]=cosf(angle); m_data[11]=0;
        m_data[12] =0; m_data[13] =0; m_data[14] =0;  m_data[15] =1;
    }
    else{
        ;
    }
}

void Matrix4x4::get_new_normal(float&x_,float&y_,float &z_){
    float x = x_;
    float y = y_;
    float z = z_;
    
    x_ = m_data[0]*x+m_data[1]*y+m_data[2]*z ;
    y_ = m_data[4]*x+m_data[5]*y+m_data[6]*z;
    z_ = m_data[8]*x+m_data[9]*y+m_data[10]*z;
}