#include <vector>

class Profile {
    std::string name;
    int age;
    std::string city, country;
    std::string pronouns;
    std::vector<std::string> hobbies;

    public:
        Profile(std::string name, int age, std::string city, std::string country, std::string pronouns = "they/them");
};
