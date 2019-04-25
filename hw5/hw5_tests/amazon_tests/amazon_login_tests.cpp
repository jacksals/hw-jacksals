//
// CS104
// Test of login/logout functionality for Amazon
//


#include "amazon_checker.h"

#include "Utility.h"
#include "DatabaseParser.h"
#include "ConsoleParser.h"

#include <gtest/gtest.h>


TEST(AmazonLogin, LoginOnly)
{
    std::string const commands =
            "LOGIN jdoe\n"
            "QUIT database.out\n";

    std::string const expectedOutput =
            "Read 1 products\n"
            "Read 1 users\n"
            "=====================================\n"
            "Menu: \n"
            "  AND term term ...                  \n"
            "  OR term term ...                   \n"
            "  ADD username search_hit_number     \n"
            "  VIEWCART username                  \n"
            "  BUYCART username                   \n"
            "  QUIT new_db_filename               \n"
            "====================================\n"
            "\n"
            "Enter command: \n"
            "\n"
            "Enter command: ";


    std::string const inputDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano\n"
            "</products>\n"
            "<users>\n"
            "jdoe 100.0 0\n"
            "</users>\n"
            "<reviews>\n"
            "Data Abstraction\n"
            "3 jdoe 1999-09-09 Too abstract.\n"
            "</reviews>";

    EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Input}, expectedOutput));
}

TEST(AmazonLogin, LoginLogout)
{
    std::string const commands =
            "LOGIN jdoe\n"
            "LOGOUT\n"
            "QUIT database.out\n";

    std::string const expectedOutput =
            "Read 1 products\n"
            "Read 1 users\n"
            "=====================================\n"
            "Menu: \n"
            "  AND term term ...                  \n"
            "  OR term term ...                   \n"
            "  ADD username search_hit_number     \n"
            "  VIEWCART username                  \n"
            "  BUYCART username                   \n"
            "  QUIT new_db_filename               \n"
            "====================================\n"
            "\n"
            "Enter command: \n"
            "\n"
            "Enter command: \n"
            "\n"
            "Enter command: ";


    std::string const inputDatabase =
            "<products>\n"
            "book\n"
            "Data Abstraction\n"
            "79.99\n"
            "20\n"
            "978-013292372-9\n"
            "Carrano\n"
            "</products>\n"
            "<users>\n"
            "jdoe 100.0 0\n"
            "</users>\n"
            "<reviews>\n"
            "Data Abstraction\n"
            "3 jdoe 1999-09-09 Too abstract.\n"
            "</reviews>";

    EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Input, Input}, expectedOutput));
}

TEST(AmazonLogin, InvalidUsername)
{
        std::string const commands =
                "LOGIN janedoe\n"
                "QUIT database.out\n";

        std::string const expectedOutput =
                "Read 1 products\n"
                "Read 1 users\n"
                "=====================================\n"
                "Menu: \n"
                "  AND term term ...                  \n"
                "  OR term term ...                   \n"
                "  ADD username search_hit_number     \n"
                "  VIEWCART username                  \n"
                "  BUYCART username                   \n"
                "  QUIT new_db_filename               \n"
                "====================================\n"
                "\n"
                "Enter command: \n"
                "Invalid user\n"
                "\n"
                "Enter command: ";


        std::string const inputDatabase =
                "<products>\n"
                "book\n"
                "Data Abstraction\n"
                "79.99\n"
                "20\n"
                "978-013292372-9\n"
                "Carrano\n"
                "</products>\n"
                "<users>\n"
                "jdoe 100.0 0\n"
                "</users>\n"
                "<reviews>\n"
                "Data Abstraction\n"
                "3 jdoe 1999-09-09 Too abstract.\n"
                "</reviews>";

        EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, InvalidUser, Input}, expectedOutput));
}

TEST(AmazonLogin, BuyWithoutLogin)
{
        std::string const commands =
                "OR r Abstraction\n"
                "ADD 1\n"
                "LOGIN jdoe\n"
                "ADD 1\n"
                "VIEWCART\n"
                "QUIT database.out\n";

        std::string const expectedOutput =
                "Read 1 products\n"
                "Read 1 users\n"
                "=====================================\n"
                "Menu: \n"
                "  AND term term ...                  \n"
                "  OR term term ...                   \n"
                "  ADD username search_hit_number     \n"
                "  VIEWCART username                  \n"
                "  BUYCART username                   \n"
                "  QUIT new_db_filename               \n"
                "====================================\n"
                "\n"
                "Enter command: \n"
                "Hit   1\n"
                "Data Abstraction\n"
                "Author: Carrano ISBN: 978-013292372-9\n"
                "79.99 20 left.\n"
                "Rating: 3.00\n"
                "\n"
                "\n"
                "Enter command: \n"
                "No current user\n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: \n"
                "Item   1\n"
                "Data Abstraction\n"
                "Author: Carrano ISBN: 978-013292372-9\n"
                "79.99 20 left.\n"
                "Rating: 3.00\n"
                "\n"
                "\n"
                "Enter command: ";


        std::string const inputDatabase =
                "<products>\n"
                "book\n"
                "Data Abstraction\n"
                "79.99\n"
                "20\n"
                "978-013292372-9\n"
                "Carrano\n"
                "</products>\n"
                "<users>\n"
                "jdoe 100.0 0\n"
                "</users>\n"
                "<reviews>\n"
                "Data Abstraction\n"
                "3 jdoe 1999-09-09 Too abstract.\n"
                "</reviews>";

        EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input, NoUser, Input, Input, Cart, Input}, expectedOutput));
}



TEST(AmazonLogin, BuyItem)
{
        std::string const commands =
                "OR r Abstraction\n"
                "LOGIN jdoe\n"
                "ADD 1\n"
                "BUYCART\n"
                "QUIT database.out\n";

        std::string const expectedOutput =
                "Read 1 products\n"
                "Read 1 users\n"
                "=====================================\n"
                "Menu: \n"
                "  AND term term ...                  \n"
                "  OR term term ...                   \n"
                "  ADD username search_hit_number     \n"
                "  VIEWCART username                  \n"
                "  BUYCART username                   \n"
                "  QUIT new_db_filename               \n"
                "====================================\n"
                "\n"
                "Enter command: \n"
                "Hit   1\n"
                "Data Abstraction\n"
                "Author: Carrano ISBN: 978-013292372-9\n"
                "79.99 20 left.\n"
                "Rating: 3.00\n"
                "\n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: ";


        std::string const inputDatabase =
                "<products>\n"
                "book\n"
                "Data Abstraction\n"
                "79.99\n"
                "20\n"
                "978-013292372-9\n"
                "Carrano\n"
                "</products>\n"
                "<users>\n"
                "jdoe 100.0 0\n"
                "thatguy 5.0 0\n"
                "fhqwhgads 100.0 0\n"
                "</users>\n"
                "<reviews>\n"
                "Data Abstraction\n"
                "3 jdoe 1999-09-09 Too abstract.\n"
                "</reviews>";

        std::string const expectedDatabase =
                "<products>\n"
                "book\n"
                "Data Abstraction\n"
                "79.99\n"
                "19\n"
                "978-013292372-9\n"
                "Carrano\n"
                "</products>\n"
                "<users>\n"
                "jdoe 20.01 0\n"
                "thatguy 5.0 0\n"
                "fhqwhgads 100.0 0\n"
                "</users>\n"
                "<reviews>\n"
                "Data Abstraction\n"
                "3 jdoe 1999-09-09 Too abstract.\n"
                "</reviews>";

        EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input, Input, Input, Input}, expectedOutput));
        EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));

}

TEST(AmazonLogin, SwitchAccountBuyItem)
{
        std::string const commands =
                "OR r Abstraction\n"
                "LOGIN jdoe\n"
                "LOGOUT\n"
                "LOGIN fhqwhgads\n"
                "ADD 1\n"
                "BUYCART\n"
                "QUIT database.out\n";

        std::string const expectedOutput =
                "Read 1 products\n"
                "Read 1 users\n"
                "=====================================\n"
                "Menu: \n"
                "  AND term term ...                  \n"
                "  OR term term ...                   \n"
                "  ADD username search_hit_number     \n"
                "  VIEWCART username                  \n"
                "  BUYCART username                   \n"
                "  QUIT new_db_filename               \n"
                "====================================\n"
                "\n"
                "Enter command: \n"
                "Hit   1\n"
                "Data Abstraction\n"
                "Author: Carrano ISBN: 978-013292372-9\n"
                "79.99 20 left.\n"
                "Rating: 3.00\n"
                "\n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: ";


        std::string const inputDatabase =
                "<products>\n"
                "book\n"
                "Data Abstraction\n"
                "79.99\n"
                "20\n"
                "978-013292372-9\n"
                "Carrano\n"
                "</products>\n"
                "<users>\n"
                "jdoe 100.0 0\n"
                "thatguy 5.0 0\n"
                "fhqwhgads 100.0 0\n"
                "</users>\n"
                "<reviews>\n"
                "Data Abstraction\n"
                "3 jdoe 1999-09-09 Too abstract.\n"
                "</reviews>";

        std::string const expectedDatabase =
                "<products>\n"
                "book\n"
                "Data Abstraction\n"
                "79.99\n"
                "19\n"
                "978-013292372-9\n"
                "Carrano\n"
                "</products>\n"
                "<users>\n"
                "jdoe 100.0 0\n"
                "thatguy 5.0 0\n"
                "fhqwhgads 20.01 0\n"
                "</users>\n"
                "<reviews>\n"
                "Data Abstraction\n"
                "3 jdoe 1999-09-09 Too abstract.\n"
                "</reviews>";

        EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input, Input, Input, Input}, expectedOutput));
        EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));

}

TEST(AmazonLogin, SwitchAccountWithoutLogout)
{
        std::string const commands =
                "OR r Abstraction\n"
                "LOGIN jdoe\n"
                "LOGIN fhqwhgads\n"
                "ADD 1\n"
                "BUYCART\n"
                "QUIT database.out\n";

        std::string const expectedOutput =
                "Read 1 products\n"
                "Read 1 users\n"
                "=====================================\n"
                "Menu: \n"
                "  AND term term ...                  \n"
                "  OR term term ...                   \n"
                "  ADD username search_hit_number     \n"
                "  VIEWCART username                  \n"
                "  BUYCART username                   \n"
                "  QUIT new_db_filename               \n"
                "====================================\n"
                "\n"
                "Enter command: \n"
                "Hit   1\n"
                "Data Abstraction\n"
                "Author: Carrano ISBN: 978-013292372-9\n"
                "79.99 20 left.\n"
                "Rating: 3.00\n"
                "\n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: \n"
                "\n"
                "Enter command: ";


        std::string const inputDatabase =
                "<products>\n"
                "book\n"
                "Data Abstraction\n"
                "79.99\n"
                "20\n"
                "978-013292372-9\n"
                "Carrano\n"
                "</products>\n"
                "<users>\n"
                "jdoe 100.0 0\n"
                "thatguy 5.0 0\n"
                "fhqwhgads 100.0 0\n"
                "</users>\n"
                "<reviews>\n"
                "Data Abstraction\n"
                "3 jdoe 1999-09-09 Too abstract.\n"
                "</reviews>";

        std::string const expectedDatabase =
                "<products>\n"
                "book\n"
                "Data Abstraction\n"
                "79.99\n"
                "19\n"
                "978-013292372-9\n"
                "Carrano\n"
                "</products>\n"
                "<users>\n"
                "jdoe 100.0 0\n"
                "thatguy 5.0 0\n"
                "fhqwhgads 20.01 0\n"
                "</users>\n"
                "<reviews>\n"
                "Data Abstraction\n"
                "3 jdoe 1999-09-09 Too abstract.\n"
                "</reviews>";

        EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input, Input, Input, Input}, expectedOutput));
        EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));

}