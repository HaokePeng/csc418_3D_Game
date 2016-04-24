//
//  loadBMP.hpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/8.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#ifndef loadBMP_hpp
#define loadBMP_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <glui.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <GLUI/GLUI.h>
GLuint loadBMP_custom(const char * imagepath);
GLuint LoadTexture( const char * filename );

#endif /* loadBMP_hpp */
