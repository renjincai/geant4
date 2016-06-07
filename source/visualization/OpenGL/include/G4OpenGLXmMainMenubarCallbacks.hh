// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLXmMainMenubarCallbacks.hh,v 2.0 1998/07/02 16:45:03 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
//

#ifdef G4VIS_BUILD_OPENGLXM_DRIVER

#ifndef G4OPENGLXMMAINMENUBARCALLBACKS_HH
#define G4OPENGLXMMAINMENUBARCALLBACKS_HH

#include "G4OpenGLXmView.hh"

void misc_callback (Widget w, XtPointer clientData, XtPointer callData);
void actions_callback (Widget w, XtPointer clientData, XtPointer callData);
void update_panels_callback (Widget w, XtPointer clientData, XtPointer callData);

#endif

#endif