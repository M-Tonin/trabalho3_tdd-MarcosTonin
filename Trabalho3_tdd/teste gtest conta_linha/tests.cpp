 // tests.cpp
#include "contador.cpp"
#include <gtest/gtest.h>

ifstream arq,arq1,arq2;
 
TEST(abrirArquivo, teste_abrir) { 
      ASSERT_EQ(1, abrir_arquivo("sdasd.c",arq));	
      ASSERT_EQ(1, abrir_arquivo("sdasf.c",arq1));
	  ASSERT_EQ(0, abrir_arquivo("sdasf1234154.c",arq2));
  //  ASSERT_NE(NULL, createStack(3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
