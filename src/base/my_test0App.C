#include "my_test0App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
my_test0App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

my_test0App::my_test0App(const InputParameters & parameters) : MooseApp(parameters)
{
  my_test0App::registerAll(_factory, _action_factory, _syntax);
}

my_test0App::~my_test0App() {}

void
my_test0App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<my_test0App>(f, af, syntax);
  Registry::registerObjectsTo(f, {"my_test0App"});
  Registry::registerActionsTo(af, {"my_test0App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
my_test0App::registerApps()
{
  registerApp(my_test0App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
my_test0App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  my_test0App::registerAll(f, af, s);
}
extern "C" void
my_test0App__registerApps()
{
  my_test0App::registerApps();
}
