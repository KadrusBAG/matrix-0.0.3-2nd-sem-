#include <catch.hpp>
#include <sstream>
#include <cassert>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t<int> matrix;
    REQUIRE(matrix.rows() == 0);
    REQUIRE(matrix.collumns() == 0);
}

TEST_CASE("reading matrix")
{
    std::string input{ "3, 3\n"
                       "1 1 1\n"
                       "2 2 2\n"
                       "3 3 3" };
    matrix_t<int> matrix;
    std::istringstream istream{ input };

    REQUIRE(matrix.read(istream));
    REQUIRE(matrix.rows() == 3);
    REQUIRE(matrix.collumns() == 3);

    std::ostringstream ostream;
    matrix.write(ostream);

    REQUIRE(input == ostream.str());
}

TEST_CASE("reading float_matrix")
{
    std::string input{ "3, 3\n"
                       "1.2 1.3 1.4\n"
                       "2.3 2.4 2.5\n"
                       "3.4 3.5 3.6" };
    matrix_t<float> matrix;
    std::istringstream stream{ input };

    REQUIRE(matrix.read(stream));
    REQUIRE(matrix.rows() == 3);
    REQUIRE(matrix.collumns() == 3);

    std::ostringstream output;
    matrix.write(output);

    REQUIRE(input == output.str());
}

TEST_CASE("add matrix int")
{
    std::string stroka1{ "2, 3\n"
                         "1 1 1\n"
                         "2 2 2" };
    std::string stroka2{ "2, 3\n"
                         "2 2 2\n"
                         "1 1 1" };
    std::string stroka_result{ "2, 3\n"
                               "3 3 3\n"
                               "3 3 3" };

    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    result = matrix1 + matrix2;

    std::ostringstream ostream;
    result.write(ostream);

    REQUIRE(stroka_result == ostream.str());
}

TEST_CASE("add matrix float")
{
    std::string stroka1{ "2, 3\n"
                         "1.1 1.1 1.1\n"
                         "2.2 2.2 2.2" };
    std::string stroka2{ "2, 3\n"
                         "2.2 2.2 2.2\n"
                         "1.1 1.1 1.1" };
    std::string stroka_result{ "2, 3\n"
                               "3.3 3.3 3.3\n"
                               "3.3 3.3 3.3" };

    matrix_t<float> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    result = matrix1 + matrix2;

    std::ostringstream ostream;
    result.write(ostream);

    REQUIRE(stroka_result == ostream.str());
}

TEST_CASE("cheking add matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    std::string stroka2{ "3, 3\n"
                         "1 2 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    REQUIRE_THROWS_AS((matrix1 + matrix2), std::invalid_argument);
}

TEST_CASE("sub matrix")
{
    std::string stroka1{ "2, 3\n"
                         "3 3 3\n"
                         "3 3 3" };
    std::string stroka2{ "2, 3\n"
                         "2 2 2\n"
                         "1 1 1" };
    std::string stroka_result{ "2, 3\n"
                               "1 1 1\n"
                               "2 2 2" };

    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    result = matrix1 - matrix2;

    std::ostringstream ostream;
    result.write(ostream);

    REQUIRE(stroka_result == ostream.str());
}

TEST_CASE("cheking sub matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    std::string stroka2{ "3, 3\n"
                         "1 2 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    REQUIRE_THROWS_AS((matrix1 - matrix2), std::invalid_argument);
}

TEST_CASE("mul matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 2 3\n"
                         "4 5 6" };
    std::string stroka2{ "3, 2\n"
                         "1 4\n"
                         "2 5\n"
                         "3 6" };
    std::string stroka_result{ "2, 2\n"
                               "14 32\n"
                               "32 77" };

    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    result = matrix1 * matrix2;

    std::ostringstream ostream;
    result.write(ostream);

    REQUIRE(stroka_result == ostream.str());
}

TEST_CASE("cheking mul matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    std::string stroka2{ "2, 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    REQUIRE_THROWS_AS((matrix1 * matrix2), std::invalid_argument);
}

TEST_CASE("selfadd matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 1 1\n"
                         "2 2 2" };
    std::string stroka2{ "2, 3\n"
                         "2 2 2\n"
                         "1 1 1" };
    std::string stroka_result{ "2, 3\n"
                               "3 3 3\n"
                               "3 3 3" };

    matrix_t<int> matrix1, matrix2;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    matrix1 += matrix2;

    std::ostringstream ostream;
    matrix1.write(ostream);

    REQUIRE(stroka_result == ostream.str());
}

TEST_CASE("cheking selfadd matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    std::string stroka2{ "3, 3\n"
                         "1 2 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    REQUIRE_THROWS_AS((matrix1 += matrix2), std::invalid_argument);
}

TEST_CASE("selfsub matrix")
{
    std::string stroka1{ "2, 3\n"
                         "3 3 3\n"
                         "3 3 3" };
    std::string stroka2{ "2, 3\n"
                         "2 2 2\n"
                         "1 1 1" };
    std::string stroka_result{ "2, 3\n"
                               "1 1 1\n"
                               "2 2 2" };

    matrix_t<int> matrix1, matrix2;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    matrix1 -= matrix2;

    std::ostringstream ostream;
    matrix1.write(ostream);

    REQUIRE(stroka_result == ostream.str());
}

TEST_CASE("cheking selfsub matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    std::string stroka2{ "3, 3\n"
                         "1 2 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    REQUIRE_THROWS_AS((matrix1 -= matrix2), std::invalid_argument);
}

TEST_CASE("selfmul matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 2 3\n"
                         "4 5 6" };
    std::string stroka2{ "3, 2\n"
                         "1 4\n"
                         "2 5\n"
                         "3 6" };
    std::string stroka_result{ "2, 2\n"
                               "14 32\n"
                               "32 77" };

    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    matrix1 *= matrix2;

    std::ostringstream ostream;
    matrix1.write(ostream);

    REQUIRE(stroka_result == ostream.str());
}

TEST_CASE("cheking selfmul matrix")
{
    std::string stroka1{ "2, 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    std::string stroka2{ "2, 3\n"
                         "1 2 3\n"
                         "1 2 3" };
    matrix_t<int> matrix1, matrix2, result;
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };

    matrix1.read(istream1);
    matrix2.read(istream2);

    REQUIRE_THROWS_AS((matrix1 *= matrix2), std::invalid_argument);
}
