// Demonstrates the use of observer to monitor worker activities

#include <taskflow/taskflow.hpp>

int main(){
  
  tf::Executor executor;
  
  // Create a taskflow of eight tasks
  tf::Taskflow taskflow;

  auto A = taskflow.emplace([] () { std::cout << "1\n"; } );
  auto B = taskflow.emplace([] () { std::cout << "1\n"; } );
  auto C = taskflow.emplace([] () { std::cout << "1\n"; } );
  auto D = taskflow.emplace([] () { std::cout << "1\n"; } );
  auto E = taskflow.emplace([] () { std::cout << "1\n"; } );
  auto F = taskflow.emplace([] () { std::cout << "1\n"; } );
  auto G = taskflow.emplace([] () { std::cout << "1\n"; } );
  auto H = taskflow.emplace([] () { std::cout << "1\n"; } );

  A.name("A");
  B.name("B");
  C.name("C");
  D.name("D");
  E.name("E");
  F.name("F");
  G.name("G");
  H.name("H");
  
  // create a default observer
  auto observer = executor.make_observer<tf::ExecutorObserver>();

  // run the taskflow
  executor.run(taskflow).get();
  
  // dump the execution timeline to json (view at chrome://tracing)
  observer->dump(std::cout);

  return 0;
}

