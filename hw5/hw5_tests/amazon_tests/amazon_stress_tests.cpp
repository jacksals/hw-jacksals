//
// Created by cs104 on 3/15/19.
//

#include "amazon_checker.h"

#include "Utility.h"
#include "DatabaseParser.h"
#include "ConsoleParser.h"

#include <random_generator.h>

#include <gtest/gtest.h>

#include <iomanip>


TEST(AmazonReviewStress, Leave10000Reviews)
{
    const size_t numProducts = 10000;

    std::string fixedDatabasePart = "<products>\n"
                                    "book\n"
                                    "Data Abstraction & Problem Solving with C++\n"
                                    "79.99\n"
                                    "20\n"
                                    "978-013292372-9\n"
                                    "Carrano and Henry\n"
                                    "book\n"
                                    "Great Men and Women of Troy\n"
                                    "19.50\n"
                                    "5\n"
                                    "978-000000000-1\n"
                                    "Tommy Trojan\n"
                                    "clothing\n"
                                    "Men's Fitted Shirt\n"
                                    "39.99\n"
                                    "25\n"
                                    "Medium\n"
                                    "J. Crew\n"
                                    "movie\n"
                                    "Hidden Figures DVD\n"
                                    "17.99\n"
                                    "5\n"
                                    "Drama\n"
                                    "PG\n"
                                    "movie\n"
                                    "Great Heights\n"
                                    "22.49\n"
                                    "5\n"
                                    "and\n"
                                    "PG-13\n"
                                    "</products>\n"
                                    "<users>\n"
                                    "rafsilva 100.00 0\n"
                                    "redekopp 50.00 1\n"
                                    "saty 120.00 1\n"
                                    "</users>\n";

    std::string inputDatabase = fixedDatabasePart + "<reviews>\n</reviews>";

    // build command set
    std::stringstream commands;
    commands << "OR n Heights" << std::endl;
    commands << "LOGIN redekopp" << std::endl;

    // build stress test dataset
    std::stringstream outputDatabase;

    outputDatabase << fixedDatabasePart << "<reviews>" << std::endl;

    std::vector<int> ratings = makeRandomNumberVector(numProducts, 1, 5, 48390, true);

    for(int reviewNum = numProducts - 1; reviewNum >= 0; --reviewNum)
    {
        // make a monotonically decreasing date by splitting the number into days, months, and years
        int reviewNumLeft = reviewNum;
        int days = reviewNumLeft % 27 + 1;
        reviewNumLeft /= 27;
        int months = reviewNumLeft % 12 + 1;
        reviewNumLeft /= 12;
        int years = reviewNumLeft + 1;

        // format as a date -- this is actually very difficult to do with C++ formatting, so we use C instead
        // note to self: learn to use fmtlib so I can actually do this kind of formatting in a sane way
        char dateString[11];
        snprintf(dateString, 11, "%04d-%02d-%02d", years, months, days);

        std::string reviewText = (ratings[reviewNum] >= 3 ? std::string("Great!") : std::string("Meh.")) + std::string(" - Reevaluation ") + std::to_string(reviewNum);

        // command to add the review
        commands << "ADDREV 1 " << ratings[reviewNum] << " " << dateString << " " << reviewText << std::endl;

        // create output database entry
        outputDatabase << "Great Heights" << std::endl;
        outputDatabase << ratings[reviewNum] << " " << "mredekopp" << " " << dateString << " " << reviewText << std::endl;
    }

    outputDatabase << "</reviews>";

    commands <<
             "QUIT database.out\n";




    EXPECT_TRUE(checkDatabase(commands.str(), inputDatabase, outputDatabase.str(), false));
}

TEST(AmazonReviewStress, View10000Reviews)
{
    const size_t numProducts = 10000;
    const std::string author = "redekopp";

    // generate set of random ratings and compute its average
    std::vector<int> ratings = makeRandomNumberVector(numProducts, 1, 5, 97676, true);

    double avgRating = 0;
    for(int rating : ratings)
    {
        avgRating += rating;
    }
    avgRating /= ratings.size();


    std::string fixedDatabasePart = "<products>\n"
                                    "book\n"
                                    "Data Abstraction & Problem Solving with C++\n"
                                    "79.99\n"
                                    "20\n"
                                    "978-013292372-9\n"
                                    "Carrano and Henry\n"
                                    "book\n"
                                    "Great Men and Women of Troy\n"
                                    "19.50\n"
                                    "5\n"
                                    "978-000000000-1\n"
                                    "Tommy Trojan\n"
                                    "clothing\n"
                                    "Men's Fitted Shirt\n"
                                    "39.99\n"
                                    "25\n"
                                    "Medium\n"
                                    "J. Crew\n"
                                    "movie\n"
                                    "Hidden Figures DVD\n"
                                    "17.99\n"
                                    "5\n"
                                    "Drama\n"
                                    "PG\n"
                                    "movie\n"
                                    "Great Heights\n"
                                    "22.49\n"
                                    "5\n"
                                    "and\n"
                                    "PG-13\n"
                                    "</products>\n"
                                    "<users>\n"
                                    "rafsilva 100.00 0\n"
                                    "redekopp 50.00 1\n"
                                    "saty 120.00 1\n"
                                    "</users>\n"
                                    "<reviews>\n";

    std::string const commands =
            "AND n Great Heights\n"
            "VIEWREV 1\n"
            "QUIT database.out\n";


    // build stress test dataset
    std::stringstream inputDatabase;
    std::stringstream expectedOutput;

    inputDatabase << fixedDatabasePart;
    expectedOutput << "Read " << numProducts << " products\n"
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
                                                "Great Heights\n"
                                                "Genre: and Rating: PG-13\n"
                                                "22.49 5 left.\n"
                                                "Rating: " << avgRating << "\n"
                                                "\n"
                                                "Enter command: \n";


    for(int reviewNum = numProducts - 1; reviewNum >= 0; --reviewNum)
    {
        // make a monotonically decreasing date by splitting the number into days, months, and years
        int reviewNumLeft = reviewNum;
        int days = reviewNumLeft % 27 + 1;
        reviewNumLeft /= 27;
        int months = reviewNumLeft % 12 + 1;
        reviewNumLeft /= 12;
        int years = reviewNumLeft + 1;

        // format as a date -- this is actually very difficult to do with C++ formatting, so we use C instead
        // note to self: learn to use fmtlib so I can actually do this kind of formatting in a sane way
        char dateString[11];
        snprintf(dateString, 11, "%04d-%02d-%02d", years, months, days);

        std::string reviewText = (ratings[reviewNum] >= 3 ? std::string("Great!") : std::string("Meh.")) + std::string(" - From Spambot no. ") + std::to_string(reviewNum);

        // create database entry
        inputDatabase << "Great Heights" << std::endl;
        inputDatabase << ratings[reviewNum] << " " << author << " " << dateString << " " << reviewText << std::endl;

        // create console entry
        expectedOutput << dateString << " " << ratings[reviewNum] << " " << author << " " << reviewText << std::endl;
    }

    // footer on output and database
    inputDatabase << "</reviews>";

    expectedOutput << std::endl;
    expectedOutput << "Enter command: " << std::endl;

    EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase.str(),
                                   {
                                           Menu,
                                           Input, Hit, // Search and parse hit.
                                           Input, ViewReviews, // View reviews
                                           Input
                                   }, expectedOutput.str(), false));
}

