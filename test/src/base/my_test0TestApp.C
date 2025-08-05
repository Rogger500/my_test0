//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "my_test0TestApp.h"
#include "my_test0App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
my_test0TestApp::validParams()
{
  InputParameters params = my_test0App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

my_test0TestApp::my_test0TestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  my_test0TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

my_test0TestApp::~my_test0TestApp() {}

void
my_test0TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  my_test0App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"my_test0TestApp"});
    Registry::registerActionsTo(af, {"my_test0TestApp"});
  }
}

void
my_test0TestApp::registerApps()
{
  registerApp(my_test0App);
  registerApp(my_test0TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
my_test0TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  my_test0TestApp::registerAll(f, af, s);
}
extern "C" void
my_test0TestApp__registerApps()
{
  my_test0TestApp::registerApps();
}
