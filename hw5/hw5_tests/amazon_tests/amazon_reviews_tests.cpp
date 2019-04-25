
#include "amazon_checker.h"

#include "Utility.h"
#include "DatabaseParser.h"
#include "ConsoleParser.h"

#include <gtest/gtest.h>



TEST(AmazonReviews, EmptyDatabase)
{
	std::string const commands =
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"</products>\n"
			"<users>\n"
			"</users>\n"
            "<reviews>\n"
			"</reviews>";


	std::string const expectedDatabase =
			"<products>\n"
			"</products>\n"
			"<users>\n"
			"</users>\n"
            "<reviews>\n"
			"</reviews>";

	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(AmazonReviews, DatabaseReadback)
{
	std::string const commands =
			"QUIT database.out\n";

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


	std::string const expectedDatabase =
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


	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(AmazonReviews, AverageRating_OneReview)
{
	std::string const commands =
			"OR r Abstraction\n"
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

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}

TEST(AmazonReviews, AverageRating_ThreeReviews)
{
	std::string const commands =
			"OR r Abstraction\n"
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
			"fjones 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 1999-09-09 Too abstract.\n"
			"Data Abstraction\n"
			"1 fjones 2028-07-03 Extremely outdated!\n"
			"Data Abstraction\n"
			"5 jdoe 2016-01-28 Not always the best reference for abstract algorithms, but quite good for realistic implementations\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}

TEST(AmazonReviews, FloatingPointAverage)
{
	std::string const commands =
			"OR r Abstraction\n"
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
			"Rating: 3.333\n"
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
			"fjones 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"2 jdoe 1999-09-09 Too abstract.\n"
			"Data Abstraction\n"
			"1 fjones 2028-07-03 Extremely outdated!\n"
			"Data Abstraction\n"
			"5 jdoe 2016-01-28 Not always the best reference for abstract algorithms, but quite good for realistic implementations\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}

TEST(AmazonReviews, NoReviews)
{
	std::string const commands =
			"OR r Headband\n"
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
			"Red Headband\n"
			"Size: Medium Brand: U-Blox\n"
			"15.50 25 left.\n"
			"Rating: 0\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"clothing\n"
			"Red Headband\n"
			"15.50\n"
			"25\n"
			"Medium\n"
			"U-Blox\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"fjones 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}


TEST(AmazonReviews, ProductNameCaseInsensitive)
{
	std::string const commands =
			"OR r SpONgeBOb\n"
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
			"SpONgeBOb MeME T-shIRt\n"
			"Size: Medium Brand: Fumei\n"
			"15.50 25 left.\n"
			"Rating: 4\n"
			"\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"clothing\n"
			"SpONgeBOb MeME T-shIRt\n"
			"15.50\n"
			"25\n"
			"Medium\n"
			"Fumei\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"fjones 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"spongebob meme t-shirt\n"
			"4 jdoe 1999-09-09 OK TBH it's kinda hilarious\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}


TEST(AmazonReviews, AvgRating_MultipleProducts)
{
	std::string const commands =
			"OR n Abstraction The Shirt\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 3 products\n"
			"Read 2 users\n"
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
			"Hit   2\n"
			"Men's Fitted Shirt\n"
			"Size: Medium Brand: J. Crew\n"
			"39.99 25 left.\n"
			"Rating: 3.5\n"
			"\n"
			"Hit   3\n"
			"The Killer Rabbit of Caerbannog: A Documentary         \n"
			"Genre: Disaster Rating: PG-13\n"
			"0.01 800000 left.\n"
			"Rating: 5.0\n"
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
			"movie\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"0.01\n"
			"800000\n"
			"Disaster\n"
			"PG-13\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"fjones 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 2000-01-01 Too abstract.\n"
			"Men's Fitted Shirt\n"
			"3 fjones 2007-09-04 Way too tight.\n"
			"Men's Fitted Shirt\n"
			"4 fjones 2016-02-20 Fits well!.\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"5 jdoe 2016-02-27 Why did the police show up at the end?\n"
			"The Killer Rabbit of Caerbannog: A Documentaryn\n"
			"5 jdoe 2016-02-27 You don't just paint EEERUGH\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}


TEST(AmazonReviews, BlankText)
{
	std::string const commands =
			"OR r Secret\n"
			"VIEWREV 1\n"
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
			"The Reviews of This Book are Secret\n"
			"Author: Bosch ISBN: 978-013292372-9\n"
			"20.00 1 left.\n"
			"Rating: 3.00\n"
			"\n"
			"\n"
			"Enter command: \n"
			"2011-01-01 3 jdoe\n"
			"\n"
			"Enter command: ";


	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"The Reviews of This Book are Secret\n"
			"20.00\n"
			"1\n"
			"978-013292372-9\n"
			"Bosch\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"The Reviews of This Book are Secret\n"
			"3 jdoe 2011-01-01\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input, ViewReviews, Input}, expectedOutput));
}


TEST(AmazonReviews, ViewOneReview)
{
	std::string const commands =
			"OR n Abstraction The Shirt\n"
            "VIEWREV 2\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 3 products\n"
			"Read 2 users\n"
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
			"Hit   2\n"
			"Men's Fitted Shirt\n"
			"Size: Medium Brand: J. Crew\n"
			"39.99 25 left.\n"
			"Rating: 3\n"
			"\n"
			"Hit   3\n"
			"The Killer Rabbit of Caerbannog: A Documentary         \n"
			"Genre: Disaster Rating: PG-13\n"
			"0.01 800000 left.\n"
			"Rating: 5.0\n"
			"\n"
			"\n"
			"Enter command: \n"
            "2007-09-04 3 fjones Way too tight.\n"
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
			"movie\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"0.01\n"
			"800000\n"
			"Disaster\n"
			"PG-13\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"fjones 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 2000-01-01 Too abstract.\n"
			"Men's Fitted Shirt\n"
			"3 fjones 2007-09-04 Way too tight.\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"5 jdoe 2016-02-27 Why did the police show up at the end?\n"
			"The Killer Rabbit of Caerbannog: A Documentaryn\n"
			"5 jdoe 2016-02-27 You don't just paint EEERUGH\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input}, expectedOutput));
}

TEST(AmazonReviews, ViewRev_SortedByYear)
{
	std::string const commands =
			"OR n Abstraction The Shirt\n"
			"VIEWREV 1\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 3 products\n"
			"Read 2 users\n"
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
			"Rating: 4.00\n"
			"\n"
			"Hit   2\n"
			"Men's Fitted Shirt\n"
			"Size: Medium Brand: J. Crew\n"
			"39.99 25 left.\n"
			"Rating: 3.5\n"
			"\n"
			"Hit   3\n"
			"The Killer Rabbit of Caerbannog: A Documentary         \n"
			"Genre: Disaster Rating: PG-13\n"
			"0.01 800000 left.\n"
			"Rating: 5.0\n"
			"\n"
			"\n"
			"Enter command: \n"
			"2019-04-08 4 talksalot I was worried that it might be a little too difficult, but honestly it isn't that bad.  I loved the parts about static programming and selfless algorithms, as well as the antidisestablishmentarian pedagogy about decentralizing compiler vendors.\n"
			"2016-04-08 4 fjones\n"
			"2000-01-02 3 jdoe Too abstract.\n"
			"1970-01-01 5 jdoe The beginning of an era\n"
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
			"movie\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"0.01\n"
			"800000\n"
			"Disaster\n"
			"PG-13\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"fjones 100.0 0\n"
			"talksalot 0.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 2000-01-02 Too abstract.\n"
			"Data Abstraction\n"
			"5 jdoe 1970-01-01 The beginning of an era\n"
			"Data Abstraction\n"
			"4 talksalot 2019-04-08 I was worried that it might be a little too difficult, but honestly it isn't that bad.  I loved the parts about static programming and selfless algorithms, as well as the antidisestablishmentarian pedagogy about decentralizing compiler vendors.\n"
			"Data Abstraction\n"
			"4 fjones 2016-04-08\n"
			"Men's Fitted Shirt\n"
			"3 fjones 2007-09-04 Way too tight.\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"5 jdoe 2016-02-27 Why did the police show up at the end?\n"
			"The Killer Rabbit of Caerbannog: A Documentaryn\n"
			"5 jdoe 2016-02-27 You don't just paint EEERUGH\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input, ViewReviews, Input}, expectedOutput));
}

TEST(AmazonReviews, ViewRev_SortedByMonth)
{
	std::string const commands =
			"OR n Abstraction The Shirt\n"
			"VIEWREV 1\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 3 products\n"
			"Read 2 users\n"
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
			"Rating: 4.00\n"
			"\n"
			"Hit   2\n"
			"Men's Fitted Shirt\n"
			"Size: Medium Brand: J. Crew\n"
			"39.99 25 left.\n"
			"Rating: 3.5\n"
			"\n"
			"Hit   3\n"
			"The Killer Rabbit of Caerbannog: A Documentary         \n"
			"Genre: Disaster Rating: PG-13\n"
			"0.01 800000 left.\n"
			"Rating: 5.0\n"
			"\n"
			"\n"
			"Enter command: \n"
			"2000-11-08 4 talksalot I was worried that it might be a little too difficult, but honestly it isn't that bad.  I loved the parts about static programming and selfless algorithms, as well as the antidisestablishmentarian pedagogy about decentralizing compiler vendors.\n"
			"2000-10-20 4 fjones\n"
			"2000-05-05 3 jdoe Too abstract.\n"
			"2000-01-31 5 jdoe The beginning of an era\n"
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
			"movie\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"0.01\n"
			"800000\n"
			"Disaster\n"
			"PG-13\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"fjones 100.0 0\n"
			"talksalot 0.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 2000-05-05 Too abstract.\n"
			"Data Abstraction\n"
			"5 jdoe 2000-01-31 The beginning of an era\n"
			"Data Abstraction\n"
			"4 talksalot 2000-11-08 I was worried that it might be a little too difficult, but honestly it isn't that bad.  I loved the parts about static programming and selfless algorithms, as well as the antidisestablishmentarian pedagogy about decentralizing compiler vendors.\n"
			"Data Abstraction\n"
			"4 fjones 2000-10-20\n"
			"Men's Fitted Shirt\n"
			"3 fjones 2007-09-04 Way too tight.\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"5 jdoe 2016-02-27 Why did the police show up at the end?\n"
			"The Killer Rabbit of Caerbannog: A Documentaryn\n"
			"5 jdoe 2016-02-27 You don't just paint EEERUGH\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input, ViewReviews, Input}, expectedOutput));
}


TEST(AmazonReviews, ViewRev_SortedByDay)
{
	std::string const commands =
			"OR n Abstraction The Shirt\n"
			"VIEWREV 1\n"
			"QUIT database.out\n";

	std::string const expectedOutput =
			"Read 3 products\n"
			"Read 2 users\n"
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
			"Rating: 4.00\n"
			"\n"
			"Hit   2\n"
			"Men's Fitted Shirt\n"
			"Size: Medium Brand: J. Crew\n"
			"39.99 25 left.\n"
			"Rating: 3.5\n"
			"\n"
			"Hit   3\n"
			"The Killer Rabbit of Caerbannog: A Documentary         \n"
			"Genre: Disaster Rating: PG-13\n"
			"0.01 800000 left.\n"
			"Rating: 5.0\n"
			"\n"
			"\n"
			"Enter command: \n"
			"2000-11-25 4 talksalot I was worried that it might be a little too difficult, but honestly it isn't that bad.  I loved the parts about static programming and selfless algorithms, as well as the antidisestablishmentarian pedagogy about decentralizing compiler vendors.\n"
			"2000-11-22 4 fjones\n"
			"2000-11-05 3 jdoe Too abstract.\n"
			"2000-11-01 5 jdoe The beginning of an era\n"
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
			"movie\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"0.01\n"
			"800000\n"
			"Disaster\n"
			"PG-13\n"
			"clothing\n"
			"Men's Fitted Shirt\n"
			"39.99\n"
			"25\n"
			"Medium\n"
			"J. Crew\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"fjones 100.0 0\n"
			"talksalot 0.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 2000-11-05 Too abstract.\n"
			"Data Abstraction\n"
			"5 jdoe 2000-11-01 The beginning of an era\n"
			"Data Abstraction\n"
			"4 talksalot 2000-11-25 I was worried that it might be a little too difficult, but honestly it isn't that bad.  I loved the parts about static programming and selfless algorithms, as well as the antidisestablishmentarian pedagogy about decentralizing compiler vendors.\n"
			"Data Abstraction\n"
			"4 fjones 2000-11-22\n"
			"Men's Fitted Shirt\n"
			"3 fjones 2007-09-04 Way too tight.\n"
			"The Killer Rabbit of Caerbannog: A Documentary\n"
			"5 jdoe 2016-02-27 Why did the police show up at the end?\n"
			"The Killer Rabbit of Caerbannog: A Documentaryn\n"
			"5 jdoe 2016-02-27 You don't just paint EEERUGH\n"
			"</reviews>";

	EXPECT_TRUE(checkConsoleOutput(commands, inputDatabase, {Menu, Input, Hit, Input, ViewReviews, Input}, expectedOutput));
}


TEST(AmazonReviews, AddReview)
{
	std::string const commands =
			"LOGIN jdoe\n"
   			"OR n Data FRC\n"
   			"ADDREV 1 5 2017-03-21 Just managed to hang in there...\n"
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
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
			"20\n"
			"978-013292372-9\n"
			"Carrano\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 1999-09-09 Too abstract.\n"
			"Data Abstraction\n"
			"5 jdoe 2017-03-21 Just managed to hang in there...\n"
			"</reviews>";


	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(AmazonReviews, AddBlankReview)
{
	std::string const commands =
			"LOGIN jdoe\n"
			"OR n Data FRC\n"
			"ADDREV 1 5 2017-03-21\n"
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
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
			"20\n"
			"978-013292372-9\n"
			"Carrano\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 1999-09-09 Too abstract.\n"
			"Data Abstraction\n"
			"5 jdoe 2017-03-21\n"
			"</reviews>";


	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(AmazonReviews, AddRevValidDates)
{
	std::string const commands =
			"LOGIN jdoe\n"
			"OR n Data FRC\n"
			"ADDREV 1 3 0001-01-01 Datum structurum!\n"
			"ADDREV 2 4 2014-12-31 Aerial Assault is kinda cool\n"
			"ADDREV 2 5 2016-02-28 Stronghold-really-awesome\n"
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
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
			"20\n"
			"978-013292372-9\n"
			"Carrano\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 1999-09-09 Too abstract.\n"
			"Data Abstraction\n"
			"3 jdoe 0001-01-01 Datum structurum!\n"
			"Data Abstraction\n"
			"4 jdoe 2014-12-31 Aerial Assault is kinda cool\n"
			"Data Abstraction\n"
			"5 jdoe 2016-02-28 Stronghold-really-awesome\n"
			"</reviews>";


	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}

TEST(AmazonReviews, AddRevInvalidDates)
{
	std::string const commands =
			"LOGIN jdoe\n"
			"OR n Data FRC\n"
			"ADDREV 1 1 0000-00-00 I think this book crashed my brain and all my memory was zeroed\n"
			"ADDREV 1 3 2017-58-21 This year has just been going on for aaaaaaages\n"
			"ADDREV 1 5 2017-02-31 Is it some kind of double leap year?\n"
			"QUIT database.out\n";

	std::string const inputDatabase =
			"<products>\n"
			"book\n"
			"Data Abstraction\n"
			"79.99\n"
			"20\n"
			"978-013292372-9\n"
			"Carrano\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
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
			"20\n"
			"978-013292372-9\n"
			"Carrano\n"
			"clothing\n"
			"FRC Fan T-Shirt\n"
			"17.00\n"
			"3\n"
			"7\n"
			"FIRST\n"
			"</products>\n"
			"<users>\n"
			"jdoe 100.0 0\n"
			"</users>\n"
			"<reviews>\n"
			"Data Abstraction\n"
			"3 jdoe 1999-09-09 Too abstract.\n" // <- none of the reviews should actually be added because of the invalid dates
			"</reviews>";


	EXPECT_TRUE(checkDatabase(commands, inputDatabase, expectedDatabase));
}


