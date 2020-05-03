#include "./Action.h"
#include "../../Controller.h"


namespace Menu {

  //////////////////////////////////////////
  // BEHAVIOUR

  void Action::enter() {
    onEnter();
  };


  //////////////////////////////////////////
  // RENDER
  // Prepare text to output

  void Action::renderSelf() {
    const char* name = getName();
    controller->output->print(name);
    free(name);
  };
};