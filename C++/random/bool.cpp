#include <iostream>
using namespace std;

#if 0
struct  StormControlPortAndTypeComp {
  static StrataCommonSmData::Ptr scsdPtr;
  bool operator() ( const StormControlPortAndType  &lhs,
		    const StormControlPortAndType  &rhs ) const {
    Arnet::IntfId lIntfId = scsdPtr->strataPortToIntf( lhs.sp() );
    Arnet::IntfId rIntfId = scsdPtr->strataPortToIntf( rhs.sp() );
    bool lbcast = lhs.bcast();
    bool rbcast = rhs.bcast();
    if ( ( lIntfId > rIntfId ) ||
	 ( ( lIntfId == rIntfId ) &&
	   ( lbcast > rbcast ) ) ) {
      return true;
    }
    return false;
  }
};
#endif
void foo( bool val, bool add ){
  cout << " val is " << val << endl;
  cout << " add is " << add << endl;
}
int main() {
  bool a(true);
  bool b(false);
  if ( a > b ) {
    cout << a << " is greater than " << b << endl;
  }
  foo( !"this is true", "add" );
  return 0;
}
