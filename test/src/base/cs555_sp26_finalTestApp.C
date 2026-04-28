//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "cs555_sp26_finalTestApp.h"
#include "cs555_sp26_finalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
cs555_sp26_finalTestApp::validParams()
{
  InputParameters params = cs555_sp26_finalApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

cs555_sp26_finalTestApp::cs555_sp26_finalTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  cs555_sp26_finalTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

cs555_sp26_finalTestApp::~cs555_sp26_finalTestApp() {}

void
cs555_sp26_finalTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  cs555_sp26_finalApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"cs555_sp26_finalTestApp"});
    Registry::registerActionsTo(af, {"cs555_sp26_finalTestApp"});
  }
}

void
cs555_sp26_finalTestApp::registerApps()
{
  registerApp(cs555_sp26_finalApp);
  registerApp(cs555_sp26_finalTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
cs555_sp26_finalTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cs555_sp26_finalTestApp::registerAll(f, af, s);
}
extern "C" void
cs555_sp26_finalTestApp__registerApps()
{
  cs555_sp26_finalTestApp::registerApps();
}
