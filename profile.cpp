#include <iostream>
#include "profile.hpp"


Profile::Profile(std::string new_name, int new_age, std::string new_city, std::string new_country, std::string new_pronouns = "they/them") 
    : name(new_name), age(new_age), city(new_city), country(new_country), pronouns(new_pronouns) {}

void Profile::add_hobby(std::string new_hobby) {
    hobbies.push_to_back(new_hobby);
}

std::string Profile::view_profile() {
    std::string hobbies_list;

    for (int i = 0; i < hobbies.size(); i++) {
        hobbies_list += hobbies[i];
    }

    return "Name: " + name + "\nAge: " + age + "\nCity: " + city + "\nCountry: " + country + 
        "\nPronouns: " + pronouns + "\nHobbies:\n" + hobbies_list + "\n";
}