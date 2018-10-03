 // tests.cpp
#include "contador.cpp"
#include <gtest/gtest.h>
 
TEST(createStack, PositiveNos) { 
      ASSERT_EQ(0, createStack(-3));	
      ASSERT_EQ(0, createStack(-3));
  //  ASSERT_NE(NULL, createStack(3));
}
pilha * p = createStack(2);
dado *retorno = (dado *)malloc(sizeof(dado)); 
TEST(pop, pop_vazio_isEmpty) {
    ASSERT_EQ(1,isEmpty(p));
    ASSERT_EQ(0,size(p));
    ASSERT_EQ(0,pop(p));
    ASSERT_EQ(0,top(retorno,p));
}
 TEST(push_top, push_size_isFull_isEmpty) {
    
    ASSERT_EQ(1,push(3,p));
    ASSERT_EQ(0,isEmpty(p));
    ASSERT_EQ(0,isFull(p));
    ASSERT_EQ(1,size(p));
    ASSERT_EQ(1,top(retorno,p));
    ASSERT_EQ(3,*retorno);
    ASSERT_EQ(1,push(21,p));
    ASSERT_EQ(1,isFull(p));
    ASSERT_EQ(2,size(p));
    ASSERT_EQ(1,top(retorno,p));
    ASSERT_EQ(21,*retorno);
    ASSERT_EQ(0,push(13,p));
    ASSERT_EQ(2,size(p));
    ASSERT_EQ(1,top(retorno,p));
    ASSERT_EQ(21,*retorno);
}

TEST(set_size, size) {
    ASSERT_EQ(0,set_size(-1,p));
    ASSERT_EQ(1,set_size(1,p));
    ASSERT_EQ(1,set_size(5,p));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
