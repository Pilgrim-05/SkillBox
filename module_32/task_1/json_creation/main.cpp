#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main()
{
    json movies =
    {
        {
            "The Imitation Game",{
                {"country", "UK, USA"},
                {"date", 2014},
                {"distributed", "The Weinstein Company"},
                {"category", "military, drama, history"},
                {"director", "Morten Tyldum"},
                {"producer", "Nora Grossman"},
                {
                    "cast", {
                        {"Benedict Cumberbatch", "Alan Turing"},
                        {"Keira Knightley", "Joan Clarke"},
                        {"Matthew Goode", "Hugh Alexander"},
                        {"Charles Dance", "Commander Denniston"},
                        {"Mark Strong", "Stewart Menzies"}
                    }
                }
            }
        }
    };

    std::ofstream file("movielist.json");

    file << movies;
    file.close();

    return 0;
}
