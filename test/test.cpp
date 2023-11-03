#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "sort.hpp"

void sortArray(int arr[], int n){
  Sort sort;
  sort.bubble(arr, n);
}

TEST_CASE("Sorting an array of integers using sorting algorthms", "[sort]") {
  SECTION("Sorting an already sorted array") {
    int arr[] = {1, 2, 3, 4, 5};
    sortArray(arr, 5);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
    REQUIRE(arr[2] == 3);
    REQUIRE(arr[3] == 4);
    REQUIRE(arr[4] == 5);
  }

  SECTION("Sorting a reverse-sorted array") {
    int arr[] = {5, 4, 3, 2, 1};
    sortArray(arr, 5);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
    REQUIRE(arr[2] == 3);
    REQUIRE(arr[3] == 4);
    REQUIRE(arr[4] == 5);
  }

  SECTION("Sorting an unsorted array") {
    int arr[] = {1, 4, 3, 5, 2};
    sortArray(arr, 5);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
    REQUIRE(arr[2] == 3);
    REQUIRE(arr[3] == 4);
    REQUIRE(arr[4] == 5);
  }

  SECTION("Sorting an array with duplicate values") {
    int arr[] = {5, 1, 2, 2, 3, 1, 4};
    sortArray(arr, 7);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 1);
    REQUIRE(arr[2] == 2);
    REQUIRE(arr[3] == 2);
    REQUIRE(arr[4] == 3);
    REQUIRE(arr[5] == 4);
    REQUIRE(arr[6] == 5);
  }
}
