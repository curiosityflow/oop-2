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


  visitor* my_v = new multiply(new add( new Int(10)), new Int(8)), new subtract(new Int(3), new Int(1)));
  my_v.print();
  std::cout << " = " << my_v.eval() << std::endl;

  visitor* my_v2 = new add(new multiply( new Int(6)), new Int(12)), new divide(new Int(9), new Int(3)));
  my_v2.print();
  std::cout << " = " << my_v2.eval() << std::endl;

  visitor* my_v3 = new add(new subtract( new Int(30)), new Int(18)), new multiply(new Int(2), new Int(2)));
  my_v3.print();
  std::cout << " = " << my_v3.eval() << std::endl;

}
