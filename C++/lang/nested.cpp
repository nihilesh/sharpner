#include <iostream>

class Outer {
   int i, j;
   void data() {
	std::cout << "callback " << std::endl;
   }

   class Inner {
     Outer *parent;
   protected:
     friend class Outer;
   public:
     Inner(Outer *parent) : parent(parent) {}
     void printData(){
	//std::cout << "I: " << Outer::i << ", J: " << parent->j << std::endl;
	std::cout << "I: " << parent->i << ", J: " << parent->j << std::endl;
        data();
        parent->data();
     }
     
   };
   Inner *in;
  
public:
   Outer(int i, int j) : i(i), j(j) {
       in = new Inner(this);
   }

   ~Outer () {
      delete(in);
      in = NULL;
   }
  
   void printData() {
       in->printData();	   
   }
};

int main() {
   Outer o(2, 3);
   o.printData();
   return 0;
}
