#include<igloo/igloo_alt.h>
#include<rangetools>

using namespace rangetools;
using namespace igloo;
using namespace std;


Describe(rangeToolsTestcase)
{
  Describe(genericTests){

    struct test{
      template<class T>
      int next(T);
    };

    It(should_detect_callability){
      Assert::That( has_next<test,int>() , Equals(1) );
      Assert::That( has_next<int,int>() , Equals(0) );
    }
  };

  Describe(RangeTest){
    It(should_count_from_0_to_4){
      int i=0;
      for( auto j : gen*Range(5) ){
        Assert::That( j == i );
        ++i;
      }
      Assert::That(i==5);
    }

    It(should_be_composable_and_count_from_5_to_9){
      int i=5;
      for( auto j : gen*Range(5) | gen*Range(5,10) ){
        Assert::That( j == i );
        ++i;
      }
      Assert::That(i==10);
    }


  };



};

int main(int argc, char const* argv[])
{
  return TestRunner::RunAllTests(argc, argv);
}
