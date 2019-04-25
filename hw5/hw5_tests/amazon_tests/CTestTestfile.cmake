# CMake generated Testfile for 
# Source directory: /home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests
# Build directory: /home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AmazonReviews.EmptyDatabase "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.EmptyDatabase")
add_test(AmazonReviews.DatabaseReadback "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.DatabaseReadback")
add_test(AmazonReviews.AverageRating_OneReview "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.AverageRating_OneReview")
add_test(AmazonReviews.AverageRating_ThreeReviews "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.AverageRating_ThreeReviews")
add_test(AmazonReviews.FloatingPointAverage "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.FloatingPointAverage")
add_test(AmazonReviews.NoReviews "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.NoReviews")
add_test(AmazonReviews.ProductNameCaseInsensitive "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.ProductNameCaseInsensitive")
add_test(AmazonReviews.AvgRating_MultipleProducts "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.AvgRating_MultipleProducts")
add_test(AmazonReviews.BlankText "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.BlankText")
add_test(AmazonReviews.ViewOneReview "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.ViewOneReview")
add_test(AmazonReviews.ViewRev_SortedByYear "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.ViewRev_SortedByYear")
add_test(AmazonReviews.ViewRev_SortedByMonth "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.ViewRev_SortedByMonth")
add_test(AmazonReviews.ViewRev_SortedByDay "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.ViewRev_SortedByDay")
add_test(AmazonReviews.AddReview "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.AddReview")
add_test(AmazonReviews.AddBlankReview "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.AddBlankReview")
add_test(AmazonReviews.AddRevValidDates "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.AddRevValidDates")
add_test(AmazonReviews.AddRevInvalidDates "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviews.AddRevInvalidDates")
add_test(AmazonLogin.LoginOnly "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonLogin.LoginOnly")
add_test(AmazonLogin.LoginLogout "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonLogin.LoginLogout")
add_test(AmazonLogin.InvalidUsername "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonLogin.InvalidUsername")
add_test(AmazonLogin.BuyWithoutLogin "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonLogin.BuyWithoutLogin")
add_test(AmazonLogin.BuyItem "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonLogin.BuyItem")
add_test(AmazonLogin.SwitchAccountBuyItem "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonLogin.SwitchAccountBuyItem")
add_test(AmazonLogin.SwitchAccountWithoutLogout "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonLogin.SwitchAccountWithoutLogout")
add_test(AmazonSorting.ByRating "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonSorting.ByRating")
add_test(AmazonSorting.ByRating_NoReviews "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonSorting.ByRating_NoReviews")
add_test(AmazonSorting.ByName "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonSorting.ByName")
add_test(AmazonReviewStress.Leave10000Reviews "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviewStress.Leave10000Reviews")
add_test(AmazonReviewStress.View10000Reviews "/home/cs104/cs104hw/hw-jesalisb/hw5/hw5_tests/amazon_tests/amazon_tests" "--gtest_filter=AmazonReviewStress.View10000Reviews")
