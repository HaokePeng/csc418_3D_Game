//
//  Matrix.hpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/3.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h

#include <stdio.h>
#include <math.h>

class Matrix4x4 {
      //is like    0 1 2 3
                      //           4 5 6 7
    
public:
    float m_data[16];
    Matrix4x4();

    Matrix4x4(char axis, float angle);
    void get_new_normal(float&x_,float&y_,float &z_);
};



#endif /* basic_element_hpp */
