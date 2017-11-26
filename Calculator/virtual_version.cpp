//B. Maritza Trevizo Nava

struct Expression {
  virtual ~Expression()=0;
  virtual Expression* clone()=0;
  virtual void print()=0;
  virtual  Int eval()=0;
};

struct Int:Expression {
  Int(int v):val(v) {}
  int val;

  void print() override{
    cout << v;
  }

  Int eval() override {
    return val;
  }

  Expression* clone(){
    return new Int(v);
  }
};

struct Binary:Expression() {
  Binary(Expression* e1, Expression* e2):e1(e1),e2(e2) {}
  Expression* e1;
  Expression* e2;

  ~Binary() {
    delete e1;
    delete e2;
  }
};

struct add:Binary {
  using Binary::Binary();
  int eval() override {
  int i1 = e1->evaluate();
  int i2 = e2->evaluate();
  return i1 + i2;
  }

  Expression* clone(){
    return new add(*this);
  }

  void print() override {
    cout << '(';
    e1.print();
    cout << ") + (";
    e2.print();
    cout << ')';

  }
};


struct subtract:Binary {
  using Binary::Binary();
  int eval() override {
  int i1 = e1->evaluate();
  int i2 = e2->evaluate();
  return i1 - i2;
  }

  Expression* clone(){
    return new subtract(*this);
  }

  void print() override {
    cout << '(';
    e1.print();
    cout << ") - (";
    e2.print();
    cout << ')';

  }
};


struct multiply:Binary {
  using Binary::Binary();
  int eval() override {
  int i1 = e1->evaluate();
  int i2 = e2->evaluate();
  return i1 * i2;
  }

  Expression* clone(){
    return new multiply(*this);
  }

  void print() override {
    cout << '(';
    e1.print();
    cout << ") * (";
    e2.print();
    cout << ')';

  }
};

struct divide:Binary {
  using Binary::Binary();
  int eval() override {
  int i1 = e1->evaluate();
  int i2 = e2->evaluate();
  return i1 / i2;
  }

  Expression* clone(){
    return new divide(*this);
  }

  void print() override {
    cout << '(';
    e1.print();
    cout << ") / (";
    e2.print();
    cout << ')';

  }
};
