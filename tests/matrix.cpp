#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t matrix;
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
    matrix_t matrix;
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
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string stroka2{
        "3, 4\n"
        "7 2 2 7\n"
        "1 5 2 6\n"
        "2 2 8 5" };
    std::string strokar{
        "3, 4\n"
        "8 3 6 12\n"
        "3 6 4 12\n"
        "11 5 11 12" };
    
    matrix_t matrix1, matrix2, result;   
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
        "3, 4\n"
        "8 3 6 12\n"
        "3 6 4 12\n"
        "11 5 11 12" };
    std::string stroka2{
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string strokar{
        "3, 4\n"
        "7 2 2 7\n"
        "1 5 2 6\n"
        "2 2 8 5" };
    
    matrix_t matrix1, matrix2, result;   
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
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string stroka2{
        "4, 3\n"
        "7 2 2 \n"
        "1 5 2 \n"
        "2 2 8 \n" 
        "1 1 1" };
    std::string strokar{
        "3, 3\n"
        "21 20 41\n"
        "25 19 28\n"
        "79 46 55" };
    
    matrix_t matrix1, matrix2, result;   
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
        "3, 4\n"
        "8 3 6 12\n"
        "3 6 4 12\n"
        "11 5 11 12" };
    std::string stroka2{
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string strokar{
        "3, 4\n"
        "7 2 2 7\n"
        "1 5 2 6\n"
        "2 2 8 5" };
    
    matrix_t matrix1, matrix2;   
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
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string stroka2{
        "3, 4\n"
        "7 2 2 7\n"
        "1 5 2 6\n"
        "2 2 8 5" };
    std::string strokar{
        "3, 4\n"
        "8 3 6 12\n"
        "3 6 4 12\n"
        "11 5 11 12" };
    
    matrix_t matrix1, matrix2;   
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
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string stroka2{
        "4, 3\n"
        "7 2 2 \n"
        "1 5 2 \n"
        "2 2 8 \n" 
        "1 1 1" };
    std::string strokar{
        "3, 3\n"
        "21 20 41\n"
        "25 19 28\n"
        "79 46 55" };
    
    matrix_t matrix1, matrix2;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    matrix1 *= matrix2;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}
