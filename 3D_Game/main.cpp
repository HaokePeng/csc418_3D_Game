/***********************************************************
             CSC418, Winter 2016
 
                 penguin.cpp
                 author: Mike Pratscher
                 based on code by: Eron Steger, J. Radulovich

		Main source file for assignment 2
		Uses OpenGL, GLUT and GLUI libraries
  
    Instructions:
        Please read the assignment page to determine 
        exactly what needs to be implemented.  Then read 
        over this file and become acquainted with its 
        design. In particular, see lines marked 'README'.
		
		Be sure to also look over keyframe.h and vector.h.
		While no changes are necessary to these files, looking
		them over will allow you to better understand their
		functionality and capabilites.

        Add source code where it appears appropriate. In
        particular, see lines marked 'TODO'.

        You should not need to change the overall structure
        of the program. However it should be clear what
        your changes do, and you should use sufficient comments
        to explain your code.  While the point of the assignment
        is to draw and animate the character, you will
        also be marked based on your design.

***********************************************************/

#ifdef _WIN32
#include <windows.h>
#endif

//
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <glui.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <GLUI/GLUI.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




#include <iostream>


#include "basic_element.h"
#include "Matrix.h"
#include "Control.h"
#include "loadBMP.h"
#include "object.h"
#include "sky_ground.h"


// *************** GLOBAL VARIABLES *************************




const float SPINNER_SPEED = 0.1;
float xxxx;
object player;
vector<enemy> enemy_list;
vector<enemy> food_list;

// --------------- USER INTERFACE VARIABLES -----------------

// Window settings
int windowID;				// Glut window ID (for display)
int Win[2];					// window (x,y) size

GLUI* glui_render;			// Glui window for render style
GLUI* glui_Camera;

char msg[256];				// String used for status message
GLUI_StaticText* status;	// Status message ("Status: <msg>")


// ---------------- ANIMATION VARIABLES ---------------------

// Camera settings
const float ZOOM_SCALE = 0.01;

float camXPos =  6;
float camYPos =  12;
float camZPos = 12;
float cam_rotate_left_right =  2.2;
float cam_rotate_up_down =  -45;
float unit_length = 25;
float limit = 255*unit_length;



const GLdouble CAMERA_FOVY = 60.0;
const GLdouble NEAR_CLIP   = 0.1;
const GLdouble FAR_CLIP    = 7000.0;

// Render settings
enum { WIREFRAME, SOLID, OUTLINED };	// README: the different render styles
int renderStyle = WIREFRAME;			// README: the selected render style



// ***********  FUNCTION HEADER DECLARATIONS ****************


// Initialization functions
void initDS();
void initGlut(int argc, char** argv);
void initGlui();
void initGl();


// Callbacks for handling events in glut
void reshape(int w, int h);
void animate();
void display(void);
//void mouse(int button, int state, int x, int y);
//void motion(int x, int y);





// ******************** FUNCTIONS ************************



// main() function
// Initializes the user interface (and any user variables)
// then hands over control to the event handler, which calls 
// display() whenever the GL window needs to be redrawn.
int main(int argc, char** argv)
{
    
   // updatenormal(normal_x,normal_y,normal_z);
    // Process program arguments
    if(argc != 3) {
        printf("Usage: demo [width] [height]\n");
        printf("Using 800x600 window by default...\n");
        Win[0] = 800;
        Win[1] = 600;
    } else {
        Win[0] = atoi(argv[1]);
        Win[1] = atoi(argv[2]);
    }


    // Initialize data structs, glut, glui, and opengl
	
    initGlut(argc, argv);
    initGlui();
    initGl();
initDS();
    // Invoke the standard GLUT main event loop
    
    
    ///
    
    
    glutMainLoop();

    return 0;         // never reached
}


// Create / initialize global data structures
void initDS()
{
//	keyframes = new Keyframe[KEYFRAME_MAX];
//	for( int i = 0; i < KEYFRAME_MAX; i++ )
//		keyframes[i].setID(i);
    computer_ground_height(0, 0, 0, unit_length, 255, 255);
    get_ground_height_obj(unit_length);
    for (int i =0; i<10; i++) {
        enemy new_one = enemy(0);
        enemy_list.push_back(new_one);
    }
    for (int i =0; i<10; i++) {
        enemy new_one = enemy(1);
        food_list.push_back(new_one);
    }

}


// Initialize glut and create a window with the specified caption 
void initGlut(int argc, char** argv)
{
	// Init GLUT
	glutInit(&argc, argv);

    // Set video mode: double-buffered, color, depth-buffered
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Create window
    glutInitWindowPosition (0, 0);
    glutInitWindowSize(Win[0],Win[1]);
    windowID = glutCreateWindow(argv[0]);

    // Setup callback functions to handle events
    glutReshapeFunc(reshape);	// Call reshape whenever window resized
    glutDisplayFunc(display);	// Call display whenever new frame needed
//	glutMouseFunc(mouse);		// Call mouse whenever mouse button pressed
//	glutMotionFunc(motion);		// Call motion whenever mouse moves while button pressed
    glutKeyboardFunc(MyKeyboardFunc);
    glutKeyboardUpFunc(MyKeyboard_UP_Func);
    glutIgnoreKeyRepeat(1);
    
}


// Initialize GLUI and the user interface
void initGlui()
{

	GLUI_Panel* glui_panel;
	GLUI_Spinner* glui_spinner;
	GLUI_RadioGroup* glui_radio_group;

    GLUI_Master.set_glutIdleFunc(NULL);


    
    //////////
    

    
    /////////



	///////////////////////////////////////////////////////////
	// TODO (for controlling light source position & additional
	//      rendering styles):
	//   Add more UI spinner elements here. Be sure to also
	//   add the appropriate min/max range values to this
	//   file, and to also add the appropriate enums to the
	//   enumeration in the Keyframe class (keyframe.h).
	///////////////////////////////////////////////////////////

	//
	// ***************************************************


	// Create GLUI window (keyframe controls) ************
	//
	






	// Create GLUI window (render controls) ************
	//
	glui_render = GLUI_Master.create_glui("Render Control", 0, 367, Win[1]+64);

	// Create control to specify the render style
	glui_panel = glui_render->add_panel("Render Style");
	glui_radio_group = glui_render->add_radiogroup_to_panel(glui_panel, &renderStyle);
	glui_render->add_radiobutton_to_group(glui_radio_group, "Wireframe");
	glui_render->add_radiobutton_to_group(glui_radio_group, "Solid");
	glui_render->add_radiobutton_to_group(glui_radio_group, "Solid w/ outlines");
	//
	// ***************************************************
    
    // Create GLUI window (camera controls) ************
    //
    glui_Camera = GLUI_Master.create_glui("Camera Control", 0, Win[0]+200, 0);
    
    // Create controls to specify root position and orientation
    
    glui_panel = glui_Camera->add_panel("Camera");
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "Camera left right:", GLUI_SPINNER_FLOAT, &camXPos);
    
    glui_spinner->set_speed(SPINNER_SPEED);
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "Camera front back:", GLUI_SPINNER_FLOAT, &camZPos);
    
    glui_spinner->set_speed(SPINNER_SPEED);
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "camera height", GLUI_SPINNER_FLOAT, &camYPos);
    
    glui_spinner->set_speed(SPINNER_SPEED);
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "rotate left right:", GLUI_SPINNER_FLOAT, &cam_rotate_left_right);
    glui_spinner->set_speed(SPINNER_SPEED);
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "rotate up and down:", GLUI_SPINNER_FLOAT, &cam_rotate_up_down);
    glui_spinner->set_speed(SPINNER_SPEED);
    
    //*************************************************0
    //object
    glui_panel = glui_Camera->add_panel("Object");
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "Object left right:", GLUI_SPINNER_FLOAT, &player.x);
    
    glui_spinner->set_speed(SPINNER_SPEED);
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "Object front back:", GLUI_SPINNER_FLOAT, &player.z);
    
    glui_spinner->set_speed(SPINNER_SPEED);
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "Object height", GLUI_SPINNER_FLOAT, &player.y);
    
    glui_spinner->set_speed(SPINNER_SPEED);
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "Object rotate left right:", GLUI_SPINNER_FLOAT, &player.rotation_left_right);
    
    glui_spinner->set_speed(SPINNER_SPEED);
    
    glui_spinner = glui_Camera->add_spinner_to_panel(glui_panel, "Object rotate up and down:", GLUI_SPINNER_FLOAT, &player.rotation_up_down);
    
    glui_spinner->set_speed(SPINNER_SPEED);
    

    

    //
    // ***************************************************


	// Tell GLUI windows which window is main graphics window

    glui_Camera->set_main_gfx_window(windowID);
	glui_render->set_main_gfx_window(windowID);
}


// Performs most of the OpenGL intialization
void initGl(void)
{
    // glClearColor (red, green, blue, alpha)
    // Ignore the meaning of the 'alpha' value for now
    glClearColor(0.7f,0.7f,0.9f,1.0f);
}


// Calculates the interpolated joint DOF vector
// using Catmull-Rom interpolation of the keyframes





// Handles the window being resized by updating the viewport
// and projection matrices
void reshape(int w, int h)
{
	// Update internal variables and OpenGL viewport
	Win[0] = w;
	Win[1] = h;
	glViewport(0, 0, (GLsizei)Win[0], (GLsizei)Win[1]);

    // Setup projection matrix for new window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(CAMERA_FOVY, (GLdouble)Win[0]/(GLdouble)Win[1], NEAR_CLIP, FAR_CLIP);
}



void display(void)
{
    updata_postion_angle(player);
    for (int i =0; i<enemy_list.size(); i++) {
        enemy_list[i].updata_postion(player);
    }
    for (int i =0; i<food_list.size(); i++) {
        food_list[i].updata_postion(player);
    }


    
    
    camXPos = player.x - player.dx * 10 - player.dx*player.dy*5;
    camYPos = player.y - player.dy* 10 - (-player.dx*player.dx-player.dz*player.dz)*5;
    camZPos = player.z - player.dz *10 -player.dz*player.dy*5;
    

    glui_Camera->sync_live();
    // Clear the screen with the background colour
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    
    // Setup the model-view transformation matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// Specify camera transformation
    
    gluLookAt(camXPos, camYPos, camZPos, player.x , player.y, player.z, 0, 1, 0);
    

    glPushMatrix();
    draw_xyz();
    draw_ground();
    draw_sky_box();
    

    glPopMatrix();


	glPushMatrix();


    
    
    
    

    player.draw_object();
    for (int i =0; i<enemy_list.size(); i++) {
        enemy_list[i].draw_object();
    }
    for (int i =0; i<food_list.size(); i++) {
        food_list[i].draw_object();
    }


    

    glPopMatrix();
	//
	// SAMPLE CODE **********

    // Execute any GL functions that are in the queue just to be safe
    glFlush();



    // Now, show the frame buffer that we just drew into.
    // (this prevents flickering).
    glutSwapBuffers();
}






// Draw a unit cube, centered at the current location
// README: Helper code for drawing a cube

///////////////////////////////////////////////////////////
//
// BELOW ARE FUNCTIONS FOR GENERATING IMAGE FILES (PPM/PGM)
//
///////////////////////////////////////////////////////////


#define RED_OFFSET   0
#define GREEN_OFFSET 1
#define BLUE_OFFSET  2


