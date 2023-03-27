//**********************************************************************************
// STEAMiE's Entry Point.
//**********************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "GLViewNewModule.h" //GLView subclass instantiated to drive this simulation

/**
   This creates a GLView subclass instance and begins the GLView's main loop.
   Each iteration of this loop occurs when a reset request is received. A reset
   request causes the entire GLView to be destroyed (since its exits scope) and
   begin again (simStatus == -1). This loop exits when a request to exit the 
   application is received (simStatus == 0 ).
*/
int main( int argc, char* argv[] )
{
	GLViewNewModule glviewNew;
 
   return glviewNew.onExecute();
}

