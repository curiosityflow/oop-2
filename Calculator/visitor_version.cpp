// B. Maritza Trevizo Nava

struct visitor {
    virtual void visit(Int *e)=0;
    virtual void visit(add *e)=0;
    virtual void visit(subtract *e)=0;
    virtual void visit(multiply *e)=0;
    virtual void visit(divide *e)=0;
};

struct eval_visitor:visitor {
    int ret;
    void visit(Int *e) override {
      ret = e->val;
    }
    void visit(add *e) override {
      eval_visitor v1;
      e->e1->accept(v1);
      eval_visitor v2;
      e->e2->accept(v2);

      ret = v1.ret + v2.ret;
    }
    void visit(subtract *e) override {
      eval_visitor v1;
      e->e1->accept(v1);
      eval_visitor v2;
      e->e2->accept(v2);

      ret = v1.ret - v2.ret;

    }
    void visit(multiply *e) override {
      eval_visitor v1;
      e->e1->accept(v1);
      eval_visitor v2;
      e->e2->accept(v2);

      ret = v1.ret * v2.ret;

    }
    void visit(divide *e) override {
      eval_visitor v1;
      e->e1->accept(v1);
      eval_visitor v2;
      e->e2->accept(v2);

      ret = v1.ret / v2.ret;

    }
};

struct Expression {
  virtual ~Expression = default;
  virtual void accept(visitor &v) = 0;
  virtual Expression* clone()=0;
};

struct Int:Expression{
  Int(int v):val(v){}
  int val;
  void accept(visitor &v) override {
    v.visit(this);
  }

  Expression* clone(){
    return new Int(v);
  }
};

struct Binary:Expression{
  Binary(Expression *e1, Expression *e2):e1(e1), e2(e2) {}

  Expression *e1;
  Expression *e2;

  ~Binary() {
    delete e1;
    delete e2;
  }
};

struct add:Binary {
  using Binary::Binary();

  void accept(visitor &v) override {
    v.visit(this);
  }

  Expression* clone(){
    return new add(*this);
  }
};

struct subtract:Binary {
  using Binary::Binary();

  void accept(visitor &v) override {
    v.visit(this);
  }

  Expression* clone(){
    return new subtract(*this);
  }
};

struct multiply:Binary {
  using Binary::Binary();

  void accept(visitor &v) override {
    v.visit(this);
  }

  Expression* clone(){
    return new multiply(*this);
  }
};

struct divide:Binary {
  using Binary::Binary();

  void accept(visitor &v) override {
    v.visit(this);
  }

  Expression* clone(){
    return new divide(*this);
  }
};

int eval(Expression *e) {
  eval_visitor ev;
  e->accept(ev);
  return ev.ret;
}

struct print_visitor:visitor {
  void visit(Int *e) override{
    std::cout << e->val;
  }
  void visit(add *e) override {
    std::cout << '(';
    print_visitor v1;
    e->e1.accept(v1);
    std::cout << ") + (";
    print_visitor v2;
    e->e2.accept(v2);
    std::cout << ')';
  }

  void visit(subtract *e) override {
    std::cout << '(';
    print_visitor v1;
    e->e1.accept(v1);
    std::cout << ") - (";
    print_visitor v2;
    e->e2.accept(v2);
    std::cout << ')';
  }

  void visit(multiply *e) override {
    std::cout << '(';
    print_visitor v1;
    e->e1.accept(v1);
    std::cout << ") * (";
    print_visitor v2;
    e->e2.accept(v2);
    std::cout << ')';
  }

  void visit(divide *e) override {
    std::cout << '(';
    print_visitor v1;
    e->e1.accept(v1);
    std::cout << ") / (";
    print_visitor v2;
    e->e2.accept(v2);
    std::cout << ')';
  }

};


void print(Expression *e) {
  print_visitor pv;
  e->accept(pv);
}
