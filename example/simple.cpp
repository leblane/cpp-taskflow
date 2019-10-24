// A simple example to capture the following task dependencies.
//
// TaskA---->TaskB---->TaskD
// TaskA---->TaskC---->TaskD

#include <taskflow/taskflow.hpp>  // the only include you need

int main(){

  tf::Executor executor;
  tf::Taskflow taskflow;
  
  auto A = taskflow.emplace([](){ std::cout << "TaskA\n"; });
  auto B = taskflow.emplace([](){ std::cout << "TaskA\n"; });
  auto C = taskflow.emplace([](){ std::cout << "TaskA\n"; });
  auto D = taskflow.emplace([](){ std::cout << "TaskA\n"; });
                                        
  A.precede(B);  // B runs after A       //                                 
  A.precede(C);  // C runs after A       //          +---+                  
  B.precede(D);  // D runs after B       //    +---->| B |-----+            
  C.precede(D);  // D runs after C       //    |     +---+     |            
                                         //  +---+           +-v-+          
  executor.run(taskflow).wait();         //  | A |           | D |          
                                         //  +---+           +-^-+          
                                         //    |     +---+     |            
                                         //    +---->| C |-----+            
                                         //          +---+
  return 0;
}



