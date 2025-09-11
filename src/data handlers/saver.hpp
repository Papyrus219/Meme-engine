#ifndef MEME_SAVER_H
#define MEME_SAVER_H

#include<string>
#include<vector>

namespace meme {

/**
 * @todo write docs
 */
struct Saver
{
    Saver(std::string path_);

    void Save(int &current_night, std::vector<bool> &stars, int &skipped_phone_calls);
    void Load(int &current_night, std::vector<bool> &stars, int &skipped_phone_calls);

    std::string path{};
};

}

#endif // MEME_SAVER_H
