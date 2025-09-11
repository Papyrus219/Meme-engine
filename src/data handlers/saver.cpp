#include "saver.hpp"

#include<fstream>
#include<nlohmann/json.hpp>

using namespace meme;

Saver::Saver ( std::string path_ ): path{path_}
{

}

void Saver::Save ( int& current_night, std::vector<bool>& stars, int& skipped_phone_calls )
{
    nlohmann::json save_file_json
    {
        {"night", current_night},
        {"skipped_calls", skipped_phone_calls},
        {"stars", stars}
    };

    std::ofstream{path} << save_file_json.dump(4);

}

void Saver::Load(int &current_night, std::vector<bool> &stars, int &skipped_phone_calls)
{
    std::ifstream save_file_file{path};

    nlohmann::json save_file_jason{};
    save_file_file >> save_file_jason;

    current_night = save_file_jason["night"];
    stars = save_file_jason["stars"].get<std::vector<bool>>();
    skipped_phone_calls = save_file_jason["skipped_calls"];
}
