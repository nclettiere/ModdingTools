#pragma once

#include "fx.h"

class ScribbleWindow : public FXMainWindow {

  // Macro for class hierarchy declarations
  FXDECLARE(ScribbleWindow)

private:
  FXHorizontalFrame *contents;  // Content frame
  FXVerticalFrame *canvasFrame; // Canvas frame
  FXVerticalFrame *buttonFrame; // Button frame
  FXCanvas *canvas;             // Canvas to draw into
  int mdflag;                   // Mouse button down?
  int dirty;                    // Canvas has been painted?
  FXColor drawColor;            // Color for the line

protected:
  ScribbleWindow() {}

  long onSomeCommand(FXObject *sender, FXSelector sel, void *ptr);

public:
  // Message handlers
  long onPaint(FXObject *, FXSelector, void *);
  long onMouseDown(FXObject *, FXSelector, void *);
  long onMouseUp(FXObject *, FXSelector, void *);
  long onMouseMove(FXObject *, FXSelector, void *);
  long onCmdClear(FXObject *, FXSelector, void *);
  long onUpdClear(FXObject *, FXSelector, void *);



public:
  // Messages for our class
  enum { ID_CANVAS = FXMainWindow::ID_LAST, ID_CLEAR, ID_LAST };

public:
  // ScribbleWindow's constructor
  ScribbleWindow(FXApp *a);

  // Initialize
  //virtual void create();

  virtual ~ScribbleWindow() = default;
};