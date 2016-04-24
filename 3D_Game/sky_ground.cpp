//
//  basic_element.cpp
//  3D_Game
//
//  Created by Peng Haoke on 16/4/2.
//  Copyright © 2016年 Peng Haoke. All rights reserved.
//

#include "sky_ground.h"
using namespace std;

float CMap[256][256];    // 色彩值数组
vector<GLuint> texturelist;


vector< vector<int> > ground_height;

 float base_height = 0;
 float left_x=0;
 float back_z=0;
 float unit=0;
 int unit_x_long=0;
 int unit_z_long=0;

vector< vector<int> > get_ground_height(){
    return ground_height;
}
void draw_sky_box(){
    
    //glColor3f(1, 1, 1);
    glPolygonMode(GL_FRONT, GL_FILL);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_TEXTURE_2D);
    
    glFrontFace(GL_CW);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    //for the neg-z
    glColor3f(1, 1,1 );
    glBindTexture(GL_TEXTURE_2D, texturelist[1]);
    
    

    
    //glColor3f(1, 0, 0);
    glPushMatrix();
    glScalef(5100, 2500, 5100);
    glBegin(GL_QUADS);
    //first one
    glTexCoord2f(0.0, 0.0);
    glVertex3f( 0.0,0.0, 0.0);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.0,1.0, 0.0);
    
    glTexCoord2f(0.25, 1.0);
    glVertex3f(1.0 ,1.0, 0);
    
    glTexCoord2f(0.25,0.0 );
    glVertex3f(1,0, 0);
    glEnd();
    glPopMatrix();
    
    
    
    
    
    glPushMatrix();
       glTranslatef(5100, 0, 0);
       glRotated(-90, 0, 1, 0);
    glScalef(5100, 2500, 5100);
    glBegin(GL_QUADS);
    //2
    glTexCoord2f(0.25, 0.0);
    glVertex3f( 0.0,0.0, 0.0);
    
    glTexCoord2f(0.25, 1.0);
    glVertex3f(0.0,1.0, 0.0);
    
    glTexCoord2f(0.5, 1.0);
    glVertex3f(1.0 ,1.0, 0);
    
    glTexCoord2f(0.5,0.0 );
    glVertex3f(1,0, 0);
    glEnd();
    glPopMatrix();
    
    
    
    glPushMatrix();
    glTranslatef(5100, 0, 5100);
    glRotated(180, 0, 1, 0);
    glScalef(5100, 2500, 5100);
    glBegin(GL_QUADS);
    //3
    glTexCoord2f(0.5, 0.0);
    glVertex3f( 0.0,0.0, 0.0);
    
    glTexCoord2f(0.5, 1.0);
    glVertex3f(0.0,1.0, 0.0);
    
    glTexCoord2f(0.75, 1.0);
    glVertex3f(1.0 ,1.0, 0);
    
    glTexCoord2f(0.75,0.0 );
    glVertex3f(1,0, 0);
    glEnd();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0, 0, 5100);
    glRotated(90, 0, 1, 0);
    glScalef(5100, 2500, 5100);
    glBegin(GL_QUADS);
    //4
    glTexCoord2f(0.75, 0.0);
    glVertex3f( 0.0,0.0, 0.0);
    
    glTexCoord2f(0.75, 1.0);
    glVertex3f(0.0,1.0, 0.0);
    
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0 ,1.0, 0);
    
    glTexCoord2f(1.0,0.0 );
    glVertex3f(1,0, 0);
    glEnd();
    glPopMatrix();
    
    
    
    glBindTexture(GL_TEXTURE_2D, texturelist[2]);
    glPushMatrix();
    glTranslatef(0, 2500, 0);
    glRotated(90, 1, 0, 0);
    glScalef(5100, 5100, 5100);
    glBegin(GL_QUADS);
    //the cover
    glTexCoord2f(0.0, 0.0);
    glVertex3f( 0.0,0.0, 0.0);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.0,1.0, 0.0);
    
    glTexCoord2f(0.25, 1.0);
    glVertex3f(1.0 ,1.0, 0);
    
    glTexCoord2f(0.25,0.0 );
    glVertex3f(1,0, 0);
    glEnd();
    glPopMatrix();
    
//    glColor3f(1, 0, 0);
//    
//    //glBindTexture(GL_TEXTURE_2D, texturelist[1]);
//    glPushMatrix();
//    //glScalef(5100, 2500, 5100);
//    glBegin(GL_QUADS);
//    //first one
//    glTexCoord2f(0.0, 0.0);
//    glVertex3f( 1.0,0.0, 0.0);
//    
//    glTexCoord2f(0.0, 1.0);
//    glVertex3f(1.0,1.0, 0.0);
//    
//    glTexCoord2f(0.25, 1.0);
//    glVertex3f(1.0 ,1.0, 1.0);
//    
//    glTexCoord2f(0.25,0.0 );
//    glVertex3f(1,1, 0);
//    glEnd();
//    glPopMatrix();
    
//    glPushMatrix();
//    
//    glTranslatef(5100, 0, 0);
//    glRotated(-90, 0, 1, 0);
//    glScalef(5100, 5100, 5100);
//    
//    glBegin(GL_QUADS);
//    //second one
//    glTexCoord2f(0.25, 0.0);
//    glVertex3f( 0.0,0.0, 0.0);
//    
//    glTexCoord2f(0.25, 1.0);
//    glVertex3f(0.0,1.0, 0.0);
//    
//    glTexCoord2f(0.5, 1.0);
//    glVertex3f(1.0 ,1.0, 0);
//    
//    glTexCoord2f(0.5, 0.0);
//    glVertex3f(1,0, 0);
//    glEnd();
//    glPopMatrix();
//    glPushMatrix();
//    
//    glTranslatef(5100, 0, 0);
//    glRotated(-90, 0, 1, 0);
//    glScalef(5100, 5100, 5100);
//    
//    glBegin(GL_QUADS);
//    //first one
//    glTexCoord2f(0.0, 0.0);
//    glVertex3f( 0.0,0.0, 0.0);
//    
//    glTexCoord2f(0.0, 1.0);
//    glVertex3f(0.0,1.0, 0.0);
//    
//    glTexCoord2f(1.0, 1.0);
//    glVertex3f(1.0 ,1.0, 0);
//    
//    glTexCoord2f(1.0, 0.4);
//    glVertex3f(1,0, 0);
//    glEnd();
//    glPopMatrix();
   
    

            

        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_CULL_FACE);
    glPopMatrix();
    
    
    
    
    
    
    
}
void draw_ground(){

    int number_of_col = unit_x_long;//255
    int number_of_row = unit_z_long;//255
    glColor3f(1, 1, 1);
    glPolygonMode(GL_FRONT, GL_FILL);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturelist[0]);
    glFrontFace(GL_CW);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glBegin(GL_QUADS);


    for (int i = 0; i<number_of_col; i++) {
        float x_value = left_x + i * unit;
        for (int j=0; j<number_of_row; j++) {
            float rgb =CMap[i][j];
//            int red = (rgb >> 5) & 0x08;
//            int green = (rgb >> 2) & 0x08;
//            int blue = rgb & 0x04;
            
            glColor3f(rgb*0.5, rgb, rgb*0.4);

            float z_value = back_z + j * unit;

            
            

            
            glTexCoord2f(0.0, 0.0);
            glVertex3f(x_value ,ground_height[i][j], z_value);
            
            glTexCoord2f(1.0, 0.0);
            glVertex3f(x_value+unit ,ground_height[i+1][j], z_value);
            
            glTexCoord2f(1.0, 1.0);
            glVertex3f(x_value+unit ,ground_height[i+1][j+1], z_value+unit);
            
            glTexCoord2f(0.0, 1.0);
            glVertex3f(x_value ,ground_height[i][j+1], z_value+unit);

            
 



        }
        
        
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_CULL_FACE);
    glPopMatrix();

    
    
    
    
   

}
#define Clamp(x) ((x)<0 ? 0 : ((x)>255 ? 255 : (x)))
// 取 x 的低字节位, 即对 255 取模 (HMap 和 CMap 都是 256 x 256 的数组)
#define L(x) ((x)&0xff)

void computer_ground_height(const int base_height_,const int left_x_,const int back_z_,const float unit_,const int unit_x_long_,const int unit_z_long_){
    
    base_height = base_height_;
    left_x=left_x_;
   back_z=back_z_;
    unit=unit_;
    unit_x_long=unit_x_long_;
   unit_z_long=unit_z_long_;
    texturelist.push_back(loadBMP_custom("/Users/Peng_Haoke/Desktop/programming/ground.bmp"));
    texturelist.push_back(loadBMP_custom("/Users/Peng_Haoke/Desktop/programming/AAA.bmp"));
    texturelist.push_back(loadBMP_custom("/Users/Peng_Haoke/Desktop/programming/cover.bmp"));

    
    
    
    
    
    
//    int number_of_col = unit_x_long+1;
//    int number_of_row = unit_z_long+1;
//    
//    for (int i = 0; i<number_of_col; i++) {
//        vector<float> height_of_a_col;
//        for (int j=0; j<number_of_row; j++) {
//            
//            float heignt= base_height + ((rand()%101)-50)/50.0 * 0.2 * unit;
//            
////            float heignt= base_height ;
//            height_of_a_col.push_back(heignt);
//        }
//        ground_height.push_back(height_of_a_col);
//    }

//    cout<<"finishe computer the height of the ground"<<endl;
    
    int HMap[256][256];
    

    

    

        int p,i,j,k,k2,p2;
        

        
        HMap[0][0]=128;
    //vector<vector<int>> ground_height;
        for ( p=256; p>1; p=p2 )
        {
            p2=p/2;
            k=p*20+40; k2=k/2;
            for ( i=0; i<256; i+=p )
            {
                for ( j=0; j<256; j+=p )
                {
                    int a,b,c,d;
                    a=HMap[i][j];
                    b=HMap[ L(i+p) ][j];
                    c=HMap[i][ L(j+p) ];
                    d=HMap[ L(i+p)][ L(j+p) ];
                    HMap[i][ L(j+p2) ]=
                    Clamp(((a+c)>>1)+(rand()%k-k2));
                    HMap[ L(i+p2) ][ L(j+p2) ]=
                    Clamp(((a+b+c+d)>>2)+(rand()%k-k2));
                    HMap[ L(i+p2) ][j]=
                    Clamp(((a+b)>>1)+(rand()%k-k2));
                }
            }
        }
        
        // 平滑处理
        
        for ( k=0; k<3; k++ )
            for ( i=0; i<256; i++ )
                for ( j=0; j<256; j++ )
                {
                    HMap[i][j]=(HMap[ L(i+1) ][j]+HMap[i][ L(j+1) ]+
                                HMap[ L(i-1) ][j]+HMap[i][ L(j-1) ])/4;
                }
    
    for (i = 0; i<256; i++) {
        vector<int> col;
        for (j=0; j<256; j++) {
            
            col.push_back(HMap[i][j]);
        }
        ground_height.push_back(col);
    }

        

        
        for ( i=0; i<256; i++ )
            for ( j=0; j<256; j++ )
            {
                k=300-abs((HMap[ L(i+1) ][ L(j+1) ]-HMap[i][j])*4);
                CMap[i][j]=Clamp(k)/300.0;
                
            }
    
   
    
}


