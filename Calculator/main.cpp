// B. Maritza Trevizo Nava

#include <iostream>

// Test cases
int main() {

  Expression* my_exp = new multiply(new add( new Int(10)), new Int(8)), new subtract(new Int(3), new Int(1)));
  my_exp.print();
  std::cout << " = " << my_exp.eval() << std::endl;

  Expression* my_exp2 = new add(new multiply( new Int(6)), new Int(12)), new divide(new Int(9), new Int(3)));
  my_exp2.print();
  std::cout << " = " << my_exp2.eval() << std::endl;

  Expression* my_exp3 = new add(new subtract( new Int(30)), new Int(18)), new multiply(new Int(2), new Int(2)));
  my_exp3.print();
  std::cout << " = " << my_exp3.eval() << std::endl;


  Expression* my_v = new multiply(new add( new Int(10)), new Int(8)), new subtract(new Int(3), new Int(1)));
  print(my_v);
  std::cout << " = " << eval(my_v) << std::endl;

  Expression* my_v2 = new add(new multiply( new Int(6)), new Int(12)), new divide(new Int(9), new Int(3)));
  print(my_v2);
  std::cout << " = " << eval(my_v2) << std::endl;

  Expression* my_v3 = new add(new subtract( new Int(30)), new Int(18)), new multiply(new Int(2), new Int(2)));
  print(my_v3);
  std::cout << " = " << eval(my_v3) << std::endl;

}
