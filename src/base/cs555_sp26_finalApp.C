#include "cs555_sp26_finalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
cs555_sp26_finalApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

cs555_sp26_finalApp::cs555_sp26_finalApp(const InputParameters & parameters) : MooseApp(parameters)
{
  cs555_sp26_finalApp::registerAll(_factory, _action_factory, _syntax);
}

cs555_sp26_finalApp::~cs555_sp26_finalApp() {}

void
cs555_sp26_finalApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<cs555_sp26_finalApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"cs555_sp26_finalApp"});
  Registry::registerActionsTo(af, {"cs555_sp26_finalApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
cs555_sp26_finalApp::registerApps()
{
  registerApp(cs555_sp26_finalApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
cs555_sp26_finalApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cs555_sp26_finalApp::registerAll(f, af, s);
}
extern "C" void
cs555_sp26_finalApp__registerApps()
{
  cs555_sp26_finalApp::registerApps();
}
