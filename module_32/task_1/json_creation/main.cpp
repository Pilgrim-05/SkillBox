#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main()
{
    json movies =
    {
        {
            "movie",{
                {"title", "Missing"},
                {"country", "USA"},
                {"date", 2022},
                 {"genre", "action, thriller"},
                {"Scenario", "Mark Friedman"},
                {"director", "Brian Goodman"},
                {"producer", "Brian Pitt"},
                {
                    "cast", {"Gerard Butler", "Jaimie Alexander", "Dani Deetté", "Robert Walker Branch", "Jordan Salloum"}
                }
            }
        }

    };

    std::ofstream file("movielist.json");

    file << movies;
    file.close();

    return 0;
}
