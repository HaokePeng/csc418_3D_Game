//
//  Control.cpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/8.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#include "Control.h"
#define PI 3.14159

bool key_w_down = false;//rotate down
bool key_a_down = false;//rotate up
bool key_s_down = false;//rotate left
bool key_d_down = false;//rotate right
bool key_i_down = false;//go forward
bool key_k_down = false;//go back


void MyKeyboardFunc(unsigned char Key, int x, int y)
{
    
    std::cout<<Key<<" is down"<<std::endl;
    switch(Key)
    {
        case 'W':
        case 'w':{
            key_w_down = true;
            break;
        }
        case 'A':
        case 'a':{
            key_a_down = true;
            break;
        }
        case 'S':
        case 's':{
            key_s_down = true;
            break;
        }
        case 'D':
        case 'd':{
            key_d_down = true;
            break;
        }
        case 'I':
        case 'i':{
            key_i_down = true;
            break;
        }
        case 'K':
        case 'k':{
            key_k_down = true;
            break;
        }
            
            
            
    }
    glutPostRedisplay();
}

void MyKeyboard_UP_Func(unsigned char Key, int x, int y){
    std::cout<<Key<<" is up"<<std::endl;
    switch(Key)
    {
        case 'W':
        case 'w':{
            key_w_down = false;
            break;
        }
        case 'A':
        case 'a':{
            key_a_down = false;
            break;
        }
        case 'S':
        case 's':{
            key_s_down = false;
            break;
        }
        case 'D':
        case 'd':{
            key_d_down = false;
            break;
        }
        case 'I':
        case 'i':{
            key_i_down = false;
            break;
        }
        case 'K':
        case 'k':{
            key_k_down = false;
            break;
        }
        case 27:{//for the escape
            exit(0);
            break;
        }
            
            
            
    }
    glutPostRedisplay();
}

void updata_postion_angle(object& player){
    player.updata_postion_angle(key_w_down, key_a_down, key_s_down, key_d_down, key_i_down, key_k_down);
}