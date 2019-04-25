//
// Tests for Comparators problem in CS104 HW5
//

#include <user_code_runner.h>

#include <gtest/gtest.h>

#include <kwsys/SystemTools.hxx>

#include <vector>
#include <string>
#include <fstream>

class ComparatorsTest : public testing::Test
{
protected:
	static std::vector<std::vector<std::string>> output;

public:
	// do the bulk of the work here of running the program and parsing the output
	// that way we can have a seperate test case for each line of output
	// without actually running the program 4 times.
	static void SetUpTestCase()
	{
		std::string testFolder = TEST_BINARY_DIR "/comparators_tests/testFiles/";
		std::string outputFile = testFolder + "output.txt";
		kwsys::SystemTools::MakeDirectory(testFolder);

		UserCodeRunner codeRunner(testFolder, COMPARATORS_EXECUTABLE, {outputFile}, true);

		if(!codeRunner.execute())
		{
			// if the code didn't run, just return, and the other tests will fail
		}

		std::ifstream resultStream(outputFile);
		std::string line;

		while(std::getline(resultStream, line))
		{
			if(resultStream.eof() && line.empty())
			{
				break;
			}

			std::vector<std::string> terms;
			kwsys::SystemTools::Split(line, terms, ':');
			output.push_back(terms);
		}
	}

	static void TearDownTestCase()
	{
		// do nothing
	}
};

std::vector<std::vector<std::string>> ComparatorsTest::output{};

TEST_F(ComparatorsTest, StandardLexicographic)
{
	ASSERT_GE(output.size(), 1);

	ASSERT_EQ((std::vector<std::string>{"  efg" , "Acc", "Zxy", "aBc", "abc", "zyx"}), output[0]);
}

TEST_F(ComparatorsTest, DescendingLexicographic)
{
	ASSERT_GE(output.size(), 2);

	ASSERT_EQ((std::vector<std::string>{ "zyx",  "abc", "aBc", "Zxy",  "Acc", "  efg"}), output[1]);
}

TEST_F(ComparatorsTest, CaseInsensitiveLexicographic)
{
	ASSERT_GE(output.size(), 3);

	// this is case insensitive so indexes 0 and 1 could legally be flipped either way
	EXPECT_EQ("  efg", output[2][0]);
	EXPECT_TRUE(output[2][1] == "abc" || output[2][1] == "aBc");
	EXPECT_TRUE(output[2][2] == "abc" || output[2][2] == "aBc");
	EXPECT_EQ("Acc", output[2][3]);
	EXPECT_EQ("Zxy", output[2][4]);
	EXPECT_EQ("zyx", output[2][5]);
}

TEST_F(ComparatorsTest, IgnoreLeadingWhitespace)
{
	ASSERT_GE(output.size(), 4);

	ASSERT_EQ((std::vector<std::string>{"Acc", "Zxy", "aBc", "abc", "  efg", "zyx"}), output[3]);
}