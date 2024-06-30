#define NO_EXP10F
#define NO_EXP10

#include <fx.h>

#include <iostream>

// Define a main window class
class HelloWorldWindow : public FXMainWindow {
  FXDECLARE(HelloWorldWindow)
protected:
  HelloWorldWindow(){}

public:
  HelloWorldWindow(FXApp* app);
  virtual void create();
  long onCmdHello(FXObject*, FXSelector, void*);

  enum {
    ID_HELLO = FXMainWindow::ID_LAST,
    ID_LAST
  };
};

// Implement the message map for HelloWorldWindow
FXDEFMAP(HelloWorldWindow) HelloWorldWindowMap[] = {
  FXMAPFUNC(SEL_COMMAND, HelloWorldWindow::ID_HELLO, HelloWorldWindow::onCmdHello),
};

// Macro to implement the FXMainWindow interface
FXIMPLEMENT(HelloWorldWindow, FXMainWindow, HelloWorldWindowMap, ARRAYNUMBER(HelloWorldWindowMap))

HelloWorldWindow::HelloWorldWindow(FXApp* app) : FXMainWindow(app, "Hello World", nullptr, nullptr, DECOR_ALL, 0, 0, 400, 200) {
  // Create a button that sends the ID_HELLO message when clicked
  new FXButton(this, "Hello, World!", nullptr, this, ID_HELLO, FRAME_THICK | FRAME_RAISED | LAYOUT_CENTER_X | LAYOUT_CENTER_Y);
}

void HelloWorldWindow::create() {
  FXMainWindow::create();
  show(PLACEMENT_SCREEN);
}

long HelloWorldWindow::onCmdHello(FXObject*, FXSelector, void*) {
  FXMessageBox::information(this, MBOX_OK, "Hello", "Hello, World!");
  return 1;
}

int main(int argc, char* argv[]) {
  try {
    // Make application
    FXApp application("Hello", "FoxTest");

    // Open the display
    application.init(argc, argv);

    // Make the main window
    new HelloWorldWindow(&application);

    // Create the application's windows
    application.create();

    // Run the application
    return application.run();
  } catch (FXException& e) {
    std::cerr << "An error occurred: " << e.what() << std::endl;
    return 1;
  }
}