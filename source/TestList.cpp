
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include "List.hpp"
#include "vec2.hpp"
#include "circle.hpp"
#include "color.hpp"

//Aufgabe 4.2
TEST_CASE("create a list and check if its empty", "[constructor & size]") {
    List<int> list;
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty() == true);
}

//Aufgabe 4.3
TEST_CASE ("all the push_* and pop_* methods", "[modifiers]") {
    List<int> list;
    list.push_front(12);        //12
    list.push_front(42);        //42, 12
    REQUIRE(42 == list.front());
    REQUIRE(12 == list.back());

    list.push_back(34);         //42, 12, 34
    REQUIRE(34 == list.back());

    list.pop_front();           //12, 34
    REQUIRE(list.size() == 2);
    REQUIRE(12 == list.front());

    list.push_back(12);         //12, 34, 12
    list.pop_back();            //12, 34
    REQUIRE(list.size() == 2);
    REQUIRE(34 == list.back());

    list.pop_back();            //12
    REQUIRE(list.front() == list.back());   //first_==last_ , dh korrekt deletet

    list.pop_back();
    REQUIRE(list.empty());      //list ist empty
}

//Aufgabe 4.4
TEST_CASE("should be empty after clearing", "[modifiers]") {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.clear();
    REQUIRE(list.empty());
}

//Aufgabe 4.5
TEST_CASE("Aufgabe 4.5", "[iterators]") {
    List<int> list;
    list.push_front(2);
    list.push_front(1);             //1, 2
    auto listit = list.begin();
    REQUIRE(list.begin() == listit);

    listit++;
    REQUIRE(list.begin() != listit);


    List<Circle> circle_list ;
    Vec2 center{400.f, 400.f};
    RGB c{};
    Circle c1{center, 20.f, c, 2.0f, "Kreis 1"};
    circle_list.push_back(c1);
    auto c_it = circle_list . begin ();
    std::cout << "Der Radius des 1. Circles in der Liste ist: "
                << c_it->getRadius() << std::endl ;
}

//Aufgabe 4.6
TEST_CASE("should be an empty range after default construction", "[iterators]") {
    List<int> list;
    auto a = list.begin();
    auto b = list.end();
    REQUIRE(b == a);
}

TEST_CASE("provide access to the first element with begin", "[iterators]") {
    List<int> list;
    list.push_front(420);
    REQUIRE(*list.begin() == 420);
}

//Aufgabe 4.7
TEST_CASE("Comparison operators", "[operators]") {
    List <int> list4;
    List <int> list5;
    list4.push_front(1);
    REQUIRE(list4!=list5);

    list5.push_front(1);
    REQUIRE(list4==list5);

    list5.push_front(1);
    REQUIRE(list4!=list5);
    REQUIRE(list5!=list4);

    List<int>listee;
    List<int>listea;
    REQUIRE(listea == listee);
}

//Aufgabe 4.8
TEST_CASE ("copy lists", "[constructor]"){
    List<int>list;
    list.push_front(1);
    list.push_front(2);        
    list.push_front(3);
    list.push_front(4);        //4, 3, 2, 1
    List <int> list2{list};
    REQUIRE(list2.size()==4);
    REQUIRE(list2==list);
    List <int> list3;
    List <int> list4{list3};
    REQUIRE(list4.empty());
}

//Aufgabe 4.9
TEST_CASE("insert","[iterators]")
{
    List<int>list;
    auto a = list.begin();
    list.insert(a);
    REQUIRE(list.size()==1);
    a=list.begin();
    list.insert(a);
    REQUIRE(list.size()==2);

    List<int> listee;
    auto b = listee.begin();
    listee.insert(b); // 1
    List<int> listea;
    listea.insert(b); // 1
    REQUIRE(listee == listea);
}

//Aufgabe 4.10
TEST_CASE("reverse","[rev]")
{
    List<int>list5;
    list5.push_back(1);
    list5.push_back(2);
    list5.push_back(3);
    list5.push_back(4);         //1,2,3,4
    REQUIRE(list5.front()==1);        
    list5.reverse();            //4,3,2,1
    REQUIRE(list5.front()==4);
    list5.pop_back();           //4,3,2
    REQUIRE(list5.back()==2);
    list5.pop_back();           //4,3
    REQUIRE(list5.back()==3);
    list5.pop_back();           //4
    REQUIRE(list5.back()==4);
    REQUIRE(list5.front()==4);

}

//Aufgabe 4.13
TEST_CASE("move constructor","[constructor]")
{
    List<int>list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int>list2 = std::move(list);
    REQUIRE (0==list.size());
    REQUIRE (list.empty());
    REQUIRE (4 == list2.size());
}

int main(int argc, char* argv[]){
    return Catch::Session().run(argc, argv);
}