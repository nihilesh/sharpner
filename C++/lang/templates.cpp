#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

using namespace std;

#if 0
namespace test1 {
typedef struct TabletBase_t {
    public:
        vector<uint64_t> u64_cells;
        vector<float> f64_cells;
}TabletBase;

template<class T>
T allOf_(T a, T b) {
    return T();
}

template<class T>
T opAverage__(T writeVal, T readVal, int count){
    assert(false && "average operatio not supported for this datatype");
}

template<>
float opAverage__<float>(float writeVal, float readVal, int count) {
    float sum = (float)writeVal + (float)readVal;
    return (float)(sum/count);
}

template<>
int opAverage__<int>(int writeVal, int readVal, int count) {
    cout << writeVal << " " << readVal << " " << count << endl;
    int sum = (int)writeVal + (int)readVal;
    cout << sum/count << " " << endl;
    return (int)(sum/count);
}

template<class T, int count=2>
T opAverage_(T writeVal, T readVal) {
    return opAverage__(writeVal, readVal, count);
}

template<class T, T(*Op)(T, T)>
T operate(T a, T b){
    T v = Op(a,b);
    cout << v << endl;
    return v;
}

} // Namespace

/**********************************/
struct Tablet;

using TabletPtr = Tablet *;
using RowIndex = int;
using U64 = unsigned long;

struct Tablet {
    U64 u64Cell(int rowId) {return 2;}
    void u64CellIs(int rowId, U64 val) {
        cout << "rowID: " << rowId << " value: " << val << endl;
    }
};

namespace test2 {

template <class T>
class AggregatorBase {
public:
//    virtual void anyOf() = 0 ;
//    virtual void average(unsigned int count) = 0 ;
//    virtual void min() = 0 ;
//    virtual void max() = 0 ;
//    virtual void last() = 0 ;
    TabletPtr writeTablet;
    TabletPtr readTablet;
    RowIndex writeRowIdx;
    RowIndex readRowIdx;

   virtual T getCell(const TabletPtr tablet, RowIndex idx) = 0;
   virtual void setCell(TabletPtr tablet, RowIndex idx, T val) = 0;

   virtual void allOf(){
       cout << "All of" << endl;
       T writeVal = getCell(writeTablet, writeRowIdx);
       T readVal = getCell(readTablet, readRowIdx);
       setCell(writeTablet, writeRowIdx, readVal ? writeVal : readVal);
   }

};


template<class T>
class SeamAggregator : public AggregatorBase<T> {
};

template<>
class SeamAggregator<U64> : public AggregatorBase<U64> {
public:
   U64 getCell(const TabletPtr tablet, RowIndex idx) {
       return tablet->u64Cell(idx);
   }
   void setCell(TabletPtr tablet, RowIndex idx, U64 val) {
       tablet->u64CellIs(idx, val);
   }
   using AggregatorBase::allOf;
};

// int main() {
//     SeamAggregator<U64> u64Aggregator;
//     Tablet writeTablet, readTablet;
//     u64Aggregator.writeTablet = &writeTablet;
//     u64Aggregator.readTablet = &readTablet;
//     u64Aggregator.writeRowIdx = u64Aggregator.readRowIdx = 3;
//     u64Aggregator.allOf();
// }

} // Namespace test2 
#endif
/* ----------------------------------------------------------------------*/

#ifdef 0
namespace {
    struct Tablet {
        void boolCellIs(int index, bool val) {
            cout <<"Bool cell is: " << val << endl;
        }
        void intCellIs(int index, int val) {
            cout <<"Bool cell is: " << val << endl;
        }
        void stringCellIs(int index, string val) {
            cout <<"Bool cell is: " << val << endl;
        }
        int intCell(int index) const { return 9; }
        string stringCell(int index) const { return "device-1"; }
        bool boolCell(int index) const { return false; }
    };

    template <class T>
    struct CellAccessor {
    public:
        static T getCell(const Tablet& tablet, int index){}
        static void setCell(Tablet& tablet, int index, T val){}
    };
    
    template<>
    struct CellAccessor<int> {
        static int getCell(const Tablet& tablet, int index){return tablet.intCell(index);}
        static void setCell(Tablet& tablet, int index, int val){tablet.intCellIs(index, val);}
    };

    template<>
    struct CellAccessor<string> {
        static string getCell(const Tablet& tablet, int index){return tablet.stringCell(index);}
        static void setCell(Tablet& tablet, int index, string val){tablet.stringCellIs(index, val);}
    };

    template<>
    struct CellAccessor<bool> {
        static bool getCell(const Tablet& tablet, int index){return tablet.boolCell(index);}
        static void setCell(Tablet& tablet, int index, bool val){tablet.boolCellIs(index, val);}
    };


    template <class T>
    void allOf(Tablet& writeTablet, Tablet& readTablet, int readIdx, int writeIdx){
        auto readVal = CellAccessor<T>::getCell(readTablet, readIdx);
        auto writeVal = CellAccessor<T>::getCell(readTablet, readIdx);
        CellAccessor<T>::setCell(writeTablet, writeIdx, readVal ? writeVal: 0);
    }
    template<>
    void allOf<int>(Tablet& writeTablet, Tablet& readTablet, int readIdx, int writeIdx){
        auto readVal = CellAccessor<int>::getCell(readTablet, readIdx);
        auto writeVal = CellAccessor<int>::getCell(readTablet, readIdx);
        CellAccessor<int>::setCell(writeTablet, writeIdx, readVal ? writeVal: 0);
    }

    template <class T>
    void average(Tablet& writeTablet, Tablet& readTablet, int readIdx, int writeIdx, int count) {
        assert(false);
    }

    template <>
    void average<int> (Tablet& writeTablet, Tablet& readTablet, int readIdx, int writeIdx, int count) {
        auto readVal = CellAccessor<int>::getCell(readTablet, readIdx);
        auto writeVal = CellAccessor<int>::getCell(readTablet, readIdx);
        CellAccessor<int>::setCell(writeTablet, writeIdx, readVal + writeVal / count);
    }

    struct SeamAggregator {
        SeamAggregator(
                Tablet* writeTablet, 
                const Tablet* readTablet) : writeTablet(writeTablet), readTablet(readTablet) {}

        const unordered_map <int, void*> avgFuncMap = {
            {1, (void*)&average<int>},
            {2, (void*)&average<float>},
        };

        void allOf(int type, int readIdx, int writeIdx){
            switch(type) {
            case 1:
            {
                auto readVal = CellAccessor<int>::getCell(*readTablet, readIdx);
                auto writeVal = CellAccessor<int>::getCell(*writeTablet, writeIdx);
                cout << "allOf(" << type << "," << readIdx << "," << writeIdx << ")" << endl;
                break;
            }
            case 2:
            {
                auto readVal = CellAccessor<int>::getCell(*readTablet, readIdx);
                auto writeVal = CellAccessor<int>::getCell(*writeTablet, writeIdx);
                cout << "allOf(" << type << "," << readIdx << "," << writeIdx << ")" << endl;
                break;
            }
            default:
                assert(false && "type not supported");            
            }
        }

        Tablet *writeTablet; 
        const Tablet *readTablet;
    };
} // Namespace
#endif 

namespace {
    template <typename T>
    class SeamAggregator {
        T average(T a, T b, int count){
            return a+b/count;
        }
    };
}

int main() {
    Tablet writeTablet, readTablet;
    SeamAggregator sAggr(&writeTablet, &readTablet);
    sAggr.allOf(1, 2, 3);
}