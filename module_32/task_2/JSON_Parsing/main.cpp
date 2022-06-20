#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void jsonCreater();

int main()
{
    jsonCreater();

    std::ifstream iFile("movielist.json");
    json movies;
    iFile >> movies;
    iFile.close();

    std::cout << "Enter actor name: ";
    std::string actor;
    getline(std::cin, actor);

    for(auto it = movies.begin(); it != movies.end(); ++it)
    {
        if(it.value()["cast"][actor] != nullptr)
            std::cout << "Starred in a movie - " << it.key() << ": Cast - " << it.value()["cast"][actor] << std::endl;
    }

    return 0;
}

void jsonCreater()
{
    json movies =
    {
        {
            "The Imitation Game",{
                {"country", "UK, USA"},
                {"date", 2014},
                {"distributed", "Black Bear Pictures"},
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
        },

        {
            "A Beautiful Mind",{
                {"country", "USA"},
                {"date", 2001},
                {"distributed", "Universal Pictures"},
                {"category", "drama"},
                {"director", "Ron Howard"},
                {"producer", "Brian Grazer"},
                {
                    "cast", {
                        {"Russell Crowe", "John Nash"},
                        {"Ed Harris", "William Parcher"},
                        {"Jennifer Connelly", "Alicia Nash"},
                        {"Paul Bettany", "Charles Herman"},
                        {"Christopher Plummer", "Dr. Rosen"}
                    }
                }
            }
        },

        {
            "The Theory of Everything",{
                {"country", "UK, Japan, USA"},
                {"date", 2014},
                {"distributed", "Working Title Films"},
                {"category", "Biographical"},
                {"director", "James Marsh"},
                {"producer", "Tim Bevan"},
                {
                    "cast", {
                        {"Eddie Redmayne", "Stephen Hawking"},
                        {"Felicity Jones", "Jane Hawking"},
                        {"Charlie Cox", "Jonathan Jones"},
                        {"David Thewlis", "Dennis Sciama"}
                    }
                }
            }
        },

        {
            "The Man Who Knew Infinity",{
                {"country", "UK"},
                {"date", 2016},
                {"distributed", "Warner Bros. Pictures"},
                {"category", "drama"},
                {"director", "Matthew Brown"},
                {"producer", "Edward R. Pressman"},
                {
                    "cast", {
                        {"Dev Patel", "Srinivasa Ramanujan"},
                        {"Jeremy Irons", "G. H. Hardy"},
                        {"Devika Bhise", "Janaki"},
                        {"Toby Jones", "John Edensor Littlewood"},
                        {"Stephen Fry", "Sir Francis Spring"}
                    }
                }
            }
        },

        {
            "Sherlock",{
                {"country", "UK"},
                {"date", 2017},
                {"distributed", "Netflix"},
                {"category", "Drama, Crime, Mystery, Comedy"},
                {"director", "Euros Lyn"},
                {"producer", "Stephen Moffat"},
                {
                    "cast", {
                        {"Benedict Cumberbatch", "Sherlock Holmes"},
                        {"Martin Freeman", "Dr. John Watson"},
                        {"Una Stubbs", "Mrs Hudson"},
                        {"Andrew Scott", "Professor Moriarty"}
                    }
                }
            }
        },

        {
            "The Social Network",{
                {"country", "USA"},
                {"date", 2010},
                {"distributed", "Columbia Pictures"},
                {"category", "Drama, Biographical"},
                {"director", "David Fincher"},
                {"producer", "Scott Rudin"},
                {
                    "cast", {
                        {"Jesse Eisenberg", "Mark Zuckerberg"},
                        {"Andrew Garfield", "Eduardo Saverin"},
                        {"Justin Timberlake", "Sean Parker"},
                        {"Max Minghella", "Divya Narendra"},
                        {"Brenda Song", "Christy Lee"}
                    }
                }
            }
        }

    };
    std::ofstream file("movielist.json");

    file << movies;
    file.close();
}
