#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t matrix<int>;
    REQUIRE( matrix.rows() == 0 );
    REQUIRE( matrix.collumns() == 0 );
}

TEST_CASE("reading matrix")
{
    std::string input{
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    matrix_t matrix<int>;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}

TEST_CASE("add matrix")
{
    std::string stroka1{
        "2, 3\n"
        "1.1 1.1 1.1\n"
        "2.2 2.2 2.2" }; 
    std::string stroka2{
        "2, 3\n"
        "2.2 2.2 2.2\n"
        "1.1 1.1 1.1" };
    std::string strokar{
        "2, 3\n"
        "3.3 3.3 3.3\n"
        "3.3 3.3 3.3" };
    
    matrix_t<float> matrix1, matrix2, result;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    result = matrix1 + matrix2;
    
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("sub matrix")
{
    std::string stroka1{
        "2, 3\n"
        "3.3 3.3 3.3\n"
        "3.3 3.3 3.3" };
    std::string stroka2{
        "2, 3\n"
        "2.2 2.2 2.2\n"
        "1.1 1.1 1.1" };
    std::string strokar{
        "2, 3\n"
        "1.1 1.1 1.1\n"
        "2.2 2.2 2.2" };
    
    matrix_t<float> matrix1, matrix2, result;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    result = matrix1 - matrix2;
    
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("mul matrix")
{
    std::string stroka1{
        "2, 3\n"
        "1 2 3\n"
        "4 5 6" }; 
    std::string stroka2{
        "3, 2\n"
        "1 4\n"
        "2 5\n"
        "3 6"  };
    std::string strokar{
        "2, 2\n"
        "14 32\n"
        "32 77" };
    
    matrix_t<int> matrix1, matrix2, result;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    result = matrix1 * matrix2;
    
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("selfsub matrix")
{
    std::string stroka1{
        "2, 3\n"
        "3.3 3.3 3.3\n"
        "3.3 3.3 3.3" }; 
    std::string stroka2{
        "2, 3\n"
        "2.2 2.2 2.2\n"
        "1.1 1.1 1.1" }; 
    std::string strokar{
        "2, 3\n"
        "1.1 1.1 1.1\n"
        "2.2 2.2 2.2" };
    
    matrix_t<float> matrix1, matrix2;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    matrix1 -= matrix2;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("selfadd matrix")
{
    std::string stroka1{
        "2, 3\n"
        "1.1 1.1 1.1\n"
        "2.2 2.2 2.2" }; 
    std::string stroka2{
        "2, 3\n"
        "2.2 2.2 2.2\n"
        "1.1 1.1 1.1" };
    std::string strokar{
        "2, 3\n"
        "3.3 3.3 3.3\n"
        "3.3 3.3 3.3" };
    
    matrix_t<float> matrix1, matrix2;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    matrix1 += matrix2;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("selfmul matrix")
{
    std::string stroka1{
        "2, 3\n"
        "1 2 3\n"
        "4 5 6" }; 
    std::string stroka2{
        "3, 2\n"
        "1 4\n"
        "2 5\n"
        "3 6"  };
    std::string strokar{
        "2, 2\n"
        "14 32\n"
        "32 77" };
    
    matrix_t<int> matrix1, matrix2;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    matrix1 *= matrix2;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}
